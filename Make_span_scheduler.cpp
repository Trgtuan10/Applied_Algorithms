#include<bits/stdc++.h>
using namespace std; 

const int MAXN = 1e4 + 3;
int n, k; 
int d[MAXN];
vector<int> constraint[MAXN];
long best[MAXN];
bool check[MAXN];

void input(){
    cin >> n >> k; 
    for(int i=1; i<=n; i++){
        cin >> d[i];
    }
    int a, b; 
    while(k--){
        cin >> a >> b; 
        constraint[b].push_back(a);
    }
}

long Try(int x){
    check[x] = true;
    if(constraint[x].size() == 0) best[x] = d[x];
    else{
        long max_val = -1;
        for(int i=0; i< constraint[x].size(); i++){
            int y = constraint[x][i];
            if(check[y] == false){
                check[y] = true;
                Try(y);
            }
            max_val = max(max_val, best[y]);
        }
        best[x] = max_val + d[x];
    }
    return best[x];
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    long res = -1;
    for(int i=1; i<=n; i++){
        if(check[i] == false){
            res = max(res, Try(i));
        }
    }
    cout << res;
    return 0;
}