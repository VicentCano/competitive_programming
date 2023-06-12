#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int v1, v2;
        if(n == 1){
            printf("Jolly\n");
            scanf("%d", &v1);
        } else {
            int a [n];
            scanf("%d", &v1);
            for(int i = 0; i<n-1; i++){
                scanf("%d", &v2);
                int d = v1 - v2;
                a[i] = d>0?d:-d;
                v1 = v2;
            }
            sort(a, a + (n-1));
            bool j = true;
            for(int i = 1; i<n; i++){
                if(i != a[i-1]) j =  false;
            }
            if(j){
                printf("Jolly\n");
            } else {
                printf("Not jolly\n");
            }
        }
    }
    return 0;
}