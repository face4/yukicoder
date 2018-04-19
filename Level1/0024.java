import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[10];
        while (n-- > 0) {
            String[] input = br.readLine().split(" ");
            if (input[4].equals("YES")) {
                for (int i = 0; i < 4; i++) {
                    arr[Integer.parseInt(input[i])]++;
                }
            } else if (input[4].equals("NO")) {
                for (int i = 0; i < 4; i++) {
                    arr[Integer.parseInt(input[i])]--;
                }
            }
        }

        int maxIndex = 0;
        int maxValue = arr[0];
        for (int i = 1; i < 10; i++) {
            if (maxValue < arr[i]) {
                maxIndex = i;
                maxValue = arr[i];
            }
        }

        System.out.println(maxIndex);
    }
}