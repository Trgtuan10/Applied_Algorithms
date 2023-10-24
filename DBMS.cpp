#include<iostream>

using namespace std;

int n,l;
string s;

void solve(){
    cin >> n >> l;
    for(int i=0; i<n; i++){
        cin >> s; 
        int len = s.size();
        for(int j=1; j<=l-len; j++){
            cout << '0';
        }
        cout << s << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}