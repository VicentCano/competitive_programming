import java.util.*;

public class Balloons2{
    public static void main(String [] args){
        Scanner s = new Scanner(System.in).useLocale(Locale.US);
        while(true){
            int teams = s.nextInt();
            int balloons = s.nextInt();
            
            if(teams == 0 && balloons == 0) break;
            int [] results = new int[teams];
            for(int i = 0; i < balloons; i++){
                int team = s.nextInt(); // Integer.parseInt(s.next());
                s.nextLine();
                results[team-1]++;
            }
            int winner = getWinner(results, teams);
            if(winner != -1){
                System.out.println(winner+1);
            } else {
                System.out.println("EMPATE");
            }
        }
    }

    static int getWinner(int [] results, int teams){
        int winner = 0;
        int maxBalloons = -1;
        boolean tie = false;

        for(int i = 0; i < teams; i++){
            if(results[i] > maxBalloons){
                maxBalloons = results[i];
                winner = i;
                tie = false;
            } else if(maxBalloons == results[i]){
                tie = true;
            }
        }
        
        if(tie){
            return -1;
        } else {
            return winner;
        }
    }

}