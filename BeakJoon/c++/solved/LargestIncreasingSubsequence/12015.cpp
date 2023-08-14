
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> lis, a;
    
    //일단 수열 a를 input 받음
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        a.push_back(input);
    }

    //lower bound도 이분탐색으로 돌아가기 때문에 binary search를 내가 구현하지 않음.
    int j = 0;
    lis.push_back(a[0]);
    for(int i = 1; i < n; i++){
        int node = a[i];
        if(node > lis[j]) {
            lis.push_back(node);
            j++;
        } else {
            *lower_bound(lis.begin(), lis.begin() + j, node) = node;
        }
    }
    
    cout << (j + 1);
    
    return 0;
}