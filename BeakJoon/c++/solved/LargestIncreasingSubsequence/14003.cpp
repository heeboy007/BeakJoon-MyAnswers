#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    int n;
    vector<int> lis, a, pr;

    //이게 핵심! 노드 갱신시 이전 인덱스의 정보는 언제나 이어질 수 있는 정보이므로 기록
    vector<unordered_map<int, int>> hash(1000005);
    
    //일단 수열 a를 input 받음
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        a.push_back(input);
    }
    
    int j = 0;
    lis.push_back(a[0]);
    for(int i = 1; i < n; i++){
        int node = a[i];
        if(node > lis[j]) {
            lis.push_back(node);
            hash[j + 1][node] = lis[j];
            j++;
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), node);
            if(*it == node)
                continue;
            *it = node;
            
            int idx = (it - lis.begin());
            //0번째를 갱신하는게 아니라면
            if(idx){
              //*(it-1) < node < *it 이고, *(it-1)은 무조건 node와 이을 수 있음
                hash[idx][node] = *(it - 1);
            }
        }
    }
    
    cout << (j + 1) << '\n';
    int prev = lis[j];
    pr.push_back(lis[j]);
    for(int i = j; i > 0; i--){
        prev = hash[i][prev];
        pr.push_back(prev);
    }
    
    reverse(pr.begin(), pr.end());
    for(int n : pr){
        cout << n << ' ';
    }
    
    return 0;
}