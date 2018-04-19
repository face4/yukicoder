import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int l = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        
        m += (n/25);
        n -= (n/25) * 25;

        l += (m/4);
        m -= (m/4) * 4;

        l -= (l/10) * 10;

        System.out.println((l+m+n));
    }
}  