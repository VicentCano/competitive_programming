#include<stdio.h>
#include <vector>
#include <queue> 
#include <cmath>

using namespace std;

int main() {
    while(true){
        int r, c;
        scanf("%d %d", &r, &c);
        //printf("Rows:%d Columns:%d\n", r, c);
        if(r == 0) break;
        int br;
        scanf("%d", &br);
        //printf("Number of rows:%d\n", br);

        vector<vector<bool>> visited (r,
                    vector<bool>(c, false));
        
        //vector<int> rwb;

        for(int i = 0; i < br; i++){
            int l0;
            scanf("%d", &l0);
            int l1;
            scanf("%d", &l1);
            //printf("Number of bombs in row %d: %d\n", l0, l1);
            int lt;
            //printf("Row %d:", l0);
            for(int j = 0; j < l1; j++){
                scanf("%d", &lt);
                
                //printf(" c: %d", lt);
                visited[l0][lt] = true;
            }
            //printf("\n");
        }
        int sr, sc, fr, fc;
        scanf("%d %d", &sr, &sc);
        scanf("%d %d", &fr, &fc);
        //printf("Starting position:%d %d\n", sx, sy);
        //printf("Final position:%d %d\n", fx, fy);
        if(sr == fr && sc == fc){
            printf("%d\n", 0);
            continue;
        } else if(br == 0){
            printf("%d\n", abs(fr - sr) + abs(fc - sc)); 
            continue;
        }

        queue<pair<pair<int, int>,int>> q;
        q.push(make_pair(make_pair(sr, sc),0));
        pair<pair<int, int>,int> u;
        visited[sr][sc] = true;
        int sd, sd1;
        while(!q.empty()){
            
            u = q.front();
            q.pop();
            sd = u.second;
            sd1 = sd + 1;
            pair<int, int> coords = u.first; 
            //printf("s(%d %d)\n", coords.first, coords.second);
            if(coords.first > 0 && !visited[coords.first-1][coords.second]){
                if(coords.first - 1 == fr && coords.second == fc){
                    sd++;
                    //printf("Test1\n");
                    break;
                }
                visited[coords.first-1][coords.second] = true;
                //printf("a(%d, %d, %d)\n", coords.first - 1, coords.second, sd1);
                q.push(make_pair(make_pair(coords.first - 1, coords.second), sd1));
            }
            if(coords.second > 0 && !visited[coords.first][coords.second-1]){
                if(coords.first == fr && coords.second - 1 == fc){
                    sd++;
                    //printf("Test2\n");
                    break;
                }
                visited[coords.first][coords.second-1] = true;
                //printf("b(%d, %d, %d)\n", coords.first, coords.second - 1, sd1);
                q.push(make_pair(make_pair(coords.first, coords.second - 1), sd1));
            }
            if(coords.second < c - 1 && !visited[coords.first][coords.second+1]){
                if(coords.first == fr && coords.second + 1 == fc){
                    sd++;
                    //printf("Test3\n");
                    break;
                }
                visited[coords.first][coords.second+1] =  true;
                //printf("c(%d, %d, %d)\n", coords.first, coords.second + 1, sd1);
                q.push(make_pair(make_pair(coords.first, coords.second + 1), sd1));
            }
            if(coords.first < r - 1 && !visited[coords.first + 1][coords.second]){
                if(coords.first + 1 == fr && coords.second == fc){
                    sd++;
                    //printf("Test4\n");
                    break;
                }
                visited[coords.first + 1][coords.second] = true;
                //printf("d(%d, %d, %d)\n", coords.first + 1, coords.second, sd1);
                q.push(make_pair(make_pair(coords.first + 1, coords.second),sd1));
            }
            //for(int a = 0; a<r; a++){
            //    for(int b = 0; b<c; b++){
            //        printf("%d ", visited[a][b] ? 1 : 0);
            //    }
            //    printf("\n");
            //}
        }
        printf("%d\n", sd);
    
    }
    return 0;
}