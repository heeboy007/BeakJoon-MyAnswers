#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 0;
    cin >> n;

    for(int i = 5; i <= n; i += 5){
        int copy = i;
        while(!(copy % 5)){
            sum += 1;
            copy /= 5;
        }
    }

    cout << sum;

    return 0;
}