import java.io.*;

public class Main {
    static int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a%b);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int a[] = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(br.readLine());
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int g = gcd(a[i], a[j]);
                if(g == 1){
                    ans += n-j-1;
                    continue;
                }
                for(int k = j+1; k < n; k++){
                    ans += gcd(g, a[k])==1 ? 1 : 0;
                }
            }
        }
        System.out.println(ans);
    }
}
