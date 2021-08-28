#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> check;
vector<int> seq;

bool bin_search(int index, int end, int until){
    if(index >= end){
        for(int node : check)
            if(node == until)
                return true;
        if(until)
            check.push_back(until);
        return false;
    }
    return bin_search(++index, end, until + seq[index]) || bin_search(++index, end, until);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int length;
        seq.clear();
        check.clear();

        cin >> length;
        for(int i = 0; i < length; i++){
            int input;
            cin >> input;
            seq.push_back(abs(input));
        }
        
        sort(seq.begin(), seq.end());

        bool result = false;
        for(int i = 1; i < length; i++){
            if(seq[i] == seq[i - 1])
                result = true;
        }

        if(!result){
            result = bin_search(0, length, 0);
        }

        cout << (result ? "YES\n" : "NO\n");
    }

    return 0;
}