#include<iostream>
#include<cmath>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    while(n != 0){
        int a = 0, b = 0;
        bool ia = true;
        for(int i = 0; n > 0; i++){
            int one = 1, bit;
            bit = n & one;
            if(bit != 0){
                if(ia){
                    a += pow(2, i);
                } else {
                    b += pow(2, i);
                }
                ia = !ia;
            }
            n = n >> 1;
        }
        cout << a << " " << b << endl;
        cin >> n;
    }
    
    return 0;
}