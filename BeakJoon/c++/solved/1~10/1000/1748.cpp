#include <iostream>
using namespace std;

int main() {
	long long n, x = 1, count = 0;
	cin >> n;
	
	int i = 1;
	for(long long x = 9; n; x = x * 10){
	    //cout << "n : " << n << " x : " << x << " i : " << i << '\n';
	    if(n > x){
	        count += x * i;
	        n -= x;
	    } else {
	        count += n * i;
	        n -= n;
	    }
	    i++;
	}
	
	cout << count;
	
	return 0;
}
