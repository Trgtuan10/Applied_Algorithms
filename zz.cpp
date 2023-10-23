#include<bits/stdc++.h>

using namespace std; 

int n,m;
int x[1000];
int a[1000];
int c=0;
int cur = 0;

void input(){
    cin >> n >> m; 
    for(int i=1; i<=n; i++){
        cin >> x[i];
    }
}

void Try(int k){
    for(int i=1; i<= (m-cur)/x[k]; i++){
        a[k] = i;
        cur += x[k]*i; 
        if(k == n){
            if(cur == m){
                c++;
            }
        } 
        else Try(k+1);
        cur -= x[k]*i;
    }
}

int main(){
    input();
    Try(1);
    cout << c;
    return 0;
}