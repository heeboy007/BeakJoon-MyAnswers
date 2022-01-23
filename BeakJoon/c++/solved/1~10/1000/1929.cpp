#include<iostream>
#include<vector>
#include<cstdio>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::vector<int> primes;
    std::string output;

    std::cin >> n >> m;

    if(n <= 2 && m >= 2)
        output.append("2\n");

    for(int i = 3; i <= m; i += 2){
        bool is_i_prime = true;
        for(int p : primes){
            if(p * p > i)
                break;
            if(i % p == 0){
                is_i_prime = false;
                break;
            }
        }
        if(is_i_prime){
            if(i >= n){
                char buff[10];
                sprintf(buff, "%d\n", i);
                output.append(buff);
            }
            primes.push_back(i);
        }       
    }

    std::cout << output;

    return 0;
}