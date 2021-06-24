#include<iostream>

using namespace std;

//long long box_memo[100];

long long box(int n){
    if(n == 0 || n == 1 || n == 2){
        return n;
    } else {
        return 2 * box(n - 1) - 1;
    }
}

int main(){
    int n;
    cin >> n;

    /*
    for(int i = 0; i < 100; i++){
        box_memo[i] = -1; //not using memset here.
        //memset is supposed to set BYTES not TYPES.
    }*/

    //box_memo[0] = 0;
    //box_memo[1] = 1;

    cout << box(n) % 10007;

    return 0;
}