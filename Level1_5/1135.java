import java.io.*;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        Stack<Integer> s = new Stack<Integer>();
        for(int i = 0; i < n; i++){
            if(line[i].equals("+")){
                s.push(s.pop()+s.pop());
            }else if(line[i].equals("-")){
                s.push(-s.pop()+s.pop());
            }else{
                s.push(Integer.parseInt(line[i]));
            }
        }
        System.out.println(s.peek());
    }
}
