import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        String[] input = br.readLine().split(" ");
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(input[i]);
        }

        Arrays.sort(arr);

        if(n%2 == 0){
            System.out.printf("%.1f%n", (arr[n/2] + arr[n/2-1])/2.0);
        }else{
            System.out.printf("%d%n", arr[n/2]);
        }
    }
}