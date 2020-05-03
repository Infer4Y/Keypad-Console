package inferno.spritemaker.ui;

import inferno.spritemaker.ColorPallet;

import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
import java.awt.*;

public class ColorPane extends JPanel {
    private ColorPallet pallet = new ColorPallet();
    private JColorChooser colorChooser = new JColorChooser();
    JTree colorTree;
    JScrollPane treeView;
    private JPanel row = new JPanel();
    private JButton addColorButton;
    JLabel colorNameLabel = new JLabel("Color Name : ");
    JTextField colorName = new JTextField("untitled");

    public ColorPane() {
        setLayout(new BorderLayout());

        ColorTreeNode top = new ColorTreeNode("Colors",null,  0);
        setupTree(top);
        colorTree = new JTree(top);
        add(colorChooser, BorderLayout.NORTH);
        add(treeView=new JScrollPane(colorTree), BorderLayout.CENTER);
        row.setLayout(new BorderLayout());
        row.add(colorNameLabel, BorderLayout.LINE_START);
        row.add(colorName, BorderLayout.CENTER);
        row.add(addColorButton=new JButton("Add Color"), BorderLayout.LINE_END);
        add(row, BorderLayout.SOUTH);
    }

    ColorTreeNode customColorNode = new ColorTreeNode("Custom Pallet",null,  0);

    private void setupTree(DefaultMutableTreeNode node){
        node.add(customColorNode);
    }

    public int getCurrentColorID() {
        return 0;
    }

    public JButton getAddColorButton() {
        return addColorButton;
    }

    public Color getCurrentColor() {
        return colorChooser.getColor();
    }
}
