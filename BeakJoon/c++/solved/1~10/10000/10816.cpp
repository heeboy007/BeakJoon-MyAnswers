#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    unordered_map<int, int> storage;
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        if(storage.find(input) == storage.end()){
            storage[input] = 1;
        } else {
            storage[input] += 1;
        }
    }

    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        if(storage.find(input) == storage.end()){
            cout << "0 ";
        } else {
            cout << storage[input] << ' ';
        }
    }

    return 0;
}