import java.util.*;

public class hex{
    public static void main(String [] args){
        Scanner input = new Scanner(System.in).useLocale(Locale.US);
        int slength;
        char c;
        while(input.hasNext()){
            slength = input.nextInt();
            c = input.next().charAt(0);
            if(slength == 0 && c =='0') break;
            genAndPrint(slength, c);
        }
    }
    static void genAndPrint(int l, char c){
        
        Stack<String> lines = new Stack<String>();

        for(int i = 0; i<l; i++){
            String line = "";
            for(int j = 0; j<l-i-1; j++){
                line = line + " ";
            }
            for(int k = 0; k<l + 2 * i; k++){
                line = line + c;
            }
            lines.push(line);
            System.out.println(line);
        }
        
        if(!lines.empty()) lines.pop();
    
        while(!lines.empty()){
            System.out.println(lines.pop());
        }
    }
}