#include<iostream>
#include<stack>

using namespace std;

//우우우어어워ㅝㅜ아ㅜ아ㅓㅜ아ㅓㅜ아ㅜ웅우아ㅓ우ㅏ우어ㅏㅜ아ㅓㅜ우아ㅜ아ㅜ아ㅓㅜ아ㅓㅜ아ㅓㅇ
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 0;
    stack<pair<int, int>> lines;
    pair<int, int> input;
    cin >> n;
    cin >> input.first >> input.second;
    n--;
    lines.push(input);

    while(n--){
        cin >> input.first >> input.second;
        if(lines.top().second < input.first){
            lines.push(input);
        } else {
            input.first = lines.top().first;
            input.second = max(lines.top().second, input.second);
            
            lines.pop();
            lines.push(input);
        }

    }

    while(!lines.empty()){
        sum += (lines.top().second - lines.top().first);
        lines.pop();
    }

    cout << sum;

    return 0;
}