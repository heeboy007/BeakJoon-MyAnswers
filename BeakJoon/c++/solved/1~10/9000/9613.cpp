#include<iostream>
#include<vector>

using namespace std;

long gcd(long a, long b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;
    while(c--){
        vector<int> nums;
        int n;
        long sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            int input;
            cin >> input;
            nums.push_back(input);
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                sum += gcd(nums[i], nums[j]);
            }
        }
        cout << sum << '\n';
    }

    return 0;
}