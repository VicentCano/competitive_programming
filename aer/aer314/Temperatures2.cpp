#include<iostream>
using namespace std;

int main(){
    //bool ascending;
    int cases, records, current, previous, next, picos, valles;
    cin >> cases;
    while(cases--){
        picos = 0;
        valles = 0;
        cin >> records;
        if(records <= 2){
            cout << "0 0" << endl;
            for(int i = 0; i<records; i++, cin >> previous);
        } else {
            cin >> previous >> current >> next;
            //ascending = previous < current;
            for(int j = 0; j < records-3; j++){
                previous = current;
                current = next;
                cin >> next;
                if(previous < current && current > next){
                    picos++;
                } else if (previous < current && current > next){
                    valles++;
                }
            }
            cout << picos << " " << valles << endl;
        }
    }
    return 0;
}