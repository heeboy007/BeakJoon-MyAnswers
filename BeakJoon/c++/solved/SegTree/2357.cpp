#include <iostream>
#include <sstream>

using namespace std;

#define LL long long
#define P pair<LL, LL>
#define MAX 400005

LL min_tree[MAX] = {0}, max_tree[MAX] = {0};
LL input[MAX] = {0};

LL min_init(LL start, LL end, LL node) {
    if(start == end)
        return (min_tree[node] = input[start]);
    LL mid = (start + end) / 2;
    return min_tree[node] = min(min_init(start, mid, node * 2), min_init(mid + 1, end, node * 2 + 1));
}

LL max_init(LL start, LL end, LL node) {
    if(start == end)
        return (max_tree[node] = input[start]);
    LL mid = (start + end) / 2;
    return max_tree[node] = max(max_init(start, mid, node * 2), max_init(mid + 1, end, node * 2 + 1));
}

LL find_min(LL start, LL end, LL node, LL left, LL right){
    if(right < start || end < left)
        return 1000000001L;
    //여기가 핵심! 그냥 범위안에 든다 싶으면 바로 반환할 수 있음~
    if(left <= start && end <= right)
        return min_tree[node];
    LL mid = (start + end) / 2;
    return min(find_min(start, mid, node * 2, left, right), find_min(mid + 1, end, node * 2 + 1, left, right));
}

LL find_max(LL start, LL end, LL node, LL left, LL right){
    if(right < start || end < left)
        return 0L;
    //여기가 핵심! 그냥 범위안에 든다 싶으면 바로 반환할 수 있음~
    if(left <= start && end <= right)
        return max_tree[node];
    LL mid = (start + end) / 2;
    return max(find_max(start, mid, node * 2, left, right), find_max(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> input[i];
        //cout << input[i] << '\n';
    }
    
    min_init(0, n - 1, 1);
    max_init(0, n - 1, 1);
    //print();
    
    ostringstream os;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        os << find_min(0, n - 1, 1, x, y) << ' ' << find_max(0, n - 1, 1, x, y) << '\n';
    }
    cout << os.str();

    return 0;
}
