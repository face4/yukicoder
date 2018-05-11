import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

class Enemy{
    int xl,yu,xr,yd;
    int number;
    Enemy(int xl , int yu , int xr , int yd, int number){
        this.xl = xl;
        this.yu = yu;
        this.xr = xr;
        this.yd = yd;
        this.number = number;
    }
}

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        
        int n = Integer.parseInt(input[0]);
        int laserL = Integer.parseInt(input[1]);
        int laserR = Integer.parseInt(input[2]);
        
        int[] beam = new int[1281];
        Arrays.fill(beam, 0);

        Enemy[] enemies = new Enemy[n];
        for(int i = 0; i < n; i++){
            input = br.readLine().split(" ");
            enemies[i] = new Enemy(Integer.parseInt(input[0]),Integer.parseInt(input[1]),
                                    Integer.parseInt(input[2]), Integer.parseInt(input[3]), i+1);
        }

        Arrays.sort(enemies, new Comparator<Enemy>(){
            @Override
            public int compare(Enemy e1, Enemy e2){
                return e1.yd - e2.yd;
            }
        });

        for(int i = 0; i < n; i++){
            for(int j = Math.max(1,enemies[i].xl); j <= Math.min(1280,enemies[i].xr); j++){
                beam[j] = enemies[i].number;
            }
        }

        boolean[] hit = new boolean[n];
        for(int i = laserL; i <= laserR; i++){
            if(beam[i] != 0){
                hit[beam[i]-1] = true;
            }
        }

        for(int i = 0; i < n; i++){
            if(hit[i])   System.out.println("1");
            else        System.out.println("0");
        }
        
    }
}