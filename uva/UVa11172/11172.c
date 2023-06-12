#include<stdio.h>

int main(){
    int n, a, b;
    scanf("%d", &n);
    int i;
    for(i =0; i<n; i++){
        scanf("%d %d", &a, &b);
        if(a < b){
            printf("%s\n", "<");
        } else if (a > b) {
            printf("%s\n", ">");
        } else {
            printf("%s\n", "=");
        }
    }
    return 0;
}