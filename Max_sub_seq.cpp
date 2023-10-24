#include<bits/stdc++.h>

using namespace std; 

const int MAXN = 1e6+1;
int n;
int res; 
int a[MAXN];
int t[MAXN];    // max sum sub sequence end by i 

void input(){
    cin >> n; 
    for(int i=1; i<=n; i++) cin >> a[i];
    res = -MAXN;
    t[0] = 0;
}

void solve(){
    // cout << "start";
    for(int i=1; i<=n; i++){
        // cout << i;
        t[i] = max(t[i-1] + a[i], a[i]);
        res = max(res, t[i]);
    }
}

int main(){
    input();
    solve();
    cout << res; 
}

