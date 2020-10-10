import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        double d1 = Double.parseDouble(line[0]);
        double d2 = Double.parseDouble(line[1]);
        int ans = 0;
        if(d1+d1==d2 || d1==d2){
            ans = 4;
        }else if(d2/2 < d1 && d1 < d2){
            ans = 8;
        }
        System.out.println(ans);
    }
}
