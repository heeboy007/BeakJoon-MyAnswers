#include<iostream>
#include<stack>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int input = 0;
    std::cin >> input;

    for(int i = 0; i < input; i++){
        std::string m_vps;
        std::cin >> m_vps;
        std::stack<char> stack;
        bool is_vps = true;

        for(char ch : m_vps){
            if(ch == '('){
                stack.push('(');
            }
            else { // ch == ')'
                if(stack.empty()){
                    is_vps = false;
                    break;
                } else {
                    stack.pop();
                }
            }
        }

        if(stack.empty() && is_vps)
            std::cout << "YES\n";
        else    
            std::cout << "NO\n";
    }
    return 0;
}