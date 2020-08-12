import java.io.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer> arr = new ArrayList<Integer>(n);
        String line[] = br.readLine().split(" ");
        double sum = 0;
        for(int i = 0; i < n; i++){
            arr.add(Integer.parseInt(line[i]));
            sum += arr.get(i);
        }
        sum /= n;
        for(int i = 0; i < n; i++){
            System.out.println((int)(50.0-(sum-arr.get(i))/2));
        }
    }
}
