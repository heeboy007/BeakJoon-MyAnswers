#include<iostream>

using namespace std;

void div_con(long long n, long long r, long long c, long long start){
    if(n == 0){
        cout << start;
        return;
    }
    long long border = 1 << (n - 1);
    if(r < border){
        if(c < border){
            div_con(n - 1, r, c, start);
        } else {
            div_con(n - 1, r, c - border, start + (1 << (2 * n - 2)));
        }
    } else {
        if(c < border){
            div_con(n - 1, r - border, c, start + (1 << (2 * n - 1)));
        } else {
            div_con(n - 1, r - border, c - border, start + (1 << (2 * n - 1)) + (1 << (2 * n - 2)));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, r, c;
    cin >> n >> r >> c;

    div_con(n, r, c, 0);

    return 0;
}