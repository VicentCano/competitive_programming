import java.util.Scanner;

public class f1necks{
    public static void main(String [] args){
        Scanner input = new Scanner(System.in);
        while(input.hasNextLine()){
            String line = input.nextLine();
            String [] numbers = line.split(" ");
            String []circuit = new String[Integer.parseInt(numbers[1])];
            for(int i = 0; i<Integer.parseInt(numbers[1]); i++){
                circuit [i] = input.nextLine();
            }
            for(int i = 0; i<Integer.parseInt(numbers[1]); i++){
                System.out.println(circuit[i]);
            }
        }
    }
}