#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; ++i){
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    
    string output = "";
    cin >> m;
    for(int i = 0; i < m; ++i){
        int input, left = 0, right = n - 1, mid;
        cin >> input;
        if(input < v[left] || v[right] < input){
            output += "0\n";
            continue;
        }
        if(v[right] == input){
            output += "1\n";
            continue;
        }
        while(left <= right){
            mid = (left + right) / 2;
            if(v[mid] > input){
                right = mid;
            } else if(v[mid] < input){
                left = mid;
            } else {
                output += "1\n";
                break;
            }
            if(left + 1 == right){
                if(v[left] < input && input < v[right]){
                    output += "0\n";
                    break;
                }
            }
        }
    }
    cout << output;

    return 0;
}