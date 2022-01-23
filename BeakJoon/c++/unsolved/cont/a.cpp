#include<iostream>
#include<unordered_map>
#include<cstring>
#include<cstdlib>

using namespace std;

#define Time pair<int, int>

int delta(int to, int from){
    if(from < to)
        return 1440 - to + from;
    else
        return from - to;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(14);

    unordered_map<string, double> station = {
        {"Seoul", 0.0},
        {"Yeongdeungpo", 9.1},
        {"Anyang", 23.9},
        {"Suwon", 41.5},
        {"Osan", 56.5},
        {"Seojeongri", 66.5},
        {"Pyeongtaek", 75.0},
        {"Seonghwan", 84.4},
        {"Cheonan", 96.6},
        {"Sojeongni", 107.4},
        {"Jeonui", 114.9},
        {"Jochiwon", 129.3},
        {"Bugang", 139.8},
        {"Sintanjin", 151.9},
        {"Daejeon", 166.3},
        {"Okcheon", 182.5},
        {"Iwon", 190.8},
        {"Jitan", 196.4},
        {"Simcheon", 200.8},
        {"Gakgye", 204.6},
        {"Yeongdong", 211.6},
        {"Hwanggan", 226.2},
        {"Chupungnyeong", 234.7},
        {"Gimcheon", 253.8},
        {"Gumi", 276.7},
        {"Sagok", 281.3},
        {"Yangmok", 289.5},
        {"Waegwan", 296.0},
        {"Sindong", 305.9},
        {"Daegu", 323.1},
        {"Dongdaegu", 326.3},
        {"Gyeongsan", 338.6},
        {"Namseonghyeon", 353.1},
        {"Cheongdo", 361.8},
        {"Sangdong", 372.2},
        {"Miryang", 381.6},
        {"Samnangjin", 394.1},
        {"Wondong", 403.2},
        {"Mulgeum", 412.4},
        {"Hwamyeong", 421.8},
        {"Gupo", 425.2},
        {"Sasang", 430.3},
        {"Busan", 441.7}
    };

    int n, m;
    cin >> n >> m;
    unordered_map<string, Time> times;
    char time1[10] = {0}, time2[10] = {0};
    for(int i = 0; i < n; i++){
        string name;
        Time x = {0, 0};
        cin >> name >> time1 >> time2;
        if(time1[0] != '-'){
            time1[2] = 0;
            x.first = atoi(time1) * 60 + atoi(time1 + 3);
        }
        if(time2[0] != '-'){
            time2[2] = 0;
            x.second = atoi(time2) * 60 + atoi(time2 + 3);
        }
        times[name] = x;
    }

    for(int i = 0; i < m; i++){
        string to, from;
        cin >> to >> from;
        double dist = (double)abs(station[to] - station[from]);
        double time = (double)delta(times[to].second, times[from].first);
        cout << (dist / time) * 60.0 << '\n';
    }

    return 0;
}