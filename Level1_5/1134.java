import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        int x[] = new int[n];
        double sum = 0;
        for(int i = 0; i < n; i++){
            x[i] = Integer.parseInt(line[i]);
            sum += x[i];
        }
        sum /= n;
        double d = 0;
        for(int i = 0; i < n; i++){
            d += Math.pow(sum-x[i], 2.0);
        }
        d = Math.sqrt(d/n);
        int m = Integer.parseInt(br.readLine())-1;
        int ret = 50;
        if(d > 0){
            ret += (x[m]-sum)*10/d;
        }
        System.out.println(ret);
    }
}
