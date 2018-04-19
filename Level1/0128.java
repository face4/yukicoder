import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long max = Long.parseLong(br.readLine());
        max /= 1000;
        int m = Integer.parseInt(br.readLine());
        System.out.println(max / m * 1000);
    }
}