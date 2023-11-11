#include "M5Timer.h"

struct  timer_info_t {
    uint8_t sec;
    uint8_t min;
    uint8_t hour;
    uint8_t day;
};

timer_info_t timer_info = { 0, 0, 0 };

hw_timer_t* timer = NULL;

TaskHandle_t drawTaskHandle;

Context::Context(M5Timer* tm) { _tm = tm; }

M5Timer* Context::getTimer() { return _tm; }

void IRAM_ATTR onTimer() {
    timer_info.sec++;
    if (timer_info.sec == 60) {
        timer_info.sec = 0;
        timer_info.min++;
    }
    if (timer_info.min == 60) {
        timer_info.min = 0;
        timer_info.hour++;
    }
    if (timer_info.hour == 24) {
        timer_info.hour = 0;
        timer_info.day++;
    }
}

void drawLoop(void* args) {
    Context* ctx = reinterpret_cast<Context*>(args);
    M5Timer* tm = ctx->getTimer();

    while (tm->isDrawing() || tm->isChanged()) {
        if (tm->isDrawing()) {
            tm->drawTimer();
        }
        if (tm->isChanged()) {
            M5.Display.clear();
            tm->setChanged(false);
        }
        vTaskDelay(1);
    }
    vTaskDelete(NULL);
}

M5Timer::M5Timer() {
    canvas = new M5Canvas(&M5.Lcd);
    _drawing = false;
    _changed = false;
    _x = 0;
    _y = 0;
    _text_size = 1.0;
    _text_color = canvas->color888(255, 255, 255);
    _bg_color = canvas->color888(0, 0, 0);
}

void M5Timer::setPosition(int32_t x, int32_t y) {
    _x = x;
    _y = y;
    _changed = true;
}

void M5Timer::setTextSize(float size) {
    _text_size = size;
    _changed = true;
}

void M5Timer::setTextColor(uint32_t color) {
    _text_color = color;
    _changed = true;
}

void M5Timer::setBgColor(uint32_t color) {
    _bg_color = color;
    _changed = true;
}

void M5Timer::init(int32_t x, int32_t y) {
    _x = x;
    _y = y;

    timer = timerBegin(0, getApbFrequency() / 1000000, true);
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, 1000000, true);
}

void M5Timer::show() {
    Context* ctx = new Context(this);

    if (_drawing) return;
    _drawing = true;

    xTaskCreateUniversal(drawLoop,
        "drawLoop",
        2048,
        ctx,
        1,
        &drawTaskHandle,
        APP_CPU_NUM);
}

void M5Timer::hide() {
    _drawing = false;
    _changed = true;
}

void M5Timer::start() {
    timerAlarmEnable(timer);
}

void M5Timer::stop() {
    timerAlarmDisable(timer);
    _drawing = false;
}

void M5Timer::reset() {
    timer_info.sec = 0;
    timer_info.min = 0;
    timer_info.hour = 0;
    timer_info.day = 0;
}


bool M5Timer::isDrawing() {
    return _drawing;
}

bool M5Timer::isChanged() {
    return _changed;
}

void M5Timer::setChanged(bool changed) {
    _changed = changed;
}

void M5Timer::drawTimer() {
    int32_t _sprite_width = M5.Display.width();
    int32_t _sprite_height = M5.Display.fontHeight(&Font7) * _text_size + M5.Display.fontHeight(&Font2) * _text_size * 0.3;

    canvas->createSprite(_sprite_width, _sprite_height);

    canvas->setTextWrap(false);
    canvas->setCursor(0, 0);
    canvas->setTextColor(_text_color);

    canvas->setFont(&Font7);
    canvas->setTextSize(_text_size);
    canvas->printf("%02d:%02d", timer_info.hour, timer_info.min);

    canvas->setFont(&Font7);
    canvas->setTextSize(_text_size * 0.3);
    canvas->printf(" : %02d\n", timer_info.sec);

    canvas->pushSprite(&M5.Display, _x, _y);

    canvas->deleteSprite();
}