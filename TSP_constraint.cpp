#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
int n, k; 
int a[MAXN][MAXN];
bool check[MAXN];
vector<int> constraint[MAXN];
int route[MAXN];

void input(){
    cin >> n; 
    for(int i=1; i<=n; i++){
        cin >> route[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }

    cin >> k;
    int a, b; 
    while(k--){
        cin >> a >> b; 
        constraint[b].push_back(a);
    }
}

bool check_constraint(int x){
    if(constraint[x].size() == 0) return true;
    for(int i=0; i< constraint[x].size(); i++){
        if(check[constraint[x][i]] == false) return false;
    }
    return true;
}

int solve(){
    int res = 0;
    check[route[1]] = true;
    for(int i=2; i<=n; i++){
        // cout << check_constraint(route[i]) << " " << i << endl;
        if(check_constraint(route[i])){
            // cout << check_constraint(route[i]) << " " << i << endl;
            check[route[i]] = true;
            res += a[route[i-1]][route[i]];
        }
        else return -1;
    }
    if(!check_constraint(route[1])) return false; 
    else res += a[route[n]][route[1]];
    return res;
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    // for(int i=1; i<=n; i++){
    //     cout << check_constraint(route[i]) << " ";
    // }
    cout << solve();
}

