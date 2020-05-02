#include "Arduino.h"
#include "_settings\Sprite_Settings.h"
#include "Sprite.h"
#include "Colors.h"
#include "Display.h"
#include <TFT_ILI9163C.h>

Sprite::Sprite(Display display, PixelLine *image) {
    _display = display;
    _image = image;
};


void Sprite::draw(int x, int y) {
    draw(x, y, 1);
};

void Sprite::draw(int x, int y, int scale) {
    for (int i = 0; i < SPRITEHIGHT; i++) {
        for (int j = 0; j < SPRITEWIDTH; j++) {
            int offX = (i != 0) ? scale : 0;
            int offY = (j != 0) ? scale : 0;
            _display.getDisplay()->fillRect(x + i + offX, y + j + offY, scale, scale, getColorFromRef(_image[j].data[i]));
        }
    }
};