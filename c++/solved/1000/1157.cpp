#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    sort(s.begin(), s.end());

    int len = s.length(), used = 0;
    char max_char = '?';
    for(int i = 0; i < len; i++){
        char curr_char = s[i];
        int start_idx = i;
        while(s[i] == curr_char)
            i++;
        if(used < i - start_idx){
            max_char = curr_char;
            used = i - start_idx;
        } else if (used == i - start_idx){
            max_char = '?';
        }
        i--;
    }

    cout << max_char;

    return 0;
}