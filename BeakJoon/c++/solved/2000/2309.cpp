#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> tall;
    int sum = 0;
    for(int i = 0; i < 9; i++){
        int input;
        cin >> input;
        sum += input;
        tall.push_back(input);
    }

    sort(tall.begin(), tall.end());

    int skip1 = 9, skip2 = 9;
    for(int i = 0; i < 9; i++){
        for(int j = i; j < 9; j++){
            if((sum - tall[i] - tall[j]) == 100){
                skip1 = i;
                skip2 = j;
                break;
            }
        }
        if(skip1 < 9)
            break;
    }

    for(int i = 0; i < 9; i++){
        if(i == skip1 || i == skip2)
            continue;
        cout << tall[i] << '\n';
    }

    return 0;
}