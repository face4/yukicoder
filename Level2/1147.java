import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        int x[][] = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                x[i][j] = i==j ? 0 : 1<<29;
            }
        }
        while(m-- > 0){
            line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0])-1;
            int b = Integer.parseInt(line[1])-1;
            x[a][b] = x[b][a] = 1;
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    x[i][j] = Math.min(x[i][j], x[i][k]+x[k][j]);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(x[i][j] == 2) continue;
                for(int k = j+1; k < n; k++){
                    if(x[i][k] != 2 && x[j][k] != 2)    ans++;
                }
            }
        }
        System.out.println(ans);
    }
}
