#include<iostream>
#include<cstring>

using namespace std;

int n;
int how_many_answers = 0;
int seq[24];
bool is_used[13];


void back_track(int level){
    if(level == n){
        how_many_answers++;
    }

    for(int i = 1; i <= n; i++){
        if(is_used[i])
            continue;

        is_used[i] = true;

        int j = 0;
        while(seq[j])
            j++;

        if((j + i + 1) < 2 * n){
            if(!seq[j] && !seq[j + i + 1]){
                seq[j] = i;
                seq[j + i + 1] = i;
                back_track(level + 1);
                seq[j] = 0;
                seq[j + i + 1] = 0;
            }
        }

        is_used[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(is_used, false, sizeof(bool) * 13);
    memset(seq, 0, sizeof(int) * 24);
    int x, y, target;
    cin >> n;
    cin >> x >> y;
    
    target = y - x - 1;
    is_used[target] = true;
    seq[y - 1] = target;
    seq[x - 1] = target;

    back_track(1);

    //back_track(0);

    cout << how_many_answers;

    return 0;
}