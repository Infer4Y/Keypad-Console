package inferno.spritemaker.ui;

import javax.swing.*;
import java.awt.*;

public class SpriteSize extends JPanel {
    JLabel spriteNameLabel = new JLabel("Name : ");
    JTextField spriteName = new JTextField("untitled");
    JLabel spriteSizeXLabel = new JLabel("Width : ");
    JTextField spriteSizeX = new JTextField("8");
    JLabel spriteSizeYLabel = new JLabel("Height : ");
    JTextField spriteSizeY = new JTextField("8");

    public SpriteSize(){
        setLayout(new GridLayout(2,2));

        add(spriteSizeXLabel);
        add(spriteSizeX);
        add(spriteSizeYLabel);
        add(spriteSizeY);
    }

    public String getSpriteName() {
        return spriteName.getText();
    }

    public int getSpriteWidth() {
        return new Integer(spriteSizeX.getText());
    }

    public int getSpriteHeight() {
        return new Integer(spriteSizeY.getText());
    }
}
