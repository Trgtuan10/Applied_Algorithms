#include<bits/stdc++.h>

using namespace std; 

int n, k, l;
struct node{
    string key;
    int num;
};

bool cmp(node x, node y){
    return x.num < y.num;
}

vector<node> v; 

void input(){
    cin >> n >> l >> k; 
    string s; 
    while(n--){
        cin >> s; 
        node u; 
        u.key = s;
        u.num = stoi(u);
        v.push_back(u);
    }

    sort(v.begin(), v.end(), cmp);
}

string make_string(int x, int l){
    string s = to_string(x);
    int len = l - s.length();
    while(len--){
        s = '0' + s;
    }
    return s; 
}

void solve(){
    int st = v[0];
    int count = 0;
    for(auto &x)
}

int main(){
    
}