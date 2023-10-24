#include<bits/stdc++.h>

using namespace std; 

int n; 
vector<pair<int,int>> s; 

bool cmp(pair<int,int> x, pair<int,int> y){
    if(x.second == y.second) return x.first < y.first;
    return x.second < y.second;
}

void input(){
    int a,b; 
    cin >> n; 
    while(n--){
        cin >> a >> b; 
        s.push_back(make_pair(a,b));
    }

    sort(s.begin(), s.end(), cmp);
}

int solve(){
    int last = -1; 
    int res = 0;
    pair<int,int> temp;
    for(auto &u : s){
        if(u.first > last){
            res++; 
            last = u.second;
        }
    }
    return res; 
}

int main(){
    input();
    
    cout << solve();
    return 0;
}