#include<iostream>
#include<cstring>

using namespace std;

int break_to_num(int n){
    if(n > 9){
        return break_to_num(n / 10) + n % 10;
    } else {
        return n;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, min = 0;
    cin >> n;
    for(int i = 1; i < n; i++){
        if(break_to_num(i) + i == n){
            min = i;
            break;
        }
    }
    cout << min;

    return 0;
}