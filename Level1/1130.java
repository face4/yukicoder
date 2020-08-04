import java.io.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int h = Integer.parseInt(line[0]), w = Integer.parseInt(line[1]);
        ArrayList<Integer> arr = new ArrayList<Integer>(h * w);
        for (int i = 0; i < h; i++) {
            line = br.readLine().split(" ");
            for (int j = 0; j < w; j++) {
                arr.add(Integer.parseInt(line[j]));
            }
        }
        arr.sort(null);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (j > 0) System.out.print(" ");
                System.out.print(arr.get(i * w + j));
            }
            System.out.println();
        }
    }
}
