#include<iostream>
#include<bitset>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string han = "가";
    cin >> han;
    int numbering = 1;

    for(int i = 0; i < 6; i++){
        if((char)(1 << i) & han[2]){
            numbering += (1 << i);
        }
    }
    for(int i = 6; i < 12; i++){
        if((char)(1 << (i - 6)) & han[1]){
            numbering += (1 << i);
        }
    }
    for(int i = 12; i < 16; i++){
        if((char)(1 << (i - 12)) & han[0]){
            numbering += (1 << i);
        }
    }
    cout << (numbering - 0xAC00);

    return 0;
}