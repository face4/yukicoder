import java.io.*;
import java.util.Arrays;

public class Main {
    static long[][] cp(long[][] a){
        int h = a.length, w = a[0].length;
        long[][] ret = new long[h][w];
        for(int i = 0; i < h; i++){
            ret[i] = Arrays.copyOf(a[i], a[i].length);
        }
        return ret;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int h = Integer.parseInt(line[0]);
        int w = Integer.parseInt(line[1]);
        int mod = 1000000007;
        long a[][] = new long[h][w];
        for(int i = 0; i < h; i++){
            line = br.readLine().split(" ");
            for(int j = 0; j < w; j++){
                a[i][j] = Integer.parseInt(line[j]);
            }
        }
        long l[][] = new long[h][w], r[][] = new long[h][w];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(j == 0){
                    l[i][j] = a[i][j];
                    r[i][w-1-j] = a[i][w-1-j];
                }else{
                    l[i][j] = l[i][j-1]*a[i][j]%mod;
                    r[i][w-1-j] = r[i][w-1-j+1]*a[i][w-1-j]%mod;
                }
            }
        }
        long ld[][] = cp(l), lu[][] = cp(l);
        long rd[][] = cp(r), ru[][] = cp(r);
        for(int i = 1; i < h; i++){
            for(int j = 0; j < w; j++){
                ld[i][j] = ld[i-1][j]*l[i][j]%mod;
                lu[h-1-i][j] = lu[h-1-i+1][j]*l[h-1-i][j]%mod;
                rd[i][w-1-j] = rd[i-1][w-1-j]*r[i][w-1-j]%mod;
                ru[h-1-i][w-1-j] = ru[h-1-i+1][w-1-j]*r[h-1-i][w-1-j]%mod;
            }
        }
        int q = Integer.parseInt(br.readLine());
        while(q-- > 0){
            line = br.readLine().split(" ");
            int x = Integer.parseInt(line[0])-1;
            int y = Integer.parseInt(line[1])-1;
            long ans = 1;
            if(x-1 >= 0 && y-1 >= 0)  ans = ans*ld[x-1][y-1]%mod;
            if(x-1 >= 0 && y+1 < w)   ans = ans*rd[x-1][y+1]%mod;
            if(x+1 < h && y-1 >= 0)   ans = ans*lu[x+1][y-1]%mod;
            if(x+1 < h && y+1 < w)    ans = ans*ru[x+1][y+1]%mod;
            System.out.println(ans);
        }
    }
}
