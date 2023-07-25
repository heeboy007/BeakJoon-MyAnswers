#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LL unsigned long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int up[100] = { 0 };
    vector<LL> numbers;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        LL input;
        cin >> input;
        numbers.push_back(input);
    }

    sort(numbers.rbegin(), numbers.rend());
    
    while(!(numbers.back()))
        numbers.pop_back();
    
    
    int index = 0;
    LL curr = 1;
    
    while(!(numbers.empty())){
        int until = numbers.size();
        for(int i = 0; i < until; i++){
            if(curr == numbers.back()){
                numbers.pop_back();
                ++up[index];
            } else {
                break;
            }
        }
        ++index;
        curr = curr << 1;
    }

    for(int i = 0; i < 65; i++){
        up[i + 1] += up[i] / 2;
        up[i] %= 2;
    }

    int max_count = 0;
    for(int i = 62; i >= 0; i--){
        if(up[i]) {
            max_count = i;
            break;
        }
    }
    
    curr = 1;
    for(int i = 0; i < max_count; i++){
        curr = curr << 1;
    }
    cout << curr;

    return 0;
}
