#include<iostream>

#define MAX 10001

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int sum_dp[MAX] = {0};
    cin >> n >> m; 
    sum_dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int input;
        cin >> input;
        sum_dp[i] = input + sum_dp[i - 1];
    }

    int res = 0;
    for(int i = n; i > 0; i--){
        int find = sum_dp[i] - m;
        int left = 0, right = n, mid = n / 2;
        if(find < sum_dp[left] || sum_dp[right] < find){
            continue;
        }
        if(sum_dp[right] == find){
            res++;
            continue;
        }
        while(left <= right){
            mid = (left + right) / 2;
            if(sum_dp[mid] > find){
                right = mid;
            } else if(sum_dp[mid] < find){
                left = mid;
            } else {
                res++;
                break;
            }
            if(left + 1 == right){
                if(sum_dp[left] < find && find < sum_dp[right]){
                    break;
                }
            }
        }
    }

    cout << res;

    return 0;
}