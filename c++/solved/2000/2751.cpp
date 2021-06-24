#include<algorithm>
#include<vector>
#include<iostream>

//without namespace std.

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> number_list;

    int N = 0;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        //this is a bad practice. unless you need to modifiy the value befroe pushing it.
        int input;
        std::cin >> input;
        number_list.push_back(input);
    }

    //basic sort method.
    sort(number_list.begin(), number_list.end());

    std::string output;

    for(int n : number_list){
        char ptr[10]; 
        sprintf(ptr, "%d\n", n);
        output.append(ptr);
    }

    std::cout << output;
    return 0;
}