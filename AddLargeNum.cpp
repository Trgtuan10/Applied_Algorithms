#include<bits/stdc++.h>

using namespace std;

string a, b;

vector<int> trans(string &x) {
    vector<int> res;
    for (char c : x) {
        res.push_back(c - '0');
    }
    return res;
}

vector<int> add(string &a, string &b) {
    vector<int> n1 = trans(a);
    vector<int> n2 = trans(b);
    vector<int> result;

    int i = n1.size() - 1;
    int j = n2.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += n1[i];
            i--;
        }
        if (j >= 0) {
            sum += n2[j];
            j--;
        }
        carry = sum / 10;
        result.push_back(sum % 10);
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    cin >> a >> b;
    vector<int> sum = add(a, b);

    
    for (int digit : sum) {
        cout << digit;
    }
    cout << endl;

    return 0;
}
