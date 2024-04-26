# Otto DIY Robot Arduino Libraries

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
![version](https://img.shields.io/badge/version-13.0-blue)

This repository have all the main [Otto DIY robot](https://www.ottodiy.com/) libraries for Arduino compatible boards

:star: Star us on GitHub, it helps!

## Installation:

1. [Download the .zip Otto libraries here](https://github.com/OttoDIY/OttoDIYLib/archive/master.zip)
2. Open Arduino IDE and navigate to Sketch > Include Library > Add .ZIP Library. At the top of the drop down list, select the option to "Add .ZIP Library".
3. Navigate to the .zip file's location, that you just downloaded and open it.
4. In the main window you will see in the bottom back area a message that it has been installed.
5. To verify they are properly installed, go to Sketch > Include Library menu. You should now see the library at the bottom of the drop-down menu.

That means it is ready to use Otto example codes! you can find them in File > Examples > OttoDIYLib
[for more details or other ways to install libraries visit this link](https://www.arduino.cc/en/Guide/Libraries)

You can also find this library in the Arduino Manager as `Otto DIYLib` for quick installation, (do not use other non compatible libraries).

## Compatible Hardware

- Arduino Nano Atmega168


## Structure

Base set of libraries for any biped robot that uses 4 motors in the legs as Otto.

* `Otto.h` and `Otto.cpp` contains all the main functions
* `Otto_gestures.h` contains all the gestures functions
* `Oscillator.h` is the main algorithm for the servos "smooth" movement
* `SerialCommand.c` is for Bluetooth communication vis Software serial

### Adding library

```cpp
#include <Otto.h>
Otto Otto;
```

### Pins declaration

These are the default signal connections for the servos and buzzer for AVR Arduino boards in the examples, you can alternatively connect them in different pins if you also change the pin number.

```cpp
#define LeftLeg 2 // left leg pin
#define RightLeg 3 // right leg pin
#define LeftFoot 4 // left foot pin
#define RightFoot 5 // right foot pin
#define Buzzer 13 //buzzer pin
```

### Initialization

When starting the program, the 'init' function must be called with the use of servo motor calibration as a parameter. <br/>
It is best to place the servo motors in their home position after initialization with 'home' function.

```cpp
void setup() {
   Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
   Otto.home();
}
```
The `home()` function makes the servos move to the center position, Otto standing in the neutral position.

## Predetermined Functions:
Many preconfigured movements are available in the library:

### Movements:
These are actions that involve the use of the 4 servo motors with the oscillation library combined in synergy and with smooth movements. You can change the values inside the pratensis `()` to alter the speed, direction, and size of the movements.

#### Walk function

```cpp
Otto.walk(steps, time, dir);
```
- `steps` are just how many times you want to repeat that movement without the need of further coding or adding additional rows.
- `time` (noted as `T` below) translated in milliseconds is the duration of the movement. For a higher time value is slower the movement, try values between 500 to 3000.
- `dir` is the direction: `1` for forward or `-1` backward

Example:
```cpp
Otto.walk(2, 1000, 1);
```
In this example `2` is the number of steps, `1000` is "TIME" in milliseconds and it will walk forward.

For example changing T value: Slow=2000 Normal=1000 Fast= 500

```cpp
Otto.turn(steps, T, dir);
```
(# of steps, T, to the left or -1 to the right)

```cpp
Otto.bend (steps, T, dir);
```

(# of steps, T, 1 bends to the left or -1 to the right)

```cpp
Otto.shakeLeg (steps, T, dir);
```
(# of steps, T, 1 bends to the left or -1 to the right)

```cpp
Otto.jump(steps, T);
```
(# of steps up, T) this one does not have a dir parameter
Otto doesn't really jump ;P

### Dances:

Similar to movements but more fun! you can adjust a new parameter `h` "height or size of the movements" to make the dance more interesting.

```cpp
Otto.moonwalker(steps, T, h, dir);
```
(# of steps, T, h, 1 to the left or -1 to the right)

`h`: you can try change between 15 and 40


Example:
```cpp
Otto.moonwalker(3, 1000, 25,1);
```

```cpp
Otto.crusaito(steps, T, h, dir);
```
(# of steps, T, h, 1 to the left or -1 to the right)

`h`: you can try change between 20 to 50

```cpp
Otto.flapping(steps, T, h, dir);
```
(# of steps, T, h, 1 to the front or -1 to the back)

`h`: you can try change between 10 to 30

```cpp
Otto.swing(steps, T, h);
```
`h`: you can try change between 0 to 50

```cpp
Otto.tiptoeSwing(steps, T, h);
```
`h`: you can try change between 0 to 50

```cpp
Otto.jitter(steps, T, h);
```
`h`: you can try change between 5 to 25

```cpp
Otto.updown(steps, T, h);  
```
`h`: you can try change between 0 to 90

```cpp
Otto.ascendingTurn(steps, T, h);
```
`h`: you can try change between 5 to 15


### Gestures:
Finally, our favorite, This is a combination of the 2 previous functions we learnt sing + walk
Their goal is to express emotions by combining sounds with movements at the same time and if you have the LED matrix you can show them in the robot mouth!

```cpp
Otto.playGesture(gesture);
```
- `Otto.playGesture(OttoHappy);`
- `Otto.playGesture(OttoSuperHappy);`
- `Otto.playGesture(OttoSad);`
- `Otto.playGesture(OttoVictory);`
- `Otto.playGesture(OttoAngry);`
- `Otto.playGesture(OttoSleeping);`
- `Otto.playGesture(OttoFretful);`
- `Otto.playGesture(OttoLove);`
- `Otto.playGesture(OttoConfused);`
- `Otto.playGesture(OttoFart);`
- `Otto.playGesture(OttoWave);`
- `Otto.playGesture(OttoMagic);`
- `Otto.playGesture(OttoFail);`

As you see it’s very simple, but what it does is quite advanced.

## License

The OttoDIYLib is licensed under the terms of the GPL Open Source
license and is available for free.

Welcome to the Otto DIY community

<a href="https://discord.gg/CZZytnw"><img src="https://images.squarespace-cdn.com/content/v1/5cd3e3917046805e4d6700e3/1560193788834-KYURUXVSZAIE4XX1ZB2F/ke17ZwdGBToddI8pDm48kK6MRMHcYvpidTm-7i2qDf_lfiSMXz2YNBs8ylwAJx2qLijIv1YpVq4N1RMuCCrb3iJz4vYg48fcPCuGX417dnbl3kVMtgxDPVlhqW83Mmu6GipAUbdvsXjVksOX7D692AoyyEsAbPHhHcQMU6bWQFI/join_discord_button_small.png" width="25%"></a>

Big thanks to all our contributors
- @JavierIH
- @Obijuan
- @jarsoftelectrical
- @stembotvn
- @sfranzyshen
- @tehniq3
- @logix5
- @DiegoSSJ
- @loreman
- @justinotherguy
- @bhm93
- @wendtbw
- @agomezgar
- @BodoMinea
- @chico
- @PinkDev1
- @MXZZ
- @Pawka
- @per1234
- @FedericoBusero
- @hulkco
- @mishafarms
- @nisha-appanah
- @pabloevaristo
- @ProgrammerBruce
- @Nca78
- @dleval
- @coliss86
- @namepatrik

## How to Contribute:
Contributing to this software is warmly welcomed. There are 3 ways you can contribute to this project:
1. Test and if find a problem then post an issue.
2. Helps us solve the issues or other bugs.
3. Improve the code.
You can do this [basically by forking](https://help.github.com/en/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/en/articles/about-pull-requests).Please add a change log and your contact into file header.

Thanks for your contribution in advance.
