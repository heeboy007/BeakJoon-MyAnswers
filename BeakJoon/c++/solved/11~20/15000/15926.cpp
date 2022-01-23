#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, max_length = 0, just_finished_with = 0;
    string pvhs;
    stack<pair<int, int>> vhs_measure;
    cin >> n >> pvhs;

    for(int i = 0; i < n; i++){
        if(pvhs[i] == '('){
            pair<int, int> input;
            input.first = i;
            input.second = just_finished_with;
            vhs_measure.push(input);
            just_finished_with = 0;
        } else { //pvhs[i] == ')'
            just_finished_with = 0;
            if(!vhs_measure.empty()){
                just_finished_with = i - vhs_measure.top().first + 1 + vhs_measure.top().second;
                max_length = max(max_length, just_finished_with);
                vhs_measure.pop();
            }
        }
    }

    cout << max_length;

    return 0;
}