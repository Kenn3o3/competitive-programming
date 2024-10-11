// https://codeforces.com/gym/104197/problem/E

#include <bits/stdc++.h>

typedef long long ll;

inline int rd(){
    int x = 0;
    bool f = 0;
    char c = getchar();
    for( ; !isdigit(c) ; c = getchar()) f |= ( c == '-' );
    for( ; isdigit(c) ; c = getchar()) x = x * 10 + ( c ^ 48 );
    return f ? -x : x ;
}

#define eb emplace_back
#define all(a) (a).begin(), (a).end()

#define rep(a,b,c) for(int a = (b) ; a < (c) ; ++a )
#define per(a,b,c) for(int a = (b) ; a > (c) ; --a )

#define MAXN 200007

int s[MAXN];

int res;

inline void work(){
    
    int n = rd();
    res = 0;
    rep(i, 0, n) {
        s[i] = rd();
        res ^= s[i];
    }
    //if XOR of all elements = 0, then cannot divide into two sets since set A XOR set B = 0, set A and B must have same XOR
    if( res != 0 ) { puts("YES"); puts("2"); puts("1 1"); printf("%d %d\n", 2, n); return; }
    //else- find the first non-zero element and then the first a | b | c
    int fnz = -1;
    rep(i, 0, n){ if( s[i] != 0 ) {fnz = i; break;} }
    if( fnz == -1 ) { puts("NO"); return; }
    int l = 0;
    rep(i, fnz+1 , n-1){
        l ^= s[i]; 
        if( l !=0 && l != s[fnz] ){ 
            puts("YES"); puts("3"); 
            printf("%d %d\n", 1, fnz+1); 
            printf("%d %d\n", fnz+2, i+1); 
            printf("%d %d\n", i+2, n); 
            return;
        } 
    }
    puts("NO"); 
    return;
}

int main(){
    per(tc, rd(), 0) work();
}