package inferno.spritemaker;

import java.util.HashMap;

public class ColorPallet {
    private HashMap<Integer, Integer> colorMap = new HashMap<>();

    public String toCode(){
        String builder = "";
        builder=("Color " + "Pallet["+colorMap.keySet().size()+"] {\n");

        for (int key : colorMap.keySet()){
            builder+=("\tColor("+key+", 0x"+Integer.toHexString(colorMap.get(key))+"),\n");
        }

        builder+=("};\n");

        return builder;
    }
}
