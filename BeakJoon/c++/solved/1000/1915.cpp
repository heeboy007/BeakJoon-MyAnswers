#include<iostream>

using namespace std;

int n, m;
int map[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, maximum = 0;
    cin >> n >> m;

    //한칸 위에다가 저장하는 것이 키포인트!
    for(int i = 1; i <= n; i++){
        string input;
        cin >> input;
        for(int j = 1; j <= m; j++){
            map[i][j] = (int)(input[j - 1] - '0');
        }
    }

    //여기서 -1에 무사히 접근할 수 있으면, map은 전역변수로 해두는 것이 좋다.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(map[i][j]){
                map[i][j] = min(map[i][j - 1], min(map[i - 1][j], map[i - 1][j - 1])) + 1;
                maximum = max(map[i][j], maximum);
            }
        }
    }

    cout << maximum * maximum;

    return 0;
}