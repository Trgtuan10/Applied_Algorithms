#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, m;
int a[MAXN];
int tree[4 * MAXN];

void build(int node, int left, int right) {
    if (left == right) {
        tree[node] = a[left];
        return;
    }
    int mid = (left + right) / 2;
    build(2 * node, left, mid);
    build(2 * node + 1, mid + 1, right);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int left, int right, int idx, int val) {
    if (left == right) {
        tree[node] = val;
        return;
    }
    int mid = (left + right) / 2;
    if (idx <= mid)
        update(2 * node, left, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, right, idx, val);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int left, int right, int ql, int qr) {
    if (ql <= left && right <= qr)
        return tree[node];
    if (qr < left || right < ql)
        return 0;
    int mid = (left + right) / 2;
    int leftMax = 0;
    int rightMax = 0;
    if (ql <= mid)
        leftMax = query(2 * node, left, mid, ql, qr);
    if (mid < qr)
        rightMax = query(2 * node + 1, mid + 1, right, ql, qr);
    return max(leftMax, rightMax);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        string action;
        cin >> action;
        if (action == "update") {
            int idx, val;
            cin >> idx >> val;
            update(1, 1, n, idx, val);
        } else if (action == "get-max") {
            int ql, qr;
            cin >> ql >> qr;
            int result = query(1, 1, n, ql, qr);
            cout << result << endl;
        }
    }

    return 0;
}
