#include<bits/stdc++.h>

using namespace std;

int total_calls = 0;
int incorrect_call_num = 0;

map<string, int> call_time, call_num;
 
int is_correct_phone(string tel){
    if(tel.length() != 10) return 0;
    for(int i=0; i< tel.length(); i++){
        if(tel[i] < '0' || tel[i] > '9') return 0;
    }
    return 1;
}

 

int duration(string st, string et){

    int stime = (st[0]*10+st[1])*3600 + (st[3]*10+st[4])*60 + st[6]*10 + st[7];

    int etime = (et[0]*10+et[1])*3600 + (et[3]*10+et[4])*60 + et[6]*10 + et[7];

    return etime - stime;

}

 

void input(){

    string type, from_tel, to_tel, date, start_time, end_time;

    do{

        cin >> type;

        if(type == "#") continue;

        cin >> from_tel >> to_tel >> date >> start_time >> end_time;

 

        if(!is_correct_phone(from_tel) || !is_correct_phone(to_tel)){

            incorrect_call_num++;

        }
        else{

            total_calls++;
        }

        call_num[from_tel]++;

        call_time[from_tel] += duration(start_time, end_time);

 

    } while(type != "#");

}

 

void solve(){

    string type, tel;

    do{

        cin >> type;

        if(type == "#") continue;

        if(type == "?check_phone_number"){

            if(incorrect_call_num > 0) cout << "0" << endl;
            else cout << "1" << endl;
        }

        if(type == "?number_calls_from"){

            cin >> tel;

            cout << call_num[tel] << endl;

        }

        if(type == "?number_total_calls"){

            cout << total_calls << endl;

        }

        if(type == "?count_time_calls_from"){

            cin >> tel;

            cout << call_time[tel] << endl;

        }

    } while(type != "#");

}

 

int main(){

    // freopen("z.inp", "r", stdin);
    // freopen("z.out", "w", stdout);

    ios_base :: sync_with_stdio(0);

    cin.tie(0); cout.tie(0);

 

    input();

    solve();

    return 0;

}