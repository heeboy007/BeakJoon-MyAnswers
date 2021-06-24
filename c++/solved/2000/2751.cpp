#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    vector<int> numbers;
    cin >> count;

    for(int i = 0; i < count; i++){
        int input;
        cin >> input;
        numbers.push_back(input);
    }

    sort(numbers.begin(), numbers.end());
    ostringstream output;

    for(int num : numbers){
        output << num << '\n';
    }
    cout << output.str();

    return 0;
}