#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int add_num(string s){
    int sum = 0;
    for(char c : s){
        if('1' <= c && c <= '9'){
            sum += (int)(c - '0');
        }
    }
    return sum;
}

bool comp(string a, string b){
    if(a.length() == b.length()){
        int len_a, len_b;
        if((len_a = add_num(a)) == (len_b = add_num(b))){
            for(int i =0; i < a.length(); i++){
                if(a[i] > b[i])
                    return false;
                else if(a[i] < b[i])
                    return true;
            }
            return true;
        } else {
            return len_a < len_b;
        }
    } else {
        return a.length() < b.length();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> serial;
    int n;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        serial.push_back(input);
    }

    sort(serial.begin(), serial.end(), comp);
    for(string input : serial){
        cout << input << '\n';
    }

    return 0;
}