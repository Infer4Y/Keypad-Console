package inferno.spritemaker.ui;

import javax.swing.*;
import java.awt.*;

public class SpriteSize extends JPanel {
    JLabel spriteSizeXLabel = new JLabel("Width : ");
    JTextField spriteSizeX = new JTextField();
    JLabel spriteSizeYLabel = new JLabel("Height : ");
    JTextField spriteSizeY = new JTextField();

    public SpriteSize(){
        setLayout(new GridLayout(2,2));
        add(spriteSizeXLabel);
        add(spriteSizeX);
        add(spriteSizeYLabel);
        add(spriteSizeY);
    }

    public int getSpriteWidth() {
        return new Integer(spriteSizeX.getText());
    }

    public int getSpriteHeight() {
        return new Integer(spriteSizeY.getText());
    }
}
