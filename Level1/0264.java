import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

        int result = Integer.parseInt(input[0]) - Integer.parseInt(input[1]);

        if (result == 0) {
            System.out.println("Drew");
        } else if (result == 1 || result == -2) {
            System.out.println("Lost");
        } else if (result == 2 || result == -1) {
            System.out.println("Won");
        }
    }
}