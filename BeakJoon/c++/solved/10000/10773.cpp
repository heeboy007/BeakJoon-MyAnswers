#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    stack<int> numbers;
    cin >> count;

    for(int i = 0; i < count; i++){
        int input;
        cin >> input;
        if(input == 0)
            numbers.pop();
        else
            numbers.push(input);
    }

    int sum = 0;
    while(!numbers.empty()){
        sum += numbers.top();
        numbers.pop();
    }
    cout << sum;

    return 0;
}