import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line[] = br.readLine().split(" ");
        int a = Integer.parseInt(line[0]);
        int b = Integer.parseInt(line[1]);
        int c = Integer.parseInt(line[2]);
        int d = Integer.parseInt(line[3]);
        int p = Integer.parseInt(line[4]);
        int q = Integer.parseInt(line[5]);
        long ma = -1L<<60, mi = 1L<<60, xma = 0, xmi = 0;
        for(long i = p; i <= q; i++){
            long v = a*i*i*i+b*i*i+c*i+d;
            if(v > ma){
                ma = v;
                xma = i;
            }
            if(v < mi){
                mi = v;
                xmi = i;
            }
        }
        System.out.println(ma + " " + xma + " " + mi + " " + xmi);
    }
}
