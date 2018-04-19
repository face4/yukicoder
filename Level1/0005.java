import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int L = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(input[i]);
        }

        Arrays.sort(arr);

        int sum = 0;
        int i;
        for(i = 0; i < n; i++){
            if(sum + arr[i] <= L){
                sum += arr[i];
            }else{;
                break;
            }
        }

        System.out.println(i);
    }
}