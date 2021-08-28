#include<iostream>
#include<deque>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::deque<int> deque;

    int input = 0;
    std::cin >> input;

    for(int i = 0; i < input; i++){
        std::string str;
        std::cin >> str;
        if(!str.compare("push_back")){
            int num = 0;
            std::cin >> num;
            deque.push_back(num);
        }
        else if(!str.compare("push_front")){
            int num = 0;
            std::cin >> num;
            deque.push_front(num);
        }
        else if(!str.compare("pop_back")){
            if(deque.empty()){
                std::cout << "-1\n";
            }
            else{
                std::cout << deque.back() << '\n';
                deque.pop_back();
            }
        }
        else if(!str.compare("pop_front")){
            if(deque.empty()){
                std::cout << "-1\n";
            }
            else{
                std::cout << deque.front() << '\n';
                deque.pop_front();
            }
        }
        else if(!str.compare("empty")){
            std::cout << (deque.empty() ? "1\n" : "0\n");
        }
        else if(!str.compare("front")){
            std::cout << (deque.empty() ? -1 : deque.front()) << '\n'; 
        }
        else if(!str.compare("back")){
            std::cout << (deque.empty() ? -1 : deque.back()) << '\n'; 
        }
        else{ // size
            std::cout << deque.size() << '\n';
        }
    }

    return 0;
}