#include<iostream>

#define DIV2 29

using namespace std;

long long patten_ioi(int n){
    long long hash = 'I' - 'A' + 1;
    for(int i = 0; i < n; i++){
        hash = hash * DIV2 + 'O' - 'A' + 1; 
        hash = hash * DIV2 + 'I' - 'A' + 1;
    }
    return hash;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 1, m, count = 0;
    string what;
    cin >> n >> m >> what;
    what += "XXXX";
    long long comp2 = 0, base_y = 1; 
    long long pattern2 = patten_ioi(n);
    for(int i = 0; i < 2 * n + 1; i++){
        comp2 = comp2 * DIV2 + what[i] - 'A' + 1; 
        if(i) base_y = base_y * DIV2;
    }
    for(int i = 0; i < m - 2 * n; i++){
        if(pattern2 == comp2)
            count++;
        comp2 = (comp2 - base_y * (what[i] - 'A' + 1)) * DIV2 + (what[i + 2 * n + 1] - 'A' + 1);
    }
    cout << count;

    return 0;
}