#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long input, compare = 1;
    long long index = 1;
    cin >> input;
    while(input > compare){
        compare += index * 6;
        index++;
    }
    cout << index;

    return 0;
}