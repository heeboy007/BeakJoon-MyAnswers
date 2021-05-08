#include<iostream>

int factor(int n){
    if( n <= 1 ){
        return 1;
    } else {
        return n * factor(n-1);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int input;
    std::cin >> input;
    std::cout << factor(input);

    return 0;
}