#include<iostream>
#include<queue>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::queue<int> queue;

    int n = 0, k = 0;
    std::cin >> n;
    std::cin >> k;

    for(int i = 1; i <= n; i++){
        queue.push(i);
    }

    std::cout << '<';
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < k - 1; j++){
            queue.push(queue.front());
            queue.pop();
        }
        std::cout << queue.front() << ", ";
        queue.pop();
    }
    std::cout << queue.front() << '>';

    return 0;
}