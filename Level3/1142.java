import java.io.*;

public class Main {
    static int mod = 1000000007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        int k = Integer.parseInt(line[2]);
        int a[] = new int[n], b[] = new int[m];
        line = br.readLine().split(" ");
        for(int i = 0; i < n; i++)  a[i] = Integer.parseInt(line[i]);
        line = br.readLine().split(" ");
        for(int i = 0; i < m; i++)  b[i] = Integer.parseInt(line[i]);
        int acca[] = new int[1<<10], ax[] = new int[1<<10], accb[] = new int[1<<10], bx[] = new int[1<<10];
        acca[0] = accb[0] = 1;
        int tmp = 0;
        for(int i = 0; i < n; i++){
            tmp ^= a[i];
            acca[tmp]++;
        }
        tmp = 0;
        for(int i = 0; i < m; i++){
            tmp ^= b[i];
            accb[tmp]++;
        }
        for(int i = 0; i < 1<<10; i++){
            ax[0] += (int)((long)acca[i]*(acca[i]-1)/2%mod);
            ax[0] %= mod;
            bx[0] += (int)((long)accb[i]*(accb[i]-1)/2%mod);
            bx[0] %= mod;
            for(int j = i+1; j < 1<<10; j++){
                ax[i^j] += (long)acca[i]*acca[j]%mod;
                ax[i^j] %= mod;
                bx[i^j] += (long)accb[i]*accb[j]%mod;
                bx[i^j] %= mod;
            }
        }
        long ans = 0;
        for(int i = 0; i < 1<<10; i++){
            ans += (long)(ax[i]) * bx[k^i] % mod;
            ans %= mod;
        }
        System.out.println(ans);
    }
}
