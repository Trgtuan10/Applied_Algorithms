#include<bits/stdc++.h>

using namespace std; 

string word,text;
int word_in_text = 0;

int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin, word);
    getline(cin, text);

    int wLen = word.length();
    int tLen = text.length();

    int i = 0;
    string temp;

    while(i <= tLen - wLen){
        temp = text.substr(i, wLen);
        if(word == temp){
            word_in_text++;
            i += wLen;
        }
        else{i++;}
    }
    cout << word_in_text; 
    return 0;
}
