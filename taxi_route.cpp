#include<bits/stdc++.h>

using namespace std;

const int MAXN = 12; 
int n; 
int c[2*MAXN][2*MAXN];
bool check[MAXN];

int count_pass = 0;
int res = INT_MAX; // Initialize with a large value
int total_dist = 0;
int min_dist = INT_MAX; // Initialize with a large value

void input(){
    cin >> n; 
    for(int i=0; i<=2*n; i++){
        for(int j=0; j<=2*n; j++){
            cin >> c[i][j]; 
            if(i != j) min_dist = min(min_dist, c[i][j]);
        }
    }
}

void Try(int k){
    total_dist += c[k][k+n];
    check[k] = true;
    count_pass++;
    if(count_pass == n){
        total_dist += c[k+n][0];
        res = min(res, total_dist);
        total_dist -= c[k+n][0];
    }
    else if(total_dist + 2*(n-count_pass)*min_dist < res){
        for(int i=1; i<=n; i++){
            if(!check[i]){
                total_dist += c[k+n][i];
                Try(i); 
                total_dist -= c[k+n][i];
            }
        }
    }
    total_dist -= c[k][k+n];
    count_pass --;
    check[k] = false;
}

int main(){
    input();
    for(int i=1; i<=n; i++){
        count_pass = 0;
        total_dist += c[0][i];
        Try(i);
        total_dist -= c[0][i];
    }
    cout << res << endl;
    return 0;
}
