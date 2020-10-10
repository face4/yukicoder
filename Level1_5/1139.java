import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line[] = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int d = Integer.parseInt(line[1]);
        br.readLine();
        line = br.readLine().split(" ");
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(sum >= d) break;
            sum += Integer.parseInt(line[i]);
        }
        System.out.println((d+sum-1)/sum);
    }
}
