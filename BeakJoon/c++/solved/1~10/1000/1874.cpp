#include<iostream>
#include<stack>
#include<vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, pos = 1, next = 1;
    std::vector<int> goal;
    std::stack<int> pancake;
    std::string output;

    std::cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        std::cin >> input;
        goal.push_back(input);
    }

    for(int num : goal){
        if(next <= num){
            while(next <= num){
                pancake.push(next);
                next++;
                //std::cout << "curr next :" << next << '\n';
                output.append("+\n");
            }
        }
        if(!pancake.empty()){
            if(pancake.top() == num){
                pancake.pop();
                output.append("-\n");
            }
            else{
                std::cout << "NO";
                return 0;
            }
        }
    }

    std::cout << output;

    return 0;
}