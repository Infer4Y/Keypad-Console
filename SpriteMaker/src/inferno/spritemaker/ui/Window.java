package inferno.spritemaker.ui;

import inferno.spritemaker.ColorPallet;
import inferno.spritemaker.Reference;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Window extends JFrame {
    private SpriteSize spriteSize;
    private JButton spriteConfirmButton;
    private ColorPallet pallet = new ColorPallet();

    public Window(){
        super("SpriteMaker V"+ Reference.VERSION + " | Sprite Size");
        setSize(600, 400);
        add(spriteSize = new SpriteSize(), CENTER_ALIGNMENT);
        add(spriteConfirmButton = new JButton(), BOTTOM_ALIGNMENT);
        spriteConfirmButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                remove(spriteSize);
                remove(spriteConfirmButton);
                setup(spriteSize.getSpriteWidth(), spriteSize.getSpriteHeight());

            }
        });



        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    private void setup(int spriteWidth, int spriteHeight){

        // Add color bar and pixel canvas
    }

}
