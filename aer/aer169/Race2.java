import java.util.Scanner;

public class Race2{
    public static void main(String [] args){
        Scanner s = new Scanner(System.in);
        int cases = s.nextInt();
        s.nextLine();
        //String SN, prevSN, prevSN2;
        String SN, prevSN;
        for(int i = 0; i<cases; i++){
            int participants = 0, bros = 0, add = 1;
            SN = null;
            prevSN = null;
            //prevSN2 = null;
            while(true){
                String name = s.next();
                s.nextLine();
                if(name.equals("====")) break;
                //System.out.println(line);
                //System.out.println(line);
                participants++;
                SN = name.toLowerCase();
                //System.out.println(name);
                if(SN.equals(prevSN)){
                    bros = bros + 1 + add;
                    add = 0;
                } else {
                    add = 1;
                }
                /*
                boolean cond1 = SN.equals(prevSN);
                if(cond1 && prevSN.equals(prevSN2)){
                    bros++;
                } else if (cond1){
                    bros += 2;
                }
                prevSN2 = prevSN;
                */
                prevSN = SN;
            }
            System.out.println(participants + " " + bros);
        }
    }
}