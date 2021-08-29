#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long N, K;
    long maximum = 0;
    cin >> N >> K;
    vector<long> humans;
    for(long i = 0; i < N; ++i){
        long input;
        cin >> input;
        humans.emplace_back(input);
    }

    sort(humans.begin(), humans.end());

    for(long i = 1; i < N; i++){
        maximum = max(humans[0] * i + humans[i] * (N - i), maximum);
    }

    if(K % maximum){
        cout << K / maximum + 1;
    } else {
        cout << K / maximum;
    }

    return 0;
}