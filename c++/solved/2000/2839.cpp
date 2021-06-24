#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); //really not neceesary.
    cin.tie(NULL);

    bool not_found = true;
    int kg, count = 0;
    cin >> kg;

    while(kg - count * 3 >= 0){
        if(!((kg - count * 3) % 5)){
            cout << ((kg - count * 3) / 5 + count);
            not_found = false;
            break;
        }
        count++;
    }

    if(not_found)
        cout << "-1";

    return 0;
}