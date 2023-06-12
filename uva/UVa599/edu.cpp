#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
        
bool visited[27];

vector<vector<int>> graph(27);

void dfs(int i) {
    
    visited[i] = true;

    for(int adj: graph[i]) {
        if(!visited[adj]) dfs(adj);
    }
}

int main() {

    int t, trees, acorns;
    cin >> t;
    cin.ignore();

    string line;

    char a, b;
    int c, d;

    while(t--) {
        
        memset(visited, false, sizeof(visited));
        
        fori(i, 27) graph[i].clear();
        
        while(getline(cin, line)) {
            if(line[0] == '*') break;
            sscanf(line.c_str(), "(%c,%c)", &a, &b); 
            c = a - 'A';
            d = b - 'A';
            graph[c].pb(d);
            graph[d].pb(c);
        }    

        getline(cin, line);

        fori(i, line.length()) {
            if(i % 2 == 0) {
                c = line[i] - 'A';
                if(graph[c].size() == 0) graph[c].pb(-1);
            }
        } 
        
        trees = acorns = 0;

        fori(i, 27) {
            if(!visited[i]) {
                if(graph[i].size() == 0) {
                    continue;
                } else if(graph[i].size() == 1) {
                    if(graph[i][0] == -1) {
                        ++acorns;
                        visited[i] = true;
                    } else {
                        dfs(i);
                        ++trees;
                    }
                } else {
                    dfs(i); 
                    ++trees;
                }
            }
        }        
        
        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
    }

    return 0;
}