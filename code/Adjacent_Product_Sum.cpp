// https://codeforces.com/gym/104197/problem/A

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline int rd(){
    int  x =0;
    bool f =0;
    char c = getchar();
    for(; !isdigit(c); c = getchar()) f |= ( c == '-' );
    for(; isdigit(c) ; c = getchar()) x  = x * 10 + ( c ^ 48 );
    return f ? -x : x;
}

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for(int i = (a); i   < (b); ++i)
#define per(i, a, b) for(int i = (a); i   > (b); --i)

vector<int> s;

deque<int> d;

inline void work(){
    s.clear();
    d.clear();
    int n = rd();
    rep(i,0,n) s.eb(rd());
    sort(all(s));
    bool fl = false;
    for(auto x: s){
        if(fl) d.push_front(x);
        else d.push_back(x);
        fl = 1-fl;
    }
    ll ans = 0;
    rep(i,0,n) ans += 1ll*d[i]*d[(i+1)%n];
    printf("%lld\n", ans);
}

int main(){
    per(t,rd(),0) work();
    return 0;
}
