import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        s = s.replaceAll("I", "1");
        s = s.replaceAll("l", "1");
        s = s.replaceAll("O", "0");
        s = s.replaceAll("o", "0");
        System.out.println(s);
    }
}