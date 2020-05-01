#include <Adafruit_GFX.h>

#include <SPI.h>

#include <TFT_ILI9163C.h>
#include <Display.h>
#include <Colors.h>
#include <Sprite.h>

#define __DC 9
#define __CS 10

Display display = Display(TFT_ILI9163C(__CS, __DC));

int x = 0, oldX= 0, y = 0, oldY = 0;

bool dirX = true, dirY = true;

void setup(){
    display.begin();
}

void Display::draw(){
    getDisplay().fillRect(oldX, oldY, 10, 10, BLACK);
    getDisplay().fillRect(x, y, 10, 10, RED);
    oldX = x; oldY = y;
}

void gameUpdate(){
    (dirX) ? x+=5 : x-=5;
    (dirY) ? y+=10 : y-=10;

    dirX = !(x-10 >= 118);
    dirY = !(y-10 >= 118);

    dirX = (x-10 <= 0);
    dirY = (y-10 <= 0);

}

void loop(){
    if ((millis() % 100) == 0){
        display.draw();
    }
    if ((millis() % 200) == 0){
        gameUpdate();
    }
}
