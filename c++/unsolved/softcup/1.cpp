#include<iostream>

using namespace std;

long hob (long num)
{
    if (!num)
        return 0;

    long ret = 1;

    while (num >>= 1)
        ret += 1;

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long k;
    cin >> k;
    if(k == 0){
        cout << "0";
        return 0;
    } else if(!(k % 2)){
        cout << "-1";
        return 0;
    } else {
        k = abs(k);
        cout << hob(k);
    }

    return 0;
}