#include <stdio.h>

int main(){
    int n, d1, d2, x, y;
    scanf("%d", &n);
    while(n != 0){
        scanf("%d %d", &d1, &d2);
        int i;
        for(i = 0; i<n; i++){
            scanf("%d %d", &x, &y);
            if(x == d1 || y == d2){
                printf("%s\n", "divisa");
            } else if(x < d1){
                if(y > d2){
                    printf("%s\n", "NO");
                } else {
                    printf("%s\n", "SO");
                }
            } else {
                if(y > d2){
                    printf("%s\n", "NE");
                } else {
                    printf("%s\n", "SE");
                }
            }
        }
        scanf("%d", &n);
    }
    return 0;
}