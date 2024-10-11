// https://codeforces.com/gym/104639/problem/L

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

inline int rd(){
    int x = 0;
    bool f = 0;
    char c = getchar();
    for(;!isdigit(c);c = getchar()) f |= ( c == '-' );
    for(;isdigit(c) ;c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x ;
}

#define rep(i, a, b) for(int i = (a) ; i <= (b) ; ++i)
#define pre(i, a, b) for(int i = (a) ; i >= (b) ; ++i)

#define eb emplace_back
#define all(a) (a).begin(), (a).end()

inline int work(){
    int n = rd();
    double m = rd();
    int max_n = 0;
    rep(i, 1, n) max_n = max(rd(), max_n);
    return max(2, int(ceil(max_n/m))); 
}

int main(){
    printf("%d\n", work());
}