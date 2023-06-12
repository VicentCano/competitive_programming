
#include<stdio.h>

using namespace std;

int main(){
    int n, count, maxc, i, j;
    while(scanf("%d %d", &i, &j) != EOF){
        maxc = 0;
        int i1 = i, j1 = j;
        if(i > j){
            j1 = i;
            i1 = j;
        }
        for(int k = i1; k<=j1; k++){
            n = k;
            count = 1;
            while(n != 1){
                if(n%2 == 1){
                    n = 3*n +1;
                } else {
                    n = n/2;
                }
                count ++;
            }
            if(count > maxc) maxc = count;
        }
        printf("%d %d %d\n", i, j, maxc);  
    }
    return 0;
}

