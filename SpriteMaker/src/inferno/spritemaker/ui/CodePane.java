package inferno.spritemaker.ui;

import javax.swing.*;
import java.awt.*;

public class CodePane extends JPanel {
    private JTextPane output;
    private JButton generate;

    public CodePane() {
        setLayout(new BorderLayout());
        add(output = new JTextPane(), BorderLayout.CENTER);
        output.setEditable(false);
        add(generate = new JButton("Generate"), BorderLayout.SOUTH);
    }

    public JButton getGenerate() {
        return generate;
    }


    public JTextPane getOutput() {
        return output;
    }
}
