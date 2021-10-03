#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ostringstream maybe;
    vector<int> inputs;
    int n;
    int p;
    bool is_everything_zero = true;

    cin >> n >> p;
    int prev = 0, curr = p;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        if(input)
            is_everything_zero = false;
        inputs.push_back(input);
    }
    
    for(int i = 0; i < n; i++){
        if(prev > inputs[i])
            curr--;
        prev = inputs[i];
        maybe << curr; 
        maybe << '\n';
    }

    //cout << curr << '\n';
    if(is_everything_zero){
        for(int i = 0; i < n; i++)
            cout << "0\n";
    } else if(curr == 1){
        if(inputs[inputs.size() - 1] == 0)
            cout << "ambiguous\n";
        else
            cout << maybe.str();
    } else if(curr == 0){
        cout << maybe.str();
    } else {
        cout << "ambiguous\n";
    }

    return 0;
}