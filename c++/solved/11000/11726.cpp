#include<iostream>
#include<cstring>

using namespace std;

int box_memo[1024];

int box(int n){
    if(box_memo[n] > 0){
        return box_memo[n];
    } else {
        return box_memo[n] = (box(n - 2) + box(n - 1)) % 10007;
    }
}

int main(){
    int n;
    cin >> n;

    //to be informed, -1 is also the only byte that can use memset (alongside 0),
    //since -1 is equal to byte(11111111)
    memset(box_memo, -1, sizeof(box_memo));

    box_memo[0] = 0;
    box_memo[1] = 1;
    box_memo[2] = 2;

    cout << box(n);

    return 0;
}