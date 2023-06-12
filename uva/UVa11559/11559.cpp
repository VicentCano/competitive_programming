#include<iostream>
#include<stdio.h>
using namespace std;

int main (){
    int n, b, h, w, a;
    double p, tp, mp;

    while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF){
        mp = -1;
        for(int i = 0; i < h; i++){
            scanf("%lf", &p);
            for(int j = 0; j<w;j++){
                scanf("%d", &a);
                if(a >= n){
                    tp = n * p;
                    if(tp <= b && (mp == -1 || mp > tp)) mp = tp;
                }
            }
        }
        if (mp==-1){
            printf("%s\n", "stay home");
        } else {
            printf("%.0lf\n", mp);
        }

    }
    
    return 0;
}


