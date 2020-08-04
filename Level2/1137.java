import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

enum type {in, out};

class Point implements Comparable<Point>{
    int x;
    type t;
    Point(int x, type t){
        this.x = x;
        this.t = t;
    }
    @Override
    public int compareTo(Point p){
        if(this.x != p.x){
            return x-p.x;
        }else{
            return this.t == type.out ? -1 : 1;
        }
    }
}
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Point> a = new ArrayList<Point>(2*n);
        for(int i = 0; i < n; i++){
            String[] line = br.readLine().split(" ");
            int x = Integer.parseInt(line[0]);
            int r = Integer.parseInt(line[1]);
            a.add(new Point(x-r, type.in));
            a.add(new Point(x+r, type.out));
        }
        Collections.sort(a);
        int ret = 0, now = 0;
        for(int i = 0; i < 2*n; i++){
            now += a.get(i).t==type.in ? 1 : -1;
            ret = Math.max(ret, now);
        }
        System.out.println(ret);
    }
}
