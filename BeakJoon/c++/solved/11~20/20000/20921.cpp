#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    list<int> perm;
    for(int i = 1; i <= n; i++)
        perm.push_back(i);
    
    for(int i = 0; i < n && m > 0; i++){
        int move = min(n - 1 - i, m), swap = perm.back();
        auto it = perm.begin();
        perm.pop_back();
        advance(it, n - 1 - move);
        perm.insert(it, swap);
        m -= move;
    }

    for (auto it = perm.begin(); it!=perm.end(); ++it)
        cout << *it << ' ';

    return 0;
}