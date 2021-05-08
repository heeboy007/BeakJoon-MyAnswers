#include<iostream>
#include<queue>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::queue<int> queue;

    int input = 0;
    std::cin >> input;

    for(int i = 0; i < input; i++){
        std::string str;
        std::cin >> str;
        if(!str.compare("push")){
            int num = 0;
            std::cin >> num;
            queue.push(num);
        }
        else if(!str.compare("pop")){
            if(queue.empty()){
                std::cout << "-1\n";
            }
            else{
                std::cout << queue.front() << '\n';
                queue.pop();
            }
        }
        else if(!str.compare("empty")){
            std::cout << (queue.empty() ? "1\n" : "0\n");
        }
        else if(!str.compare("front")){
            std::cout << (queue.empty() ? -1 : queue.front()) << '\n'; 
        }
        else if(!str.compare("back")){
            std::cout << (queue.empty() ? -1 : queue.back()) << '\n'; 
        }
        else{ // size
            std::cout << queue.size() << '\n';
        }
    }

    return 0;
}