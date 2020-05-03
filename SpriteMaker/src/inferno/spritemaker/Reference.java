package inferno.spritemaker;

import javax.swing.tree.DefaultMutableTreeNode;

public class Reference {
    public static final String VERSION = "1.0.0-a";

    public static final ColorPallet DEFAULT_COLOR_PALLET = new ColorPallet(ColorPallet.DEFAULT);
    static {
        /**
         #define BLACK      getColorFromRef(0);
         #define DARK_BLUE  getColorFromRef(1);
         #define DARK_RED   getColorFromRef(2);
         #define DARK_GREEN getColorFromRef(3);
         #define MAGENTA    getColorFromRef(4);
         #define PURPLE     getColorFromRef(5);
         #define ORANGE     getColorFromRef(6);
         #define BROWN      getColorFromRef(7);
         #define WHITE      getColorFromRef(8);
         #define BLUE       getColorFromRef(9;
         #define RED        getColorFromRef(10);
         #define GREEN      getColorFromRef(11);
         #define PINK       getColorFromRef(12);
         #define CYAN       getColorFromRef(13);
         #define YELLOW     getColorFromRef(14);
         */
        DEFAULT_COLOR_PALLET.addColor(0, 0);
        DEFAULT_COLOR_PALLET.addColor(0, 0);
        DEFAULT_COLOR_PALLET.addColor(0, 0);
        DEFAULT_COLOR_PALLET.addColor(0, 0);
        DEFAULT_COLOR_PALLET.addColor(0, 0);
        DEFAULT_COLOR_PALLET.addColor(0, 0);
        DEFAULT_COLOR_PALLET.addColor(0, 0);
        DEFAULT_COLOR_PALLET.addColor(0, 0);
        DEFAULT_COLOR_PALLET.addColor(0, 0);
    }
}
