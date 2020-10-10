import java.io.*;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int w = Integer.parseInt(line[1]);
        int a[] = new int[n];
        for(int i = 0; i < n; i++)  a[i] = Integer.parseInt(br.readLine());
        int l = 0, r = 0, sum = 0, ans = 0;
        HashSet<Integer> s = new HashSet<Integer>();
        while(r < n){
            if(sum+a[r] > w){
                sum -= a[l];
                s.remove(a[l++]);
                continue;
            }
            if(s.contains(a[r])){
                while(s.contains(a[r])){
                    sum -= a[l];
                    s.remove(a[l++]);
                }
            }
            sum += a[r];
            s.add(a[r++]);
            ans = Math.max(ans, r-l);
        }
        System.out.println(ans);
    }
}
