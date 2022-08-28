#include <iostream>
using namespace std;

int n, count = 0;
bool is_blocked[20];
int how[20];

void backtrack(int detph){
    if(detph == n){
        //for(int i = 0; i < n; i++)
        //    cout << i + 1 << ',' << how[i] << " / ";
        //cout << '\n';
        count++;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!is_blocked[i]){
            bool is_usable = true;
            for(int j = 0; j < detph; j++)
                if(abs(how[j] - i) == abs(j - detph))
                    is_usable = false;
            if(is_usable){
                how[detph] = i;
                is_blocked[i] = true;
                backtrack(detph + 1);
                how[detph] = 0;
                is_blocked[i] = false;
            }
        }
    }
}

int main() {
    cin >> n;
    backtrack(0);
    cout << count;
	return 0;
}
