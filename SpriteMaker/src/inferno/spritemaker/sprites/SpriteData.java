package inferno.spritemaker.sprites;

import inferno.spritemaker.ui.Pixel;

import java.util.*;

public class SpriteData {
    private ArrayList<ArrayList<Integer>> data = new ArrayList<>();

    public void convertButtonData(Pixel[][] pixels){
        for (Pixel[] pixelRows: pixels) {
            ArrayList<Integer> pixelCol = new ArrayList<>();
            for (Pixel pixel: pixelRows) {
                pixelCol.add(pixel.getColorId());
            }
            data.add(pixelCol);
        }
    }

    public int[][] dataToArrays(){
        int[][] spriteData = new int[data.size()][data.get(0).size()];
        for (int i = 0; i < spriteData.length; i++) {
            for (int j = 0; j < spriteData[i].length; j++) {
                spriteData[i][j] = data.get(i).get(j);
            }
        }
        return spriteData;
    }

    public String toCode(String text){
        String builder = "Sprite "+text+" = Sprite(new PixelLine [] {\n";
        int[][] spriteData = dataToArrays();
        for (int i = 0; i < spriteData.length; i++) {
            builder+="\tgenPixelLine(";
            for (int j = 0; j < spriteData[i].length; j++) {
                builder+=spriteData[i][j]+((j == spriteData[i].length-1) ? ")"+((i == spriteData.length-1) ? "": ",")+"\n" : ",");
            }
        }
        builder+=("});\n");
        data.clear();
        return builder;
    }

}
