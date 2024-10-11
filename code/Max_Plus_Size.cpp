//https://codeforces.com/contest/2019/problem/A

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



inline void work(){
    int max_odd = 0;
    int max_even = 0;
    int num = rd();
    rep(i,1,num){
        if(i%2==1){ //odd number
            max_odd = max(max_odd, rd());
        } else {
            max_even = max(max_even,rd());
        }
    }
    if(num%2==1) printf("%d\n", max(max_odd + num/2 + 1, max_even + num/2));
    else printf("%d\n", max(max_odd + num/2, max_even + num/2));
}

int main(){
    per(i,rd(),1) work();
}

