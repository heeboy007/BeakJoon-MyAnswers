#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    vector<long long> makgul;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        makgul.push_back(input);
    }

    sort(makgul.begin(), makgul.end());

    long long low = 1, high = makgul[makgul.size() - 1] + 1;
    long long mid, sum = 0;
    while(low <= high){
        mid = (low + high) / 2;

        for(int mak : makgul){
            sum += mak / mid;
        }

        if(low == mid){
            cout << mid;
            break;
        }
        
        if(m <= sum){
            low = mid;
        } else {
            high = mid;
        }

        sum = 0;
    }

    return 0;
}