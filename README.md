# Keypad-Console
The source code to my projectOn hackaday : https://hackaday.io/project/171302-keypad-console

Future plans are to make a game engine for this device to use. The device has an i2c output to hook up more devices.

Problems currently faced by the device is the 1.8" tft display which has an area of noise. The lower half does not update correct. 

# Game Graphics
Game Graphics is a library for Keypad Console in hopes to make the graphics side of the game easier to use.

## Features
- [ ] Sprites
- [ ] Display
- [X] Color Referance

## How to use
To use I would reccomend the latest release of this library and set up your project like normal using the master of TFT_ILI9163C by sumotoy.

```Cpp
#include <Adafruit_GFX.h>

#include <SPI.h>

#include <TFT_ILI9163C.h>
#include <Display.h>
#include <Colors.h>
#include <Sprite.h>

#define __DC 9
#define __CS 10

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);
Display display = Display(&tft);

int x_0 = 128/2, x = 0, oldX= 0, y_0 = 128/2, y = 0, oldY = 0, R = 30;
double t = 0;


bool dirX = true, dirY = true;

void setup(){
    display.begin();
    display.getDisplay()->clearScreen();
}

void Display::draw(){
    getDisplay()->fillRect(oldX, oldY, 10, 10, BLACK);
    getDisplay()->fillRect(x, y, 10, 10, RED);
    oldX = x; oldY = y;
}

void gameUpdate(){
    x = R*cos(t) + x_0;
    y = R*sin(t) + y_0;
    
    (!(t < 2*PI)) ? t = 0 : t += 0.01;
}

void loop(){
    if ((millis() % 100) == 0){
        display.draw();
    }
    if ((millis() % 200) == 0){
        gameUpdate();
    }
}
```

## Libraries Used
- For the 1.8" tft display : https://github.com/sumotoy/TFT_ILI9163C
- For the 4x4 Keypad : https://playground.arduino.cc/Code/Keypad/