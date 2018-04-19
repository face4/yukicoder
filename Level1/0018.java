import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] line = br.readLine().toCharArray();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < line.length; i++) {
            int diff = (int) (line[i] - (i + 1) % 26);
            if (diff < (int)'A')
                diff += 26;
            sb.append((char) (diff));
        }

        System.out.println(sb.toString());
    }
}