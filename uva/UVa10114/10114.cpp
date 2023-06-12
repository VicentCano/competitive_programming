#include<iostream>
using namespace std;

int main(){
    int m, nd, k, result;
    double dp, o, v, cd, md, mp; 
    cin >> m;
    while(m > -1){
        cin >> dp >> o >> nd;
        if( m!= 0 ) mp = (o/m);
        v = o + dp;
        double d [m] = {0};
        for(int i = 0; i<nd; i++){
            cin >> k >> cd;
            d[k] = cd;
        }
        md = (1.0-d[0]);
        v = v * md;
        if(v > o)
        {
            cout << 0 << " months" <<endl;
        } else {
            int i =1;
            while(i<m){
                o -= mp;
                if(d[i] != 0.0){
                    md = (1.0-d[i]);
                } 
                v = v * md;
                if(v > o){
                    string ms = (i==1)?" month":" months";
                    cout << i << ms << endl;
                    break;
                }
                i++;
                if(i == m) {
                    string ms = (i==1)?" month":" months";
                    cout << i << ms << endl;
                }
            }
            
        }
        cin >> m;
        
    }
    return 0;
}