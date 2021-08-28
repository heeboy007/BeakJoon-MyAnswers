#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, counter = 0, curr_height = -1, max = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        if(input > curr_height){
            curr_height = input;
            counter = 0;
        } else {
            counter++;
        }
        max = (counter > max ? counter : max);
    }

    cout << max;

    return 0;
}