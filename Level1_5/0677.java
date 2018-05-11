import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main{
    static long pow(long x, int n){
        if(n == 0){
            return 1;
        }else{
            return x * pow(x, n-1);
        }
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] array = new long [n*n + 2*n + 1];
        Arrays.fill(array, 0);
        int index = 0;
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < n+1; j++){
                array[index++] =  pow(2,i) * pow(5,j);
            }
        }
        Arrays.sort(array);
        for(long x : array){
            System.out.println(x);
        }
    }
}