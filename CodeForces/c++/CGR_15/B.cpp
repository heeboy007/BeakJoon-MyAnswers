#include<iostream>
#include<vector>

using namespace std;

bool comp(int a[5], int b[5]){
    int count = 0;
    for(int i = 0; i < 5; i++){
        if(a[i] < b[i])
            count++;
    }
    return (count >= 3);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    string input, copy;
    while(t--){
        int aths, max_index;
        cin >> aths;
        int max[5] = {50001, 50001, 50001, 50001, 50001};
        vector<vector<int>> scores;
        for(int i = 0; i < aths; i++){
            int t[5];
            cin >> t[0] >> t[1] >> t[2] >> t[3] >> t[4];
            vector<int> ath_score;
            for(int j = 0; j < 5; j++)
                ath_score.push_back(t[j]);
            scores.push_back(ath_score);

            if(comp(t, max)){ //t is superior
                for(int j = 0; j < 5; j++)
                    max[j] = t[j];
                max_index = i;
            }
        }
        
        bool valid = true;
        for(vector<int> check : scores){
            int t[5];
            for(int j = 0; j < 5; j++)
                t[j] = check[j];
            if(comp(t, max)){
                valid = false;
                break;
            }
        }
        if(valid){
            cout << max_index + 1 << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}