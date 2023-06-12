#include<stdio.h>

using namespace std;

int main(){
    long long int a, b;
    while(scanf("%lld %lld", &a, &b) != EOF){
        if(a>b){
            long long int aux = a;
            a = b;
            b = aux;
        }
        printf("%lld\n", b-a);
    } 
    return 0;
}