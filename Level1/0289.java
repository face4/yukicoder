import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int sum = 0;

        for(char c : line.toCharArray()){
            if('0' <= c && c <= '9'){
                sum += (int)(c - '0');
            }
        }

        System.out.println(sum);
    }
}