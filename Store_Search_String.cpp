#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_set<string> key;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "w", stdin);
    freopen("output.txt", "r", stdout);

    string k;
    while (cin >> k) {
        if (k == "*") break;
        key.insert(k);
    }

    string cmd;
    while (cin >> cmd) {
        string x;
        if (cmd == "find") {
            cin >> x;
            cout << (key.find(x) != key.end()) << endl;
        }
        if (cmd == "insert") {
            cin >> x;
            cout << (key.insert(x).second) << endl;
        }
        if (cmd == "***") break;
    }

    return 0;
}
