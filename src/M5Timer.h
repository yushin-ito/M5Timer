#include <M5Unified.h>

class M5Timer {
private:
  M5Canvas* canvas;
  bool _drawing;
  bool _changed;
  int32_t _x;
  int32_t _y;
  float _text_size;
  uint32_t _text_color;
  uint32_t _bg_color;

public:
  M5Timer();
  void setPosition(int32_t x, int32_t y);
  void setTextSize(float size);
  void setTextColor(uint32_t color);
  void setBgColor(uint32_t color);
  void init(int32_t x, int32_t y);
  void start();
  void stop();
  void reset();
  bool isDrawing();
  bool isChanged();
  void setChanged(bool changed);
  void drawTimer();
};


class Context {
private:
  M5Timer* _tm;

public:
  Context(M5Timer* tm);
  M5Timer* getTimer();
};
