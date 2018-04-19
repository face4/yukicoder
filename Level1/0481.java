import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        for(int i = 1; i <= 9; i++){
            if(Integer.parseInt(input[i-1]) != i){
                System.out.println(i);
                return;
            }
        }
        System.out.println("10");
    }
}