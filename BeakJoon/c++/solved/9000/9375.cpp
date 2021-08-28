#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        unordered_map<string, int> hash;
        vector<string> exist;
        int n;
        cin >> n;
        while(n--){
            string dummy, actuall;
            cin >> dummy >> actuall;
            if(!hash[actuall]){
                hash[actuall]++;
                exist.push_back(actuall);
            } else {
                hash[actuall]++;
            }
        }
        int count = 1;
        for(string nodes : exist){
            count *= (hash[nodes] + 1);
        }
        cout << (count - 1) << '\n';
    }

    return 0;
}