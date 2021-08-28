#include<iostream>
//#include<vector>

using namespace std;

void app(){
    int n;
    long long leftover = 0;
    cin >> n;
    //vector<int> traffic(n, 0);
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        //traffic.push_back(input);
        leftover += (long long)input;
    }
    leftover %= (long long)n;
    cout << (n - leftover) * leftover << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        app();
    }

    return 0;
}