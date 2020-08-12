import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String a[] = br.readLine().split(" ");
        int b[] = new int[4];
        for(int i = 0; i < 4; i++){
            b[i] = Integer.parseInt(a[i]);
        }
        if(b[0] == b[2]){
            System.out.println(b[1]==b[3] ? "Draw" : (b[1]+1)%3==b[3] ? "null" : "tRue");
        }else{
            System.out.println(b[0] > b[2] ? "null" : "tRue");
        }
    }
}
