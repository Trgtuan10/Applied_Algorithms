#include<bits/stdc++.h>

using namespace std; 

const int MAXN = 1e5 + 1;
int n,c;
int t; 
int x[MAXN];
int choose[MAXN];

void input(){
    cin >> n >> c;
    for(int i=0; i<n; i++) cin >> x[i];
    sort(x , x + n );
}

bool check(int k){
    int last = x[0]; 
    int count = 1;
    for(int i=1; i<n; i++){
        if(x[i] - last >= k){
            count++;
            last = x[i];
        }
        if(count = c) return true;
    }
    return false;
}

int solve(){
    int low = 0;
    int high = x[n-1] - x[0];
    int mid = (low + high)/2; 
    if(check(mid)){
        low = mid;
    }
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t; 
    while(t--){
        input();
        
    }
    return 0;
}
    