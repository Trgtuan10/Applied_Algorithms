#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
int n,m; 
int a[1001][1001];
int h[MAXN];

void input(){
    cin >> n >> m; 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
}

int sub_rectangle(){
    int R[m+2];
    int L[m+2];
    h[0] = -1;
    h[m+1] = -1;
    stack<int> s, t; 
    for(int i=1; i<=m+1; i++){
        while(!s.empty() && h[i] < h[s.top()]){
            R[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    for(int i=m; i>=0; i--){
        while(!t.empty() && h[i] < h[t.top()]){
            L[t.top()] = i;
            t.pop();
        }
        t.push(i);
    }

    int res = 0;
    for(int i=1; i<=m; i++){
        res = max(res, h[i]*(R[i]-L[i]-1));
    }
    return res;
}

void set_h(int k){
    for(int i = 1; i<=m; i++){
        if(k==n) h[i] = a[k][i];
        else if(a[k][i] == 0) h[i] = 0;
        else h[i] += 1;
    }
}

int solve(){
    int res = 0;
    for(int i=n; i>=1; i--){
        set_h(i);
        res = max(res, sub_rectangle());
    }
    return res;
}

int main(){
    freopen("z.inp", "r", stdin);
    freopen("z.out", "w", stdout);

    input();
    cout << solve() << endl;
    return 0;
}