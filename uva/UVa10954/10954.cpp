#include <iostream>
#include <queue>
using namespace std;

int main(){
    int  n, a, b;
    long long cost = 0, ts = 0;
    
    cin >> n;
    while(n != 0){
        priority_queue<int> pq;
        for(int i = 0; i<n; i++){
            cin >> a;
            pq.push(-a);
        }
        while(pq.size() > 1){
            a = -pq.top();
            pq.pop();
            b = -pq.top();
            pq.pop();
            ts = (a+b);
            cost += ts;
            pq.push(-ts);
            
        } 

        cout << cost << endl;
        cost = 0;
        cin >> n;
    }
    return 0;
}