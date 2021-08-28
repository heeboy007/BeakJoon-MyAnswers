#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int e, s, m;
    cin >> e >> s >> m;
    e--; s--; m--;

    int i = 0;
    while(!((i % 15 == e) && (i % 28 == s) && (i % 19 == m)))
        i++;
    cout << (++i);

    return 0;
}