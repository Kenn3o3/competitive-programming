// https://codeforces.com/problemset/problem/1366/D

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

#define rep(i,a,b) for(int i = (a); i <= (b) ; ++i)

#define MAXN 1e7+7


typedef vector<int> vi;

vi getPrimeDivisors(int v, const vi& minDiv){
    vi ans;
    int curVal = v;
    while(curVal != 1){
        if(ans.empty() || ans.back() != minDiv[curVal])
            ans.push_back(minDiv[curVal]);
        curVal /= minDiv[curVal];
    }
    return ans;
}

inline void work(){
    int n;
    cin >> n;
    vi nums(n);
    rep(i,0,n-1) cin >> nums[i];
    vi minDiv(MAXN);
    rep(i,0,MAXN - 1) minDiv[i] = i;
    rep(i,2,MAXN - 1) {
        if(minDiv[i] != i) continue;
        for(int j = i; j < MAXN; j+=i) minDiv[j] = min(minDiv[j], i);
    }
    vi d1(n), d2(n);
    rep(id, 0, n-1) {
        vi list = getPrimeDivisors(nums[id], minDiv);
        if(list.size() < 2){
            d1[id] = -1;
            d2[id] = -1;
        } else {
            d1[id] = list[0];
            list.erase(list.begin());
            d2[id] = accumulate(list.begin(), list.end(), 1, multiplies<int>());
        }
    }
    for(int num : d1){
        cout << num << " ";
    }
    cout << endl;
    for(int num : d2){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    work();
}


