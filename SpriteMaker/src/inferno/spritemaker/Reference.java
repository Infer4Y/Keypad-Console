package inferno.spritemaker;

import javax.swing.tree.DefaultMutableTreeNode;
import java.awt.*;

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

    public static int toRGB565(String code){ // #ffffff
        return toRGB565(new Color(
                Integer.valueOf( code.substring( 1, 3 ), 16 ),
                Integer.valueOf( code.substring( 3, 5 ), 16 ),
                Integer.valueOf( code.substring( 5, 7 ), 16 ) ));
    }

    public static int toRGB565(Color color){
        return toRGB565(color.getRed(), color.getGreen(), color.getBlue());
    }

    private static int toRGB565(int red, int green, int blue) {
        return (((red & 0xf8)<<8) + ((green & 0xfc)<<3)+(blue>>3));
    }
}
