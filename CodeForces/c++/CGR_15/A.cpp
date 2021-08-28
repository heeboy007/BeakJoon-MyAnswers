#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    string input, copy;
    while(t--){
        int length, count = 0;
        input.clear();
        copy.clear();
        cin >> length;
        cin >> input;
        copy = input;
        sort(input.begin(), input.end());

        for(int i = 0; i < length; i++){
            if(copy[i] != input[i]){
                count++;
            }
        }
        cout << count << '\n';
    }

    return 0;
}