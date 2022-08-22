#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
	int n, m;
	cin >> n;
	vector<int> v, s;
	
	for(int i = 0; i < n; i++){
	    int input;
	    cin >> input;
	    v.push_back(input);
	}
	cin >> m;
	
	sort(v.begin(), v.end());
	s.push_back(v[0]);
	for(int i = 1; i < n; i++){
	    s.push_back(s[i - 1] + v[i]);
	}
	
	if(m >= s[n - 1]){
	    cout << v[n - 1];
	    return 0;
	}
	
	for(int i = v[n - 1]; i >= 1 ; i--){
	    int index = lower_bound(v.begin(), v.end(), i) - v.begin();
	    int curr = s[index - 1] + (n - index) * i;
	    //cout << "try " << i << " res " << curr << '\n';
	    if(curr <= m){
	        cout << i << '\n';
	        break;
	    }
	}
	
	return 0;
}
