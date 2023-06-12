#include<stdio.h>

int main(){
    int c, n, cs, ms;
    scanf("%d", &c);
    int i;
    for(i = 0; i<c; i++){
        ms = 0;
        scanf("%d", &n);
        int j;
        for(j = 0; j<n; j++){
            scanf("%d", &cs);
            if(cs > ms) ms = cs;
        }
        printf("Case %d: %d\n", i+1, ms);
    }
    return 0;
}