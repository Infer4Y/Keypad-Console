package inferno.spritemaker.ui;

import inferno.spritemaker.ColorPallet;
import inferno.spritemaker.Reference;
import inferno.spritemaker.sprites.SpriteData;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
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
            colorPane.getColorPallet().addColor(colorPane.customColorNode.getChildCount(), Reference.toRGB565(colorPane.getCurrentColor()));
            ColorTreeNode temp = new ColorTreeNode(colorPane.colorName.getText(), colorPane.getCurrentColor(), colorPane.customColorNode.getChildCount());
            colorPane.customColorNode.add(temp);
            colorPane.colorTree.updateUI();
        });

        colorPane.colorTree.addTreeSelectionListener(new TreeSelectionListener() {
            @Override
            public void valueChanged(TreeSelectionEvent e) {
                ColorTreeNode node = (ColorTreeNode)
                        colorPane.colorTree.getLastSelectedPathComponent();

                if (node == null)
                    return;

                if (node.isLeaf()) {
                    colorPane.setCurrentColorID(node.getID());
                }
            }
        });

        codePane.getGenerate().addActionListener(e -> {
            pixelPane.updateSprite();
            codePane.getOutput().setText(colorPane.getColorPallet().toCode()+ pixelPane.getSpriteData().toCode(spriteSize.spriteName.getText()));
        });

        genButtonHandle();

        setSize(1200, 900);
        setLocationRelativeTo(null);
    }

    private void genButtonHandle(){
        int pixelID = 0;
        for (Pixel[] pixelRow : pixelPane.getPixels()){
            for (Pixel pixel: pixelRow) {
                pixel.addActionListener(Pixel.buildActionListener(pixelID));
                pixelID++;
            }
        }
    }

    public void updatePixels(int IDPIXEL){
        int pixelID = 0;
        for (Pixel[] pixelRow : pixelPane.getPixels()){
            for (Pixel pixel: pixelRow) {
                if (IDPIXEL == pixelID){
                    pixel.setColorId(colorPane.getCurrentColorID());
                    pixel.setBackground(((ColorTreeNode) colorPane.colorTree.getLastSelectedPathComponent()).getColor());
                    return;
                }
                pixelID++;
            }
        }
    }

    public int getPixelFromID(int pixelID) {
        updatePixels(pixelID);
        return colorPane.getCurrentColorID();
    }

    public String getSpriteName() {
        return spriteSize.spriteName.getText();
    }
}
