import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in, "UTF-8");
        String s = sc.nextLine();

        while(s.startsWith("ｗ"))   s = s.substring(1);

        String candidate = "";
        int grass = 0;
        String res = "";        
        int max_grass = 0;
        boolean isGrass = false;

        for(int i = 0; i < s.length(); i++){
            if(!isGrass && s.charAt(i)=='ｗ'){
                isGrass = true;
                grass++;
            }else if(!isGrass && s.charAt(i)!='ｗ'){
                candidate += s.charAt(i);
            }else if(isGrass && s.charAt(i)=='ｗ'){
                grass++;
            }else if(isGrass && s.charAt(i)!='ｗ'){
                if(grass > max_grass){
                    max_grass = grass;
                    res = candidate;
                }else if(grass == max_grass){
                    res += "\n";
                    res += candidate;
                }
                isGrass = false;
                grass = 0;
                candidate = String.valueOf(s.charAt(i));
            }
        }

        if(isGrass){
            if(grass > max_grass)   res = candidate;
            else if(grass == max_grass) res += "\n" + candidate;
        }

        System.out.println(res);
    }
}