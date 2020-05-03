package inferno.spritemaker.ui;

import inferno.spritemaker.Main;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Pixel extends JButton {
    private int COLORID;
    private int PIXELID;


    public Pixel(String text) {
        super(text);
    }

    public int getColorId() {
        return COLORID;
    }

    public void setColorId(int id) {
        this.COLORID = id;
    }

    public static PixelAction buildActionListener(int pixelID){
        return new PixelAction(pixelID);
    }
    private static class PixelAction implements ActionListener {
        private int pixelID;

        public PixelAction(int pixelID) {
            this.pixelID = pixelID;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            Main.window.getPixelFormID(pixelID);
        }
    }
}
