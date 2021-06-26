#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long sum = 0;
    int count;
    bool is_second = false;
    vector<int> numbers;
    int counter[8001];
    
    memset(counter, 0, sizeof(counter));
    cin >> count;

    for(int i = 0; i < count; i++){
        int input;
        cin >> input;
        sum += input;
        numbers.push_back(input);
        counter[input + 4000]++;
    }
    sort(numbers.begin(), numbers.end());

    int freq_max = 0, freq_what = -5000;

    for(int i = 0; i < 8001; i++){
        if(counter[i] > freq_max){
            freq_max = counter[i];
        }
    }

    for(int i = 0; i < 8001; i++){
        if(counter[i] >= freq_max){
            freq_what = i - 4000;
            if(is_second)
                break;
            is_second = true;
        }
    }
    //cout << "---------------------\n";
    cout << (int)round(sum / (double)count) << '\n'; //1
    cout << numbers[count / 2] << '\n'; //2
    cout << freq_what << '\n'; //3
    cout << numbers[count - 1] - numbers[0] << '\n'; //4

    return 0;
}