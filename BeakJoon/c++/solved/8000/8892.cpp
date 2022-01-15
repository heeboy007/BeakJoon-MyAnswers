#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007
#define DIV 27

bool is_pel(string s){
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

void problem(){
    vector<string> words;
    vector<vector<int>> reverse_check; 
    vector<vector<int>> hash_check;

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        string input;
        cin >> input;
        words.push_back(input);
        reverse_check.push_back(vector<int>());
        hash_check.push_back(vector<int>());
        int hash = 0, rev = 0, s = input.size();
        for(int i = 0; i < s; i ++){
            rev = (rev * DIV % MOD + (input[s - i - 1] - 'a' + 1)) % MOD;
            hash = (hash * DIV % MOD + (input[i] - 'a' + 1)) % MOD;
            reverse_check.back().emplace_back(rev);
            hash_check.back().emplace_back(hash);
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i == j)
                continue;
            string x = words[i];
            string y = words[j];
            int check = min(x.length(), y.length()) - 1;
            if(hash_check[i][check] == reverse_check[j][check]){
                string pel = x + y;
                if(is_pel(pel)){
                    cout << x << y << '\n';
                    return;
                }
            }
        }
    }
    cout << "0\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    
    cin >> t;
    while(t--){
        problem();
    }

    return 0;
}