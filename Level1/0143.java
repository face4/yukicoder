import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

        int k = Integer.parseInt(input[0]);
        int n = Integer.parseInt(input[1]);
        int f = Integer.parseInt(input[2]);
        int res = k * n;

        String[] family = br.readLine().split(" ");
        for (int i = 0; i < f; i++) {
            res -= Integer.parseInt(family[i]);
        }

        System.out.println(Math.max(-1, res));
    }
}