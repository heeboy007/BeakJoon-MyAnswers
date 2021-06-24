#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long N, M;
    vector<int> trees;
    cin >> N >> M;
    
    for(long i = 0; i < N; i++){
        int input;
        cin >> input;
        trees.push_back(input);
    }

    sort(trees.rbegin(), trees.rend());

    int left = 0, right = trees.front();
    long sum = 0;
    
    while(left <= right)
    {
        int mid = (left + right) / 2;

        for(int tree : trees){
            if(tree < mid)
                break;
            sum += tree - mid;
        }

        //cout << left << ":" << mid << ":" << right << '\n';
        //cout << sum << '\n';

        if(left == mid)
        {
            cout << mid;
            break;
        }
        
        if(sum < M)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }

        sum = 0;
    }

    return 0;
}