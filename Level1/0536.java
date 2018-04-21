import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        StringBuilder s = new StringBuilder(sc.next());
        if(s.toString().endsWith("ai")){
            s = s.replace(s.length()-2, s.length(),"AI");
        }else{
            s.append("-AI");
        }
        System.out.println(s);
    }
}