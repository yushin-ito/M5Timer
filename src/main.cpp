#include <M5Unified.h>
#include <M5Timer.h>

M5Timer tm;

void setup() {
    auto cfg = M5.config();
    M5.begin(cfg);

    if (M5.Display.width() < M5.Display.height()) {
        M5.Display.setRotation(1);
    }

    tm.init(0, 0);
}

void loop() {
    M5.update();

    if (M5.BtnA.wasPressed()) {
        if (tm.isEnabled()) {
            tm.stop();
        }
        else {
            tm.start();
        }
    }


    if (M5.BtnB.wasPressed()) {
        tm.reset();
    }

    delay(100);
}