#include<iostream>
#include<stdio.h>
#include<deque>
#include<utility>

using namespace std;


int main(){
    int n, l, c, count;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d %d", &l, &c);
        l *= 100;
        deque<int> lq;
        deque<int> rq;
        for(int i = 0; i<c; i++){
            string s;
            int cs;
            cin >> cs >> s;
            if(s == "left"){
                lq.push_back(cs);
            } else {
                rq.push_back(cs);
            }
        }
        int side = 0;
        count = 0;
        while(!(lq.empty() && rq.empty())){
            int ol = 0;
            if(side == 0){
                while(!lq.empty() && ol + lq.front() <= l){
                    ol += lq.front();
                    lq.pop_front();
                }
                side = 1;
            } else {
                while(!rq.empty() && ol + rq.front() <= l){
                    ol += rq.front();
                    rq.pop_front();
                }
                side = 0;
            }
            count++;
        }
        cout << count << endl;
    }
    return 0;
}