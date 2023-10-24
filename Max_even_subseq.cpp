#include<bits/stdc++.h>

using namespace std; 

typedef ll long long;
const ll MAXN = 1e6+1;

int n;
ll res; 
int a[MAXN];
ll even[MAXN];    // max sum sub sequence end by i and even
ll odd[MAXN];     // max sum sub sequence end by i and odd

void input(){
    cin >> n; 
    for(int i=1; i<=n; i++) cin >> a[i];
    res = -MAXN;
    even[0] = -MAXN;
    odd[0] = -MAXN;
}

void solve(){
    for(int i=1; i<=n; i++){
        if(a[i] % 2 == 0){
            odd[i] = odd[i-1] + a[i];
            even[i] = max(a[i], a[i] + even[i-1]);
        }

        else{
            odd[i] = max(a[i], a[i] + even[i-1]);
            even[i] = a[i] + odd[i-1];
        }
        res = max(res, even[i]);
    }
}

int main(){
    input();
    solve();
    cout << res; 
}