//AC

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        long long maximum = 0;
        long long count = 0;
        vector<long long> v;
        cin >> n >> k;
        
        for(int i = 0; i < n; i++){
            long long input;
            cin >> input;
            count += input;
            v.push_back(input);
        }
        
        sort(v.begin(), v.end());
        auto little = v.begin();
        auto big = v.end() - 1;
        
        for(int i = 0; i < k; i++){
            count -= *big--;
        }
        
        maximum = count;
        big++;
        //cout << "Pre" << '\n';
        //cout << "CURR : " << count << '\n';
        
        for(int i = 0; i < k; i++){
            count -= *little++;
            count -= *little++;
            count += *big++;
            //cout << "Index : " << i << '\n';
            //cout << "CURR : " << count << '\n';
            maximum = max(maximum, count);
        }
        
        cout << maximum << '\n';
    }

    return 0;
}
