#include<bits/stdc++.h>

using namespace std; 

const int MAXN = 1e6+1; 
int n, k;
int a[MAXN];
bool check[MAXN];

void Ghinhan(){
    for(int i=1; i<=k; i++) cout << a[i] << " ";
    cout << '\n';
}

void Try(int x){
    for(int i=a[x-1]+1; i<=n; i++){
        if(k-x > n-i) continue;
        a[x] = i; 
        if(x == k) Ghinhan();
        else{
            Try(x+1);            
        }
    }
}

int main(){
    // freopen("z.inp", "r", stdin);
    // freopen("z.out", "w", stdout);

    a[0] = 0;
    cin >> k >> n;
    Try(1);
    return 0;
}