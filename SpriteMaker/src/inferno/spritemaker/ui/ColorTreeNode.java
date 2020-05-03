package inferno.spritemaker.ui;

import javax.swing.tree.DefaultMutableTreeNode;
import java.awt.*;

public class ColorTreeNode extends DefaultMutableTreeNode {
    private String name;
    private int ID = 0;
    private Color color = Color.BLACK;

    public ColorTreeNode(String name, Color color, int id) {
        super(name);
        this.name = name;
        this.color = color;
        this.ID = id;
    }

    public String getName() {
        return name;
    }

    public int getID() {
        return ID;
    }

    public Color getColor() {
        return color;
    }
}
