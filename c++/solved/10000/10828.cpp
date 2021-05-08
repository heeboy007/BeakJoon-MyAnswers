#include<iostream>
#include<stack>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::stack<int> stack;

    int input = 0;
    std::cin >> input;

    for(int i = 0; i < input; i++){
        std::string str;
        std::cin >> str;
        if(!str.compare("push")){
            int num = 0;
            std::cin >> num;
            stack.push(num);
        }
        else if(!str.compare("pop")){
            if(stack.empty()){
                std::cout << "-1\n";
            }
            else{
                std::cout << stack.top() << '\n';
                stack.pop();
            }
        }
        else if(!str.compare("empty")){
            std::cout << (stack.empty() ? "1\n" : "0\n");
        }
        else if(!str.compare("top")){
            std::cout << (stack.empty() ? -1 : stack.top()) << '\n'; 
        }
        else{ // size
            std::cout << stack.size() << '\n';
        }
    }

    return 0;
}