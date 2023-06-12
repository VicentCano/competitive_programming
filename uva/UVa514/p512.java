import java.util.*;

class p512 {
    public static void main(String [] args){
        Scanner s = new Scanner(System.in).useLocale(Locale.US);
        int n;
        n = s.nextInt();
        s.nextLine();
        while(n != 0){
            String [] o = s.nextLine().split(" ");
            int ii = 1;
            int io = 0;
            Stack<Integer> st = new Stack<Integer>();
            if(o[0].equals("0")){
                System.out.println();
                n = s.nextInt();
                if(s.hasNextLine())s.nextLine();
            } else {
                
                while(ii <= n){
                    st.push(ii);
                    ii++;
                    while(!st.empty() && st.peek() == Integer.parseInt(o[io])){
                        
                        st.pop();
                        io++;
                    }
                }
                if(st.empty()){
                    System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
            }
            
        }
    }
}
