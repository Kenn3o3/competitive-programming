//https://codeforces.com/contest/2013/problem/A
#include <bits/stdc++.h>

using namespace std;

inline int rd(){
    int x = 0;
    bool f = 0;
    char c = getchar();
    for(;!isdigit(c);c = getchar()) f |= ( c == '-' );
    for(;isdigit(c) ;c = getchar()) x = x * 10 + ( c ^ 48 );
    return f ? -x : x ;
}

#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rep(i,a,b) for(int i = (a) ; i <= (b) ; ++i)
#define per(i,a,b) for(int i = (a) ; i >= (b) ; --i)

inline void work(){
    double n = double(rd());
    int x = rd(), y = rd();
    printf("%d\n",int(ceil(n/(min(x,y)))));
    return;
}

int main(){
    per(i,rd(),1) work();
}
