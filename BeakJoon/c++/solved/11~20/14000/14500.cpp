#include<iostream>
#include<vector>

using namespace std;

#include<iostream>
#include<vector>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<pair<int, int>>> unique_tet = {
        {{0, 1}, {1, 0}, {1, 1}}, //square : 1
        {{0, 1}, {0, 2}, {0, 3}},
        {{1, 0}, {2, 0}, {3, 0}}, //long : 2
        {{0, 1}, {-1, 1}, {1, 1}},
        {{0, 1}, {0, 2}, {1, 1}},
        {{0, 1}, {-1, 1}, {0, 2}},
        {{1, 0}, {2, 0}, {1, 1}}, // t : 4
        {{0, 1}, {-1, 1}, {-2, 1}},
        {{1, 0}, {1, 1}, {1, 2}},
        {{0, 1}, {1, 1}, {2, 1}},
        {{0, 1}, {0, 2}, {1, 0}},
        {{0, 1}, {2, 0}, {1, 0}},
        {{0, 1}, {0, 2}, {-1, 2}},
        {{0, 1}, {0, 2}, {1, 2}},
        {{1, 0}, {2, 0}, {2, 1}}, // L : 8
        {{1, 0}, {1, 1}, {2, 1}},
        {{0, 1}, {-1, 1}, {-1, 2}},
        {{0, 1}, {1, 1}, {1, 2}},
        {{0, 1}, {1, 0}, {-1, 1}} // S : 4
    };

    int map[501][501];
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    int max = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool skip_check = ((i + 3) < n) && ((j - 2) >= 0) && ((j + 3) < m);
            for(vector<pair<int, int>> tet : unique_tet){
                bool valid = true;
                int sum = map[i][j];
                for(pair<int, int> cord : tet){
                    int cx = j + cord.first, cy = i + cord.second;
                    if(skip_check){
                        sum += map[cy][cx];
                    } else if(0 <= cx && cx < m && 0 <= cy && cy < n) {
                        sum += map[cy][cx];
                    } else {
                        valid = false;
                        break;
                    }
                }
                max = (valid && (sum > max) ? sum : max);
            }
        }
    }
    cout << max;

    return 0;
}