#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numbers[4][4];

    for(int i = 0; i < 4; i++)
        cin >> numbers[i][0] >> numbers[i][1] >> numbers[i][2] >> numbers[i][3];

    int sum_sample = numbers[0][0] + numbers[0][1] + numbers[0][2] + numbers[0][3];
    for(int i = 1; i < 4; i++){
        if(sum_sample != (numbers[i][0] + numbers[i][1] + numbers[i][2] + numbers[i][3])){
            cout << "not magic\n";
            return 0;
        }
    }
    for(int i = 0; i < 4; i++){
        if(sum_sample != (numbers[0][i] + numbers[1][i] + numbers[2][i] + numbers[3][i])){
            cout << "not magic\n";
            return 0;
        }
    }

    cout << "magic\n";

    return 0;
}