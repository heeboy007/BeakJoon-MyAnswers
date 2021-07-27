#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

typedef struct _PLANET{
    int x;
    int y;
    int r;
} Planet;

bool is_in_system(pair<int, int> cord, Planet system){
    double r = (cord.first - system.x) * (cord.first - system.x);
    r += (cord.second - system.y) * (cord.second - system.y);
    r = sqrt(r);
    return (r < system.r); //inside the system.
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        pair<int, int> start, end;
        int n, count = 0;
        cin >> start.first >> start.second >> end.first >> end.second;
        cin >> n;
        while(n--){
            Planet input;
            cin >> input.x >> input.y >> input.r;
            if(is_in_system(start, input) ^ is_in_system(end, input)){
                count++;
            }
        }
        cout << count << '\n';
    }

    return 0;
}