package inferno.spritemaker.ui;

import inferno.spritemaker.ColorPallet;

import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.TreeSelectionModel;
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
    int currentColorID = 0;

    ColorTreeNode customColorNode = new ColorTreeNode("Custom Pallet",null,  0);

    public ColorPane() {
        setLayout(new BorderLayout());
        colorTree = new JTree(customColorNode);
        colorTree.getSelectionModel().setSelectionMode
                (TreeSelectionModel.SINGLE_TREE_SELECTION);

        add(colorChooser, BorderLayout.NORTH);
        add(treeView=new JScrollPane(colorTree), BorderLayout.CENTER);
        row.setLayout(new BorderLayout());
        row.add(colorNameLabel, BorderLayout.LINE_START);
        row.add(colorName, BorderLayout.CENTER);
        row.add(addColorButton=new JButton("Add Color"), BorderLayout.LINE_END);
        add(row, BorderLayout.SOUTH);
    }


    public int getCurrentColorID() {
        return currentColorID;
    }

    public JButton getAddColorButton() {
        return addColorButton;
    }

    public Color getCurrentColor() {
        return colorChooser.getColor();
    }

    public ColorPallet getColorPallet() {
        return pallet;
    }

    public void setCurrentColorID(int colorID) {
        currentColorID = colorID;
    }
}
