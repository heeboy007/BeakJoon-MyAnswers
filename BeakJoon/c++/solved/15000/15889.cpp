#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cord[30001] = {0}, str[30001] = {0};
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> cord[i];
    }
    for(int i = 0; i < n - 1; i++){
        cin >> str[i];
    }

    int max_reach = str[0], prev_max = 0, prev_index = 0;
    do{
        int i;
        for(i = prev_index; cord[i] <= max_reach && i < n; i++)
            max_reach = max(max_reach, cord[i] + str[i]);
        prev_index = i;
        if(max_reach == prev_max)
            break;
        prev_max = max_reach;
    }
    while(max_reach < cord[n - 1]);

    if(max_reach >= cord[n - 1])
        cout << "권병장님, 중대장님이 찾으십니다";
    else
        cout << "엄마 나 전역 늦어질 것 같아";

    return 0;
}