#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string x, ucpc = "UCPC";
    int count = 0;
    getline(cin, x);
    for(int i = 0; i < x.size(); i++){
        if(x[i] == ucpc[count])
            count++;
        if(count > 3)
            break;
    }
    if(count > 3)
        cout << "I love UCPC";
    else
        cout << "I hate UCPC";

    return 0;
}