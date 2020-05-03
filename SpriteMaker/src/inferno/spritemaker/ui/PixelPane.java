package inferno.spritemaker.ui;

import javax.swing.*;
import java.awt.*;

public class PixelPane extends JPanel {
    private Pixel[][] pixels;

    public PixelPane(int spriteWidth, int spriteHeight) {
        this.pixels = new Pixel[spriteHeight][spriteWidth];


    }
}
