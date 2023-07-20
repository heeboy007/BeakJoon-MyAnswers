#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[55][55] = {0};
int power[55][55] = {0};
int total = 0;
int w, h, n;

#define Cord pair<int, int>

void bfs(Cord start){
    queue<Cord> q;
    int curr_power = 15;
    q.push(start);
    power[start.first][start.second] = curr_power;
    while(!(q.empty())){
        int track = q.size();
        for(int i = 0; i < track; i++){
            Cord node = q.front();
            q.pop();
            Cord near[5] = {
                {node.first + 1, node.second},
                {node.first, node.second + 1},
                {node.first - 1, node.second},
                {node.first, node.second - 1},
            };
            for(Cord check : near){
                if(1 <= check.first && check.first <= w && 1 <= check.second && check.second <= h){
                    if(power[check.first][check.second] < curr_power){
                        if(map[check.first][check.second] == 1){
                            q.push(check);
                            power[check.first][check.second] = curr_power;
                        } else if(map[check.first][check.second] == 3) {
                            power[check.first][check.second] = 16;
                            total++;
                        }
                    }
                }
            }
        }
        curr_power--;
    }
}

int main()
{
    cin >> w >> h >> n;
    
    vector<Cord> all_blocks;
    vector<Cord> all_lamps;
    
    for(int i = 0; i < n; i++){
        Cord input;
        string type;
        cin >> type >> input.first >> input.second;
        ++input.first;
        ++input.second;
        if(type == "redstone_block"){
            map[input.first][input.second] = 2;
            all_blocks.push_back(input);
        } else if(type == "redstone_lamp"){
            map[input.first][input.second] = 3;
            all_lamps.push_back(input);
        } else {
            map[input.first][input.second] = 1;
        }
    }
    
    /*for(int i = 1; i <= w; i++){
        for(int j = 1; j <= h; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }*/
    
    for(Cord block : all_blocks){
        bfs(block);
    }
    
    /*for(int i = 1; i <= w; i++){
        for(int j = 1; j <= h; j++){
            cout << power[i][j] << ' ';
        }
        cout << '\n';
    }*/
    
    /*bool lit = true;
    for(Cord lamp : all_lamps){
        // bool powa = 
        //     power[lamp.first + 1][lamp.second] || 
        //     power[lamp.first - 1][lamp.second] || 
        //     power[lamp.first][lamp.second + 1] || 
        //     power[lamp.first][lamp.second - 1];
        // lit = lit && powa;
        lit = lit && power[lamp.first][lamp.second];
    }*/
    
    cout << (total == all_lamps.size() ? "success" : "failed");

    return 0;
}
