#include "Arduino.h"
#include "Sprite.h"
#include "Colors.h"
#include "Display.h"
#include <TFT_ILI9163C.h>

Sprite::Sprite(Display display, PixelLine *image) {
    _display = display;
    _image = image;
};

Sprite::Sprite(Display display, PixelLine *image, int width, int height) {
    _display = display;
    _image = image;
    _width = width;
    _height = height;
};

void Sprite::draw(int x, int y) {
    draw(x, y, 1, getDefaultPallet());
};

void Sprite::draw(int x, int y, int scale) {
    draw(x, y, scale, getDefaultPallet());
};

void Sprite::draw(int x, int y, ColorPallet pallet) {
    draw(x, y, 1, pallet);
};

void Sprite::draw(int x, int y, int scale, ColorPallet pallet) {
    Serial.println("X : " + String(x) + ", Y : ," + String(y) + ", Scale : " + String(scale));
    
    for (int i = 0; i < _height; i++) {
            int offY = (i != 0) ? scale : 0;
        for (int j = 0; j < _width; j++) {
            int offX = (j != 0) ? scale : 0;
            _display.getDisplay()->fillRect(x + j * offX, y + i * offY, scale, scale, pallet.getColorFromID(int(_image[i].data[j])));
        }
    }
};

PixelLine genPixelLine(int* line){
    PixelLine temp = PixelLine();
    temp.data = line;
    return temp;
}
