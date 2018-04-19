import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        if(br.readLine().equals("1")){
            System.out.println("0");
        }else{
            System.out.println("1");
        }
    }
}