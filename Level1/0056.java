import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

        int d = Integer.parseInt(input[0]);
        int p = Integer.parseInt(input[1]);

        System.out.println((d*(100+p)/100));
    }
}