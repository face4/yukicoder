import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int l = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        /*
        int ans = 0;  
        while(l > 2*k){ 
            ans += k;
            l -= 2*k;
        }
        */
        int ans = l / (2*k) * k;
        if(l%(2*k) == 0) ans -= k;
        System.out.println(ans);
    }
}