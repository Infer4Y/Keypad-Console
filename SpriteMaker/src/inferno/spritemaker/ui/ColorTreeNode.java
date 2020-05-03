package inferno.spritemaker.ui;

import javax.swing.tree.DefaultMutableTreeNode;

public class ColorTreeNode extends DefaultMutableTreeNode {
    private String name;

    public ColorTreeNode(String name) {
        super(name);
        this.name = name;
    }

    public String getName() {
        return name;
    }
}
