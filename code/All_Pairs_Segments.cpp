//https://codeforces.com/contest/2019/problem/B

#include <bits/stdc++.h>

using namespace std;
#define ll long long 

inline ll rll(){
    ll x = 0;
    bool f = 0;
    char c = getchar();
    for(;!isdigit(c);c = getchar()) f |= ( c == '-' );
    for(;isdigit(c) ;c = getchar()) x = x * 10 + ( c ^ 48 );
    return f ? -x : x ;
}

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

inline void work(){
    int n = rd(), q = rd();
    vector<ll> x(n);
    for(auto &num: x) num = rll();
    unordered_map<ll, ll> freqs_map;
    rep(i,1,n){
        ll cp = 1ll * i * (n-i+1) - 1;
        freqs_map[cp]++;
        if(i<n){
            ll gap = x[i]-x[i-1]-1;
            if(gap>0){
                ll cb = 1ll * i * (n-i);
                freqs_map[cb]+=gap;
            }
        }
    }     
    rep(i,1,q){
        ll k = rll();
        if(freqs_map.find(k)!=freqs_map.end()){
            printf("%lld ", freqs_map[k]);
        } else {
            printf("0 ");
        }
    }
    printf("\n");
    freqs_map.clear();
    x.clear();
}
int main(){
    per(i,rd(),1) work();
}