#include<iostream>
#include<stack>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::stack<int> stack;

    int input = 0;
    int sum = 0;
    std::cin >> input;

    for(int i = 0; i < input; i++){
        int num = 0;
        std::cin >> num;
        if(num){ //not 0
            stack.push(num);
            sum += num;
        } 
        else{ // 0
            sum -= stack.top();
            stack.pop();
        }
    }

    std::cout << sum;
    return 0;
}