#include <bits/stdc++.h>

using namespace std;

vector<string> day;
unordered_map<string, int> k;

int to_second(string st) {
    return (st[0] - '0') * 36000 + (st[1] - '0') * 3600 + (st[3] - '0') * 600 + (st[4] - '0') * 60 + (st[6] - '0') * 10 + (st[7] - '0');
}

int find_index(string s) {
    auto a = k.find(s);
    return a->second;
}

void convert_time(int x){
    if(x < 10) cout << "0" << x;
    else cout << x;
}

void solve(string s, string ti, int dur) {
    int u = to_second(ti) + dur;
    int id = find_index(s);
    id += u / (24 * 60 * 60);
    u = u % (24 * 60 * 60);
    int hour = u / 3600;
    int minutes = (u % 3600) / 60;
    int sec = u % 60;
    
    cout << day[id] << " ";
    convert_time(hour);
    cout << ":";
    convert_time(minutes);
    cout << ":";
    convert_time(sec);
    cout << endl;
}

int main() {
    freopen("z.inp", "r", stdin); 
    string cmd, ti;
    int dur;
    int i = 0;
    while (cin >> cmd) {
        if (cmd == "*") break;
        day.push_back(cmd);
        k.insert(make_pair(cmd, i++));
    }

    while (cin >> cmd) {
        if (cmd == "***") break;
        cin >> ti >> dur;
        solve(cmd, ti, dur);
    }

    return 0;
}
