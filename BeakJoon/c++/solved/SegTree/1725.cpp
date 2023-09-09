#include <iostream>
#include <vector>

using namespace std;

#define LL long long
#define MAX 4000000

int tree[MAX] = {0};
LL a[MAX] = {0};
LL n, m, k;

int init(int start, int end, int node){
    if(start == end)
        return tree[node] = start;
    int mid = (start + end) / 2;
    int l = init(start, mid, node * 2);
    int r = init(mid + 1, end, node * 2 + 1);
    return tree[node] = (a[l] < a[r] ? l : r);
}

int get_min_index(int start, int end, int node, int left, int right){
    if(right < start || end < left)
        return -1;
    if(left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    int l = get_min_index(start, mid, node * 2, left, right);
    int r = get_min_index(mid + 1, end, node * 2 + 1, left, right);
    LL act_l = (l == -1 ? 1000000001L : a[l]);
    LL act_r = (r == -1 ? 1000000001L : a[r]);
    return (act_l < act_r ? l : r);
}

LL get_ans(int left, int right){
    if(left == right)
        return a[left];
    if(right < left)
        return 0L;
    int curr_ind = get_min_index(0, n - 1, 1, left, right);
    LL curr = (right - left + 1) * a[curr_ind];
    LL l = get_ans(left, curr_ind - 1);
    LL r = get_ans(curr_ind + 1, right);
    return max(curr, max(l, r));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    init(0, n - 1, 1);
    cout << get_ans(0, n - 1) << '\n';
    
    return 0;
}