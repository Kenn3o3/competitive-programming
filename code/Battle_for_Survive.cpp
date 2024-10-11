//https://codeforces.com/contest/2013/problem/B

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

#define N 200007
#define ll long long

int F[N];
int S[N];

inline void work(){
    int n = rd();
    F[0] = 0;
    F[1] = rd();
    rep(i,2,n){ 
        F[i] = rd();
    }
    ll cum = F[n-1];
    per(i, n-2, 1){ cum -= F[i];}
    printf("%lld\n", F[n] - cum);
}

int main(){
    per(i,rd(),1) work();
}
