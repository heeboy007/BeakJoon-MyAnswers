#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> chock;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        chock.push_back(input);
    }

    int cnt = 0, cntidx = 0;
    int least = chock[0];
    for(int i = 0; i < n; i++){
        cnt += chock[i] - least;
        if(chock[i] != least)
            cntidx++;
    }

    cout << cnt << ' ' << cntidx;

    return 0;
}