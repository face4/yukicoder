import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

        int s = Integer.parseInt(input[0]);
        int f = Integer.parseInt(input[1]);

        int ans = s / f + 1;
        System.out.println(ans);
    }
}