#include<iostream>

using namespace std;

int a, b;
int count = 0;
int where = 1;
int numbers[10];

void backtrack(int i, int m){
    if(i == m){
        if(a <= where && where <= b)
            for(int j = 0; j < m; j++)
                if(numbers[j] == 0)
                    count++;
        where++;
        return;
    }
    for(int j = (i ? 0 : 1); j <= 9; j++){
        numbers[i] = j;
        backtrack(i + 1, m);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        count = 0;
        where = 1;
        cin >> a >> b;
        for(int m = 1; where <= b; m++){
            backtrack(0, m);
        }
        cout << count + (a ? 0 : 1) << '\n';
    }

    return 0;
}