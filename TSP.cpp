#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 21; // Maximum number of nodes
int n;
int a[MAX_N][MAX_N];
bool check[MAX_N] = {false};
int res;
int travel[MAX_N];
int cur;
int shortest;

void input() {
    cin >> n;
    shortest = INT_MAX; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i != j) shortest = min(a[i][j], shortest);
        }
    }
    res = INT_MAX; 
    cur = 0;
    travel[1] = 1;
}

void Try(int k) {
    for (int i = 2; i <= n; i++) {
        if (!check[i]) {
            check[i] = true;
            travel[k] = i;
            cur += a[travel[k - 1]][i];
            // cout << "@" << cur<<"@"  ;
            if (k == n) {
                cur += a[travel[n]][travel[1]]; /
                res = min(res, cur);
                cur -= a[travel[n]][travel[1]];
                // cout << cur << "---";
                // for (int i = 1; i <= n; i++) cout << travel[i] << " ";
                // cout << endl;
            } else if (cur + (n - k + 1) * shortest < res) {
                Try(k + 1);
            }
            check[i] = false;
            cur -= a[travel[k - 1]][i];
        }
    }
}

int main() {
    input();
    Try(2);
    cout << res;
    return 0;
}
