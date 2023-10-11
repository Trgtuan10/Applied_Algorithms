#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5; // Sử dụng kiểu int cho kích thước mảng

int n, m, s, t;
int dis[MAXN][MAXN];
int best[MAXN];
bool check[MAXN];

void input() {
    cin >> n >> m;
    int u, v, w;
    while(m--) {
        cin >> u >> v >> w;
        dis[u][v] = w;
        dis[v][u] = w; // Nếu đồ thị vô hướng, bạn nên cập nhật cả hai chiều
    }
    cin >> s >> t;
}

void Dijkstra() {
    cout << n << m;
}

int main() {
    input();
    Dijkstra();
    return 0;
}
