package inferno.spritemaker;

import java.util.HashMap;

public class ColorPallet {
    private HashMap<Integer, Integer> colorMap = new HashMap<>();

    public void addColor(int ID, int COLOR){
        colorMap.put(ID, COLOR);
    }

    public HashMap<Integer, Integer> getColorMap() {
        return colorMap;
    }

    public String toCode(){
        String builder = ("ColorPallet " + "(new Color["+colorMap.keySet().size()+"]) {\n");

        for (int key : colorMap.keySet()){
            builder+=("\tColor("+key+", 0x"+Integer.toHexString(colorMap.get(key))+"),\n");
        }

        builder+=("};\n");

        return builder;
    }
}
