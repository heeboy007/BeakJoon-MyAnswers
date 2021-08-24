#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 0;
    pair<int, int> start, prev, input;

    cin >> n;
    cin >> start.first >> start.second;
    prev = start;
    n--;

    while(n--){
        cin >> input.first >> input.second;
        if(input.first == prev.first){
            sum += abs(input.second - prev.second);
        } else {
            sum += abs(input.first - prev.first);
        }
        prev = input;
    }

    if(start.first == prev.first){
        sum += abs(start.second - prev.second);
    } else {
        sum += abs(start.first - prev.first);
    }

    cout << sum;

    return 0;
}