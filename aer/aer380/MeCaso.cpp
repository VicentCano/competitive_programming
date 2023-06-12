#include <iostream>
using namespace std;

int main(){
    int spendings, nextSpending;
    cin >> spendings;
    while(spendings != 0){
        int totalCost = 0;
        for(int i = 0; i < spendings; i++){
            cin >> nextSpending;
            totalCost += nextSpending;
        }
        cout << totalCost << endl;
        cin >> spendings;
    }
    return 0;
}