#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, k = 0, ans = 0;
    stack<int> coins; 
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        coins.push(input);
    }

    while(k){
        if(k >= coins.top()){
            ans += k / coins.top();
            k %= coins.top();
        }
        coins.pop(); 
    }
    
    cout << ans;

    return 0;
}