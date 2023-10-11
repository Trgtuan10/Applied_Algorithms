#include<bits/stdc++.h>

using namespace std; 

const int MAX = 1e5;

int n,m; 
bool vis[MAX] = {false}; 
vector<int> v[MAX];

void input(){
    cin >> n >> m; 
    int a, b; 
    while(m--){
        cin >> a >> b; 
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }
}

void dfs(int x){
    if(vis[x] == false){
        cout << x << " ";
        vis[x] = true;
        for(int &c : v[x]){
            dfs(c);
        } 
    }
}

int main(){
    input();
    for(int x = 1; x<=n; x++){
        dfs(x);
    }
    return 0;
}