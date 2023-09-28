#include<bits/stdc++.h>

using namespace std; 

const int MAX = 1e5 + 1;
int n,m;
vector<int> edge[MAX];
bool vis[MAX];


void input(){
    cin >> n >> m;
    int a,b; 
    for(int i = 1; i<=m; i++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}

int solve(){
    int count = 0;
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        count++;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int &u : edge[x]){
                if(!vis[u]){
                    q.push(u);
                    vis[u] = true;
                }
            }
        }
    }
    return count;
}

int main(){
    input();
    cout << solve();
    return 0;
}
