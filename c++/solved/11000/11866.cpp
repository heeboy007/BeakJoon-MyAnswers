#include<queue>
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    queue<int> numbers;
    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        numbers.push(i);
    }

    cout << "<";
    while(!numbers.empty()){
        for(int i = 1; i < K; i++){
            int temp = numbers.front();
            numbers.pop();
            numbers.push(temp);
        }
        cout << numbers.front() << (N == 1 ? "" : ", ");
        numbers.pop();
        N--;
    }
    cout << ">";

    return 0;
}