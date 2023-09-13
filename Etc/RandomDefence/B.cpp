#include<iostream>
#include<algorithm>

#define DIV 29

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string words[55];
    long long hash[55][55] = { 0 }, count = 0;
    for(int i = 0; i < n; i++)
        cin >> words[i];
    sort(words, words + n);

    for(int i = 0; i < n; i++){
        int len = words[i].length();
        long long base = DIV;
        for(int j = 0; j < len; j++){
            hash[i][j + 1] = (words[i][j] - 'a' + 1) * base + hash[i][j];
            base *= DIV;
        }
    }

    for(int i = 0; i < n; i++){
        int len = words[i].length();
        long long comp = hash[i][len];
        for(int j = 0; j < n; j++){
            if(i == j || words[j].length() < len)
                continue;
            if(comp == hash[j][len]){
                if(words[j].length() == len){ //똑같은거
                    if(i < j){
                        count++;
                        break;
                    }
                }
            } else {
                count++;
                break;
            }
        }
    }

    cout << count;

    return 0;
}