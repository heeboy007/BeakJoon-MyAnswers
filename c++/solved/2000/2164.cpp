#include<iostream>
#include<queue>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::queue<int> card_queue;

    int input = 0;
    std::cin >> input;

    for(int i = 1; i <= input; i++){
        card_queue.push(i);
    }

    while(card_queue.size() > 1){
        card_queue.pop();
        if(card_queue.size() == 1) break;
        card_queue.push(card_queue.front());
        card_queue.pop();
    }

    std::cout << card_queue.front();
    return 0;
}