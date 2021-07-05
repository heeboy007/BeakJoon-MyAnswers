#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    vector<int> gates;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        gates.push_back(input);
    }

    sort(gates.begin(), gates.end());

    long long low = 0, high = gates[gates.size() - 1] * m;
    long long mid, sum = 0;
    while(low <= high){
        mid = (low + high) / 2;

        for(int gate : gates){
            if(!(mid / gate))
                break;
            sum += mid / gate;
        }

        if(low == mid){
            cout << mid + 1;
            break;
        }
        
        if(m > sum){
            low = mid;
        } else {
            high = mid;
        }

        sum = 0;
    }

    return 0;
}