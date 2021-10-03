/*
 *  About naming rules
 *  1. All directory names must have CFR_ prefix.
 *  2. If contest has a number, the number is the main name.
 *  3. It contest doesn't have a number, make up a good acronym to be the main name.
 *  4. If vituraly anticipated the contest, add suffix _V.
 */

#include<iostream>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char output[101];

    int t;
    cin >> t;

    while(t--){
        memset(output, 0, sizeof(output));

        int n;
        string row;
        cin >> n >> row;
        for(int i = 0; i < row.length(); i++){
            switch (row[i])
            {
            case 'U':
                output[i] = 'D';
                break;
            case 'D':
                output[i] = 'U';
                break;
            default:
                output[i] = row[i];
                break;
            }
        }        

        cout << output << '\n';
    }

    return 0;
}