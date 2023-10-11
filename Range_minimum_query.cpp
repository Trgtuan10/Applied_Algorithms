#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e6+1;

int m,n;
int a[MAX];
int M[23][MAX];


void precompute(){
    for(int j=0; (1<<j) <=n; j++){
        for(int i=0; i <n; i++){
            M[j][i] = -1;
            // cout << "a";
        }
    }
    for(int i=0; i<n; i++){
        M[0][i] = a[i];
    }
    for(int j=1; (1 << j) <= n; j++){
        for(int i=0; i+ (1 << j) -1 <= n; i++){
            M[j][i] = min(M[j-1][i], M[j-1][i + (1 << (j-1))]);
        }
    }
}

int rmq(int i, int j){
    int l = log2(j-i+1);
    return min(M[l][i], M[l][j - (1<<l) + 1]);
}

int main(){
    // freopen("z.inp", "r", stdin);
    // freopen("z.out", "w", stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n ;
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> m;
    int sum = 0;

    precompute();
    // for(int j=0; (1<<j) <n; j++){
    //     for(int i=0; i <n; i++){
    //         cout << i <<" "<< i+ (1<<j) <<":";
    //         cout << M[j][i] << endl ;
    //     }
    //     cout << "================" << endl;
    // }
    while(m--){
        int a,b;
        cin >> a >> b;
        sum += rmq(a,b);
        // cout << rmq(a,b);
    }
    cout << sum;
    return 0;
}