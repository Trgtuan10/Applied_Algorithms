#include<bits/stdc++.h>

using namespace std;

const int MAXN = 31; 

int m,n; 
int x[31]; 
vector<int> T[MAXN];       // teachers can teach n_th course
int load[MAXN];

int conflicts_num; 
bool conflict[MAXN][MAXN];

int res = 100;

void input(){
    cin >> m >> n; 
    for(int i=1; i <= m; i++){
        int num, course; 
        cin >> num; 
        for(int j=1; j<=num; j++){ 
            cin >> course; 
            T[course].push_back(i);
        }
    }

    cin >> conflicts_num; 
    int a,b;
    for(int i=1; i<=conflicts_num; i++){
        cin >> a >> b; 
        conflict[a][b] = true;
        conflict[b][a] = true;
    }
}

bool check(int t, int k){
    for(int i = 1; i < k; i++){
        if(x[i] == t && conflict[k][i]) return false;
    }
    return true;
}

void update_result(){
    int max_load = -1;
    for(int i=1; i<=m; i++){
        max_load = max(max_load, load[i]);
    }
    res = min(res, max_load);
}

void Try(int k){
    // cout << k << " ";
    for(int i=0; i< T[k].size(); i++){
        int t = T[k][i];
        if(check(t, k)){
            // cout << check(t,k) << endl;
            x[k] = t;
            load[t] += 1;
            if(k == n) update_result();
            else if(load[t] < res){
                Try(k+1);
            }
            load[t]--;
        }
    }
}

int main(){
    freopen("z.inp", "r", stdin);
    freopen("z.out", "w", stdout);

    input();
    Try(1);
    cout << res; 
    return 0;
}