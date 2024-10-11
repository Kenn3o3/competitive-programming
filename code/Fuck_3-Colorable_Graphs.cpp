// https://codeforces.com/gym/104197/problem/F


#include <bits/stdc++.h>

using namespace std;

inline int rd(){
    int  x = 0;
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)){
        x = x * 10 + (c ^ 48);
        c = getchar();
    }
    return x;
}

#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rep(i, a, b) for(int i = (a) ; i <= (b) ; ++i)
#define per(i, a, b) for(int i = (a) ; i >= (b) ; --i)

#define MAXN 20007
int n, m;
vector<int> edges_part1[MAXN];
vector<int> edges_part2[MAXN];

inline int work(){
    n = rd();
    m = rd();
    rep(i,1,m){
        int u = rd(), v = rd();
        edges_part1[u].eb(v); 
        edges_part2[v].eb(u);
    }
    vector<int> count_nodes(2*n+2, 0);
    vector<int> updated;
    rep(v,1,n){
        updated.clear();
        for(auto u: edges_part1[v]){
            for(auto w: edges_part2[u]){
                if(w == v) continue;
                if(count_nodes[w] == 0){
                    updated.eb(w);
                }
                count_nodes[w]++;
                if(count_nodes[w] >=2){
                    return 2;
                }
            }
        }
        for(auto w: updated){
            count_nodes[w] =0;
        }
    }
    return 3;
}

int main(){
    printf("%d", work());
}