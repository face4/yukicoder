import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] items = new int[11];
        while(n-- > 0){
            String[] input = br.readLine().split(" ");
            for(int i = 0; i < 3; i++){
                items[Integer.parseInt(input[i])]++;
            }
        }
        int rest = 0;
        int score = 0;
        for(int i = 1; i <= 10; i++){
            score += items[i]/2;
            rest += items[i]%2;
        }

        score += rest / 4;

        System.out.println(score);
    }  
}          