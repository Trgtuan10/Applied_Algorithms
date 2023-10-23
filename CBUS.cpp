#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 40;

int n, k;
int a[MAX_N][MAX_N];
int load;
bool visited[MAX_N];
int cur;
int res;
int shortest;
int travel[MAX_N];

void input() {
    cin >> n >> k;
    shortest = INT_MAX;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> a[i][j];
            if (i != j) shortest = min(a[i][j], shortest);
        }
    }
    res = INT_MAX;
    cur = 0;
    load = 0;
    travel[0] = 0;
    visited[0] = 1;
}

bool is_cand(int i) {
    if(i <= n && load == k) return false;
	if(i > n && !visited[i-n]) return false;
	if(visited[i]) return false;
	return true;
}

void Try(int x) {
    int temp = load;
    for (int i = 1; i <= 2 * n; i++) {
        if (is_cand(i)) {
            visited[i] = true;
            travel[x] = i;
            cur += a[travel[x - 1]][i];

            if (i <= n) load++;
            else load--;

            if (x == 2 * n) {
                cur += a[travel[2 * n]][travel[0]];
                res = min(res, cur);
                cur -= a[travel[2 * n]][travel[0]];
            }
            else if (cur + (2 * n - x + 1) * shortest < res) {
                Try(x + 1);
            }

            visited[i] = false;
            cur -= a[travel[x - 1]][i];
            load = temp;
        }
    }
}

int main() {
    input();
    Try(1);
    cout << res;
    return 0;
}
