package inferno.spritemaker.ui;

import inferno.spritemaker.ColorPallet;

import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
import java.awt.*;

public class ColorPane extends JPanel {
    private ColorPallet pallet = new ColorPallet();
    private JColorChooser colorChooser = new JColorChooser();
    private JTree colorTree;
    JScrollPane treeView;
    private JButton addColorButton;

    public ColorPane() {
        setLayout(new BorderLayout());

        ColorTreeNode top = new ColorTreeNode("Colors");
        setupTree(top);
        colorTree = new JTree(top);
        add(colorChooser, BorderLayout.NORTH);
        add(treeView=new JScrollPane(colorTree), BorderLayout.CENTER);
        add(addColorButton=new JButton("Add Color"), BorderLayout.SOUTH);
    }

    ColorTreeNode customColorNode = new ColorTreeNode("Custom Pallet");

    private void setupTree(DefaultMutableTreeNode node){
        node.add(customColorNode);
    }

    public int getCurrentColorID() {
        return 0;
    }

    public JButton getAddColorButton() {
        return addColorButton;
    }
}
