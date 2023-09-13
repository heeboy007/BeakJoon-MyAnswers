#include<iostream>

using namespace std;

#define ll long long

/*
아님 걍 한가지 소수로 이루어진 경우만 그걸로 곱해주면 됨
*/

ll gcd(ll a, ll b){
	ll n;
	while(b != 0){
		n=a%b;
		a=b;
		b=n;
	}	
	return a;
}

ll lcm(ll a, ll b){
	return a*b / gcd(a, b);
}

ll no_good(ll a, ll b){
    while(a){
        if(!(a % b)){
            a /= b;
            if(a == 1)
                return true;
        } else 
            return false;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, base = 2147483647, ans = 1;
    ll nums[52] = {0};
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> nums[i];
        base = min(base, nums[i]);
        ans = lcm(nums[i], ans);
    }
    
    if(no_good(ans, base))
        ans *= base;

    cout << ans;
    return 0;
}