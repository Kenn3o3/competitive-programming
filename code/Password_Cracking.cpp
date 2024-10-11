//https://codeforces.com/contest/2013/problem/C

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vl;

const int MAX = 200007;
const ll INF = 1e18;

#define fast_io                       \
    ios::sync_with_stdio(false);      \
    cin.tie(0);                        \
    cout.tie(0)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define repn(i, a, b) for(int i = a; i < b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << '\n'
#else
#define debug(x)
#endif

bool ask(string t){
    cout << "? " << t << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void result(string s){
    cout << "! " << s << endl;
    cout.flush();
}

inline void solve(){
    int n;
    cin >> n;
    string cur;
    while (cur.size() < n){ // expand right
        if(ask(cur+"0")){
            cur += "0";
        } else if(ask(cur+"1")){
            cur += "1";
        } else {
            break;
        }
    }
    while(cur.size() < n){ //expand left
        if(ask("0"+cur)){
            cur = "0" + cur;
        } else {
            cur = "1" + cur;
        }
    }
    result(cur);
}

int main(){
    fast_io;
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}