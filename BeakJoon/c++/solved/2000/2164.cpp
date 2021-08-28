#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    queue<int> cards;
    cin >> count;

    for(int i = 1; i <= count; i++){
        cards.push(i);
    }

    bool send_back = false;
    int prev = 0;
    while(!cards.empty()){
        prev = cards.front();
        cards.pop();
        if(send_back){
            cards.push(prev);
        }
        send_back = !send_back;
    }
    cout << prev;

    return 0;
}