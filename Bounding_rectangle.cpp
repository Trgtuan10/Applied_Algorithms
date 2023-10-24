#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n; 
    cin >> n;

    int x_max = -1,  x_min = 101, y_max = -1, y_min = 101; 

    int a,b; 
    while(n--){
        cin >> a >> b; 
        x_max = max(x_max, a);
        x_min = min(x_min, a);
        y_max = max(y_max, b);
        y_min = min(y_min, b);

        cin >> a >> b; 
        x_max = max(x_max, a);
        x_min = min(x_min, a);
        y_max = max(y_max, b);
        y_min = min(y_min, b);
    }

    cout << (x_max - x_min) * (y_max - y_min);
    return 0;
}