#include<iostream>
using namespace std;

int main(){
    int h, u, d, f, day;
    double ch, cu;
    cin >> h;
    while(h != 0){
        cin>>u>>d>>f;
        ch = u;
        cu = u;
        day = 1;
        while(true){
            //cout << day << endl;
            //cout << "Distance climbed " << cu << endl;
            //cout << "Height After Climbing " << ch << endl;
            if(ch > h){
                cout<<"success on day "<<day<<endl;
                break;
            }
            ch = ch - d;
            //cout << "Height After Sliding " << ch << endl;
            if(ch < 0){
                cout<<"failure on day "<<day <<endl;
                break;
            }
            if(ch == 0){
                cout<<"failure on day "<<day+1<<endl;
                break;
            }
            cu -= u * (f/100.0);
            if(cu < 0) cu = 0;
            ch = ch + cu;
            day++;
        }
        
        cin>>h;
    }
    return 0;
}