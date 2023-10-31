#include<bits/stdc++.h>

using namespace std; 

int n,m;
int x[10001];
int y[10001];

int lcs[10001][10001];

void input(){
    cin >> n >> m; 
    for(int i=1; i<=n; i++){
        cin >> x[i];
        lcs[i][0] = 0;
    } 
    for(int i=1; i<=m; i++){
        cin >> y[i];
        lcs[0][i] = 0;
    }
}

void solve(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i] == y[j]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
}

int main(){
    input();
    solve();
    cout << lcs[n][m];
    
}