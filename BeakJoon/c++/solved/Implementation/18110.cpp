#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    vector<int> v;
    
    cin >> n;
    
    if(!n){
        cout << "0";
        return 0;
    }
    
    int level = 0;
    
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    
    sort(v.begin(), v.end());

    int gaurd = floor((double)n * 0.15 + 0.5); 
    
    for(int i = gaurd; i < n - gaurd; i++){
        level += v[i];
    }

    double callevel = (double)level / (double)(n - gaurd * 2);
    
    cout << floor(callevel + 0.5);

    return 0;
}
