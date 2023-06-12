import java.util.*;
public class Balloons{
    static HashMap<String, Integer> results = new HashMap<String, Integer>();
    public static void main(String [] args){

    }

    static void getInput(){
        Scanner s = new Scanner(System.in).useLocale(Locale.US);
        while(s.hasNext()){
            int teams = s.nextInt();
            //System.out.println(teams);
            int balloons = s.nextInt();
            //System.out.println(balloons);
            if(teams != 0 && balloons != 0){
                for(int i = 0; i < balloons; i++){
                    String team = s.next();
                    //System.out.println(team + "team");
                    s.next();
                    if(results.containsKey(team)){
                        results.replace(team, results.get(team) +1);
                    } else {
                        results.put(team, 0);
                    }
                }
            } else {
                break;
            }
        }
    }

    static boolean getContest(){
        Scanner s = new Scanner(System.in).useLocale(Locale.US);
        int teams = s.nextInt();
        //System.out.println(teams);
        int balloons = s.nextInt();
        //System.out.println(balloons);
        boolean end = teams == 0 && balloons == 0;
        if(!end){
            for(int i = 0; i < balloons; i++){
                String team = s.next();
                //System.out.println(team + "team");
                s.next();
                if(results.containsKey(team)){
                    results.replace(team, results.get(team) +1);
                } else {
                    results.put(team, 0);
                }
            }
        }
        return end;
    }
}