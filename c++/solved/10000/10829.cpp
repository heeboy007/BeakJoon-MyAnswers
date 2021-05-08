#include<iostream>

char bin(long n, long base){
    long base_2 = base << 1;
    if((n % base_2) >= base){
        if(base_2 <= n)
            std::cout << bin(n, base_2);
        return '1';
    }
    else{
        if(base_2 <= n)
            std::cout << bin(n, base_2);
        return '0';
    }
}

int main(){
    long input;
    std::cin >> input;
    std::cout << bin(input, 1);

    return 0;
}