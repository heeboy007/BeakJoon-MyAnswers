#include<iostream>

int fibo(int n){
    if(n == 0){
        return 0;
    }
    else if(n <= 1){
        return 1;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int input;
    std::cin >> input;
    std::cout << fibo(input);

    return 0;
}