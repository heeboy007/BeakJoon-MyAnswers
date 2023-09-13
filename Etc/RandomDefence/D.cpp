#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        int b, p;
        pair<int, int> bridges[21];
        cin >> b >> p;
        if(b == 0)
            break;
        for(int i = 0; i < -b; i++){
            cin >> bridges[i].first >> bridges[i].second;
        }

        

    }
    

    return 0;
}