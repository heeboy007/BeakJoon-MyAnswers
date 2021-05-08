#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int gn;
    std::cin >> gn;
    for(int x = 0; x < gn; x++){
        int n, m;
        std::queue<int> priority;
        int avaliable[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        std::cin >> n >> m;
        for(int i = 0; i < n; i++){
            int input;
            std::cin >> input;
            priority.push(input);
            avaliable[input]++;
        }

        int prints = 1;
        while(!priority.empty()){
            int max = 0;
            for(int i = 9; i > 0; i--){
                if(avaliable[i]){
                    max = i;
                    break;
                }
            }

            while(priority.back() < max){
                priority.push(priority.back());
                priority.pop();
                m++;
                if(m >= n)
                    m = 0;
            }
            if((m + 1) == priority.size()){
                std::cout << prints << std::endl;
                break;
            } else {
                avaliable[priority.back()]--;
                priority.pop();
                prints++;
            }
        }
    }

    return 0;
}