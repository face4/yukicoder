import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int x = Integer.parseInt(br.readLine());
        int y = Integer.parseInt(br.readLine());
        int l = Integer.parseInt(br.readLine());

        long res = 0;
        if(y > 0){
            if(x != 0) res++;
        }else if (y < 0){
            res += 2;
        }else if(y == 0){
            if(x != 0) res++;
        }

        res += Math.abs(x) / l + ((x%l == 0) ? 0 : 1);
        res += Math.abs(y) / l + ((y%l == 0) ? 0 : 1);
        
        System.out.println(res);
    }
}