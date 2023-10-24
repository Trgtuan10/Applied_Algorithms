#include<bits/stdc++.h>
using namespace std; 

int n, k; 
int a[41];
int cur = 0;

void input(){
    cin >> k >> n; 
    a[0] = 1;
}

void Ghinhan(){
    for(int i=1; i<=k; i++) cout << a[i] << " ";
    cout << endl;
}

void Try(int x){
    // cout << x << endl;
    for(int i = a[x-1]; i<= n - cur; i++){
        a[x] = i;
        cur += i;
        if(x == k){
            if(cur == n) Ghinhan();
        }
        else{
            Try(x+1);
        }
        cur -= i;
    }
}

int main(){
    input();
    Try(1);
    return 0;
}