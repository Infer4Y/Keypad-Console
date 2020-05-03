package inferno.spritemaker.ui;

import inferno.spritemaker.ColorPallet;
import inferno.spritemaker.Reference;

import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Window extends JFrame {
    private SpriteSize spriteSize;
    private JButton spriteConfirmButton;

    private ColorPane colorPane;
    private CodePane codePane;
    private PixelPane pixelPane;

    public Window(){
        super("SpriteMaker V"+ Reference.VERSION + " | Sprite Size");
        setLayout(new BorderLayout());
        add(spriteSize = new SpriteSize(), BorderLayout.CENTER);
        add(spriteConfirmButton = new JButton("Build"), BorderLayout.SOUTH);
        spriteConfirmButton.addActionListener(e -> {
            remove(spriteSize);
            remove(spriteConfirmButton);
            setup(spriteSize.getSpriteWidth(), spriteSize.getSpriteHeight());
        });
        setSize(200,200);
        setLocationRelativeTo(null);


        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    private void setup(int spriteWidth, int spriteHeight){
        setTitle("SpriteMaker V"+ Reference.VERSION + " | Sprite Editor");
        // Add color bar and pixel canvas
        add(colorPane = new ColorPane(), BorderLayout.LINE_START);
        add(pixelPane = new PixelPane(spriteWidth, spriteHeight), BorderLayout.CENTER);
        add(codePane = new CodePane(), BorderLayout.LINE_END);

        colorPane.getAddColorButton().addActionListener(e -> {
            //colorPane;
        });

        setSize(1200, 900);
        setLocationRelativeTo(null);
    }

    public int getPixelFromID(int pixelID) {
        return colorPane.getCurrentColorID();
    }
}
