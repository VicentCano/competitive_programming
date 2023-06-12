import java.util.*;

public class hexNoStack{
    public static void main(String [] args){
        Scanner input = new Scanner(System.in).useLocale(Locale.US);
        int slength;
        char c;
        while(input.hasNext()){
            slength = input.nextInt();
            c = input.next().charAt(0);
            if(slength == 0 && c =='0') break;
            printU(slength, c);
            printL(slength, c);
        }
    }
    static void printU(int l, char c){
        for(int i = 0; i<l; i++){
            String line = "";
            for(int j = 0; j<l-i-1; j++){
                line = line + " ";
            }
            for(int k = 0; k<l + 2 * i; k++){
                line = line + c;
            }
            System.out.println(line);
        }
    }

    static void printL(int l, char c){
        for(int i = l-2; i>=0; i--){
            String line = "";
            for(int j = 0; j<l-i-1; j++){
                line = line + " ";
            }
            for(int k = 0; k<l + 2 * i; k++){
                line = line + c;
            }
            System.out.println(line);
        }
    }

    
}