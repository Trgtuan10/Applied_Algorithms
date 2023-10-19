#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
int n;
int cur = 0;
int a[51];
int c = 0;


void input() {
    cin >> n;
    a[0] = 1;
}

void Try(int k) {
    for (int i = a[k - 1]; i <= n - cur ; i++) {
        // cout << k << " " <<i << endl;
        a[k] = i;
        cur += i;
        if (cur == n) {
            c = (c + 1) % MOD;
        }
        else if(k > n || cur > n) break;
        else {
            Try(k + 1);
        }
        cur -= i;
    }
}

int main() {
    input();
    Try(1);
    cout << c;
}
