#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 1;
const int MOD = 1e9 + 7;

int n;
int a[MAX];

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

int merge(int n, int a[], int left, int mid, int right){
    if(left == right) return 0;
    long long count = 0;
    int temp[n];
    int first1 = left;
    int first2 = mid;
    
    int i = 0;

    while(first1 <= mid - 1 && first2 <= right){
        if(a[first1] <= a[first2]){
            temp[i] = a[first1];
            first1++;
        }
        else{
            temp[i] = a[first2];
            first2++;
            count += (mid - first1) % MOD;
        }
        i++;
    }

    if(first1 == mid){
        for(int j = first2; j <= right; j++) temp[i++] = a[j];
    }
    else{
        for(int j = first1; j <= mid - 1; j++) temp[i++] = a[j];
    }

    int j = 0;
    for(int k = left; k <= right; k++){
        a[k] = temp[j];
        j++;
    }

    return count % MOD;
}

int inversion(int n, int a[], int left, int right){
    long long count = 0;

    if(left < right){
        int mid = (left + right) / 2;
        count += inversion(n, a, left, mid) % MOD;
        count += inversion(n, a, mid + 1, right) % MOD;
        count += merge(n, a, left, mid + 1, right) % MOD;
    }

    return count % MOD;
}

int main(){

    freopen("z.inp", "r", stdin);
    freopen("z.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    cout << inversion(n, a, 0, n - 1);


    return 0;
}
