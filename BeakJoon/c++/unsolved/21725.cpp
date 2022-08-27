#include <iostream>
#include <vector>
#include <map>

#define MAX 100005

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> groups[MAX];
    map<pair<int, int>, int> costs;
    
    int n,m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
        groups[i] = {i};
    
    while(m--){
        int comm, x, k;
        cin >> comm >> x >> k;
        if(comm == 1){
            groups[x].insert( groups[x].end(), groups[k].begin(), groups[k].end() );
            groups[k] = groups[x];
        } else { //comm == 2
            int curr_cost = k / groups[x].size();
            for(int f : groups[x]){
                if(f == x)
                    continue;
                if(costs.find({f, x}) == costs.end())
                    costs[{f, x}] = curr_cost;
                else
                    costs[{f, x}] += curr_cost;
            }
        }
    }
    
    if(costs.size() > n){
        cout << "-1\n";
        return 0;
    }
    
    cout << costs.size() << '\n';
    
    auto iter = costs.begin();
    while (iter != costs.end()) {
        cout << iter->first.first << ' ' << iter->first.second << ' ' << iter->second << '\n';
        ++iter;
    }
    
	return 0;
}
