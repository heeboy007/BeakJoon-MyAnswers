#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define LL long long
#define MAX 4000000

LL tree[MAX] = {0}, a[MAX] = {0};
LL n, m, k;

LL init(LL start, LL end, LL node){
    if(start == end)
        return tree[node] = a[start];
    LL mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

LL sum(LL start, LL end, LL node, LL left, LL right) {
    if(left > end || right < start)
        return 0;
    if(left <= start && end <= right)
        return tree[node];
    LL mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + 
        sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(LL start, LL end, LL node, LL index, LL dif){
    if(index < start || index > end)
        return;
    tree[node] += dif;
    if(start == end)
        return;
    LL mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

/*void print(){
    cout << "TREE: ";
    for(int i = 0; i < 50; i++){
        cout << tree[i] << ' ';
    }
    cout << '\n';
}*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    
    for(LL i = 0; i < n; i++){
        cin >> a[i];
    }
    
    init(0, n - 1, 1);
    
    for(LL i = 0; i < m + k; i++){
        LL comm, c, d;
        cin >> comm >> c >> d;
        c--;
        d--;
        if(comm == 1){
            //print();
            update(0, n - 1, 1, c, d - a[c] + 1);
            //print();
            a[c] = d + 1;
        }
        if(comm == 2){
            cout << sum(0, n - 1, 1, c, d) << '\n';
        }
    }
    
    return 0;
}