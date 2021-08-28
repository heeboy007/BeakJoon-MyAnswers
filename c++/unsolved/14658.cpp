#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int limit_x, limit_y, length, stars, maximum = 0;
    cin >> limit_x >> limit_y >> length >> stars;

    vector<int> pos_x, pos_y;
    vector<pair<int, int>> star;

    for(int i = 0; i < stars; i++){
        int ix, iy;
        cin >> ix >> iy;
        pos_x.emplace_back(ix);
        pos_y.emplace_back(iy);
        star.push_back({ix, iy});
    }
    sort(pos_x.begin(), pos_x.end());
    sort(pos_y.begin(), pos_y.end());

    for(int i = 0; i < pos_x.size(); i++){
        int x = pos_x[i];
        for(int j = 0; j < pos_y.size(); j++){
            int y = pos_x[i];
            int curr1 = 0, curr2 = 0, curr3 = 0, curr4 = 0;
            for(pair<int, int> p : star){
                if(x <= p.first && p.first <= x + length && y <= p.second && p.second <= y + length)
                    ++curr1;
                if(x - length <= p.first && p.first <= x && y <= p.second && p.second <= y + length)
                    ++curr2;
                if(x <= p.first && p.first <= x + length && y - length <= p.second && p.second <= y)
                    ++curr3;
                if(x - length <= p.first && p.first <= x && y - length <= p.second && p.second <= y)
                    ++curr4;
            }

            maximum = max(curr1, max(curr2, max(curr3, max(curr4, maximum))));
        }
    }

    cout << maximum;

    return 0;
}