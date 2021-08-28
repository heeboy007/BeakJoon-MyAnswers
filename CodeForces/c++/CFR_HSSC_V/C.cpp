#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while(n--){
        string predict;
        cin >> predict;

        int min = 10;

        int curr = 0;
        int score_a = 0, score_b = 0;
        int poss_a = 5, poss_b = 5;
        //let team a win!!!
        for(int i = 0; i < 10; i++){
            char curr = predict[i];
            if(i % 2){ //b
                score_b += (curr == '1') ? 1 : 0;
                poss_b--;
            } else { //a
                score_a += (curr == '1' || curr == '?') ? 1 : 0;
            }
            if(score_a > poss_b + score_b)
                min = min > i + 1 ? i + 1 : min;
        }

        score_a = 0;
        score_b = 0;
        curr = 0;

        //let team b win!!!
        for(int i = 0; i < 10; i++){
            char curr = predict[i];
            if(i % 2){ //b
                score_b += (curr == '1' || curr == '?') ? 1 : 0;
            } else { //a
                score_a += (curr == '1') ? 1 : 0;
                poss_a--;
            }
            if(score_b > poss_a + score_a)
                min = min > i + 1 ? i + 1 : min;
        }

        cout << min << '\n';
    }

    return 0;
}