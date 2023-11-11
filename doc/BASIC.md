# Basics

- [Basics](#basics)
  - [Instance Basics](#instance-basics)
    - [Create a instance](#create-a-instance)
  - [Functions Basic](#functions-basic)
    - [tm.setPosition(x, y) => void](#tmsetpositionx-y--void)
    - [tm.setTextSize(size) => void](#tmsettextsizesize--void)
    - [tm.setTextColor(color) => void](#tmsettextcolorcolor--void)
    - [tm.setBgColor(color) => void](#tmsetbgcolorcolor--void)
    - [tm.init() => void](#tminit--void)
    - [tm.show() => void](#tmshow--void)
    - [tm.hide() => void](#tmhide--void)
    - [tm.start() => void](#tmstart--void)
    - [tm.stop() => void](#tmstop--void)
    - [tm.reset() => void](#tmreset--void)
    - [tm.isEnabled() => bool](#tmisenabled--bool)
    - [tm.isDrawing() => bool](#tmisdrawing--bool)
    - [tm.isChanged() => bool](#tmischanged--bool)
    - [tm.drawTimer() => void](#tmdrawtimer--void)

## Instance Basics

### Create a instance

Include the `M5Timer.h` and `M5Unified`

```c
#include <M5Unified.h>
#include <M5Timer.h>
```

Then Instanciate

```c
M5Timer tm;
```

Your instance is now ready.

## Functions Basic

Call the fuctions using the created instance.

### tm.setPosition(x, y) => void

Set position of timer box.

Kind: instance method of `M5Timer`

| Param |  Type   |
| :---: | :-----: |
|   x   | int32_t |
|   y   | int32_t |

### tm.setTextSize(size) => void

Set text size.

Kind: instance method of `M5Timer`

| Param | Type  |
| :---: | :---: |
| size  | float |

### tm.setTextColor(color) => void

Set text color.

Kind: instance method of `M5Timer`

| Param |   Type   |
| :---: | :------: |
| color | uint32_t |

### tm.setBgColor(color) => void

Set bg color of timer box.

Kind: instance method of `M5Timer`

| Param |   Type   |
| :---: | :------: |
| color | uint32_t |

### tm.init() => void

Initialize timer with position.

| Param |  Type   |
| :---: | :-----: |
|   x   | int32_t |
|   y   | int32_t |

Kind: instance method of `M5Timer`

### tm.show() => void

Show timer.

Kind: instance method of `M5Timer`

### tm.hide() => void

Hide timer.

Kind: instance method of `M5Timer`

### tm.start() => void

Start timer.

Kind: instance method of `M5Timer`

### tm.stop() => void

Stop timer.

Kind: instance method of `M5Timer`

### tm.reset() => void

Reset timer.

Kind: instance method of `M5Timer`

### tm.isEnabled() => bool

Get if the timer is enabled.

Kind: instance method of `M5Timer`

### tm.isDrawing() => bool

Get if the timer is drawing.

Kind: instance method of `M5Timer`

### tm.isChanged() => bool

Get if the timer style is changed.

Kind: instance method of `M5Timer`

### tm.drawTimer() => void

Display timer.

Kind: instance method of `M5Timer`
