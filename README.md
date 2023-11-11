<h1>M5Timer</h1>

<div align="left">
  <img src="https://img.shields.io/badge/version-0.0.1-red.svg">
  <a href="https://registry.platformio.org/libraries/yushin-ito/M5Timer"><img src="https://badges.registry.platformio.org/packages/yushin-ito/library/M5Timer.svg" alt="PlatformIO Registry" /></a>
  <img src="https://img.shields.io/github/actions/workflow/status/yushin-ito/M5Timer/build.yml">
  <img src="https://img.shields.io/github/stars/yushin-ito/M5Timer?color=yellow">
  <img src="https://img.shields.io/github/commit-activity/t/yushin-ito/M5Timer">
  <img src="https://img.shields.io/badge/license-MIT-green">
</div>

<br>

<h2>📝 Overview</h2>
An M5Stack library for displaying a timer.

<br>
<br>

<h2>🚀 Features</h2>
<ul>
  <li>Display a timer</li>
  <li>Customize size and color</li>
</ul>
<br>
<div align="center">
  <img src="https://github.com/yushin-ito/M5Timer/assets/75526539/26cb10b4-8c47-4716-8f28-013da7c379f8" width="80%"/>
</div>

<br>

<h2>📦 Installation</h2>
<a href="https://open.vscode.dev/yushin-ito/M5Timer">
  <img src="https://img.shields.io/static/v1?logo=visualstudiocode&label=&message=Open%20in%20Visual%20Studio%20Code&labelColor=2c2c32&color=007acc&logoColor=007acc">
</a>
<br>
<br>
<ol>
  <li>Initialize your Platform IO project</li>

```
platformio init -d . -b m5stack-core-esp32
```

  <li>Install the library and its dependency</li>

```
platformio lib install M5Timer
platformio lib install M5Unified
```

</ol>

<h2>🔧 Usage</h2>

> **Warning**
> This library has been tested only with M5Stack and M5StickC-PLUS.

<br>

```c
#include <M5Unified.h>
#include <M5Timer.h>

M5Timer tm;

void setup() {
    auto cfg = M5.config();
    M5.begin(cfg);

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
```

<p>You can also read the <a href="https://github.com/yushin-ito/M5Timer/blob/main/doc/BASIC.md">module doc</a> for a list of supported calls.</p>

<br>

<h2>👀 Author</h2>
<a href="https://github.com/yushin-ito">Yushin Ito</a>

<br>
<br>

<h2>📜 License</h2>
<a href="https://github.com/yushin-ito/M5Timer/blob/main/LICENSE">MIT License</a>
