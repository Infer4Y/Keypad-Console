package inferno.spritemaker.ui;

import inferno.spritemaker.sprites.SpriteData;

import javax.swing.*;
import java.awt.*;

public class PixelPane extends JPanel {
    private Pixel[][] pixels;
    private SpriteData spriteData = new SpriteData();

    public PixelPane(int spriteWidth, int spriteHeight) {
        setLayout(new GridLayout(spriteHeight, spriteWidth));
        this.pixels = new Pixel[spriteHeight][spriteWidth];

        for (int i = 0; i < spriteHeight; i++){
            for (int j = 0; j < spriteWidth; j++){
                this.pixels[i][j] = new Pixel("");
                add(pixels[i][j]);
            }
        }
    }

    public void updateSprite(){
        spriteData.convertButtonData(pixels);
    }

    public Pixel[][] getPixels() {
        return pixels;
    }

    public SpriteData getSpriteData() {
        return spriteData;
    }
}
