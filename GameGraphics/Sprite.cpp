#include "Arduino.h"
#include "Sprite.h"
#include "Colors.h"
#include "Display.h"
#include <TFT_ILI9163C.h>

Sprite::Sprite(Display display, int[][] image) {
    _display = display;
    _image = image;
};

Sprite::draw(int x, int y) {
    draw(x, y, 1);
};

Sprite::draw(int x, int y, int scale) {
    for (int i = 0; i < (sizeof(_image) / sizeof(_image[0])); i++) {
        for (int j = 0; j < sizeof(_image[0]); j++) {
            int offX = (i != 0) ? scale : 0;
            int offY = (j != 0) ? scale : 0;
            _display.fillRect(x + i + offX, y + j + offY, scale, scale, getColor(_image[j][i]));
        }
    }
};