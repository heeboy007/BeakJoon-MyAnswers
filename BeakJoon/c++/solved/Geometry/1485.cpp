#include <iostream>
#include <cmath>

using namespace std;

#define Cord pair<int, int>

Cord dist(Cord a, Cord b){
    a.first -= b.first;
    a.second -= b.second;
    return a;
}

double eu_dist(Cord a, Cord b){
    double euclid_distance = (double)(b.first - a.first) * (b.first - a.first)
        + (b.second - a.second) * (b.second - a.second);
    euclid_distance = sqrt(euclid_distance);
    return euclid_distance;
}

Cord cords[5] = {};
Cord dists[5][5] = {};
bool is_visited[5] = {0};
int made[5] = {0};

int a, b, c, d;
bool end_backtrack = false;

void backtrack(int curr){
    if(curr > 3) {
        if(dists[made[0]][made[1]] == dists[made[2]][made[3]]){
            a = made[0];
            b = made[1];
            c = made[2];
            d = made[3];
            end_backtrack = true;
        }
        return;
    }
    for(int i = 0; i < 4 && !end_backtrack; i++){
        if(!is_visited[i]){
            is_visited[i] = true;
            made[curr] = i;
            backtrack(curr + 1);
            is_visited[i] = false;
        }
    }
}

void solution(){
    for(int i = 0; i < 4; i++){
        cin >> cords[i].first >> cords[i].second;
    }
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i != j)
                dists[i][j] = dist(cords[i], cords[j]);
        }
    }
    
    a = b = c = d = -1;
    end_backtrack = false;
    backtrack(0);
    
    //cout << a << b << c << d << '\n';
    
    //평행하며, 길이가 같은 한짝의 선분을 찾지 못함
    if(a < 0){
        cout << "0\n";
        return;
    }
    //평행하며, 길이가 같은 한짝의 선분을 찾음
    //직사각형 조건 확인 두 대각선 길이 같음 여기서 인접한 두 변의 길이 같음
    if(eu_dist(cords[b], cords[c]) == eu_dist(cords[a], cords[d]) &&
        eu_dist(cords[a], cords[b]) == eu_dist(cords[a], cords[c])){
        cout << "1\n";
    } else {
        cout << "0\n";
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    //backtrack(0);
    while(t--){
        solution();
    }

    return 0;
}
