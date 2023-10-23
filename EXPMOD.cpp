#include <bits/stdc++.h>
using namespace std;

unsigned long long expMOD(int a, unsigned long long b) {
	// return a^b mod 10^9+7
	if (b==0) return 1;
	unsigned long long c = expMOD(a, b/2);
	c = (c*c) % 1000000007;
	if (b%2 == 1) return (c*a) % 1000000007; else return c;
}

int main() {
	unsigned long long a,b;
	cin >> a >>b;
	int m = a%(1000000007);
	cout<< expMOD(m,b);
	return 0;
}
