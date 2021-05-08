#include<iostream>
#include<vector>
#include<functional>
#include<unordered_map>

using namespace std;

// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
  
// // Creating some pairs to be used as keys
    // pair<long, long> p1(1000, 2000);
    // pair<long, long> p2(2000, 3000);
    // pair<long, long> p3(2005, 3005);
      
    // // Inserting values in the unordered_map.
    // um[p1] = 10;
    // um[p2] = 20;
    // um[p3] = 30;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    unordered_map<pair<int, int>, long, hash_pair> cost;
    vector<int>** groups = new vector<int>*[n];

    for(int i = 0; i < n; i++){
        groups[i] = new vector<int>();
        groups[i]->push_back(i);
    }

    for(int i = 0; i < m; i++){
        int command, val1, val2;
        cin >> command >> val1 >> val2;
        if(command == 1){
            for(int new_group_memeber : *(groups[val2 - 1])){
                groups[val1 - 1]->push_back(new_group_memeber);
            }
            vector<int> temp = vector<int>();
            for(int group_member : *(groups[val2 - 1])){
                temp.push_back(group_member);
            }
            for(int group_member : temp){
                groups[group_member] = groups[val1 - 1];
            }
        } else {
            vector<int>* pay_group = groups[val1 - 1];
            long dept = val2 / pay_group->size();
            for(int persons : *pay_group){
                if(val1 - 1 == persons)
                    continue;
                pair<int, int> key(val1 - 1, persons);
                unordered_map<pair<int, int>, long>::const_iterator got = cost.find(key);
                if(got == cost.end()){ //내가 진 빛이 없음
                    pair<int, int> reverse_key(persons, val1 - 1);
                    if(cost[reverse_key]){
                        cost[reverse_key] += dept;
                    } else {
                        cost[reverse_key] = dept;
                    }
                } else { //내가 진 빛이 없음
                    cost[key] -= dept;
                    if(!cost[key])
                        cost.erase(key);
                }

                // for (auto p : cost){
                //     cout << '[' << (p.first).first << ',' 
                //         << (p.first).second << "] ==> "
                //         << p.second << '\n';
                // }
                // cout << endl;
            }
        }
    }

    if(cost.size() > n){
        cout << "-1";
    } else {
        cout << cost.size() << '\n';
        for (auto p : cost){
            if(p.second > 0)
                cout << (p.first).first + 1 << ' ' 
                    << (p.first).second + 1 << ' '
                    << p.second << '\n';
            else
                cout << (p.first).second + 1 << ' ' 
                    << (p.first).first + 1 << ' '
                    << -p.second << '\n';
        }
    }
  
    return 0;
}