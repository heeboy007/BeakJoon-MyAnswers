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

int number[10];

int considerAll(int depth){
    if(depth == 1){
        return (number[depth] + 1 - max(number[depth] - 9, 0) * 2) * considerAll(0);
    } else if(depth == 0){
        return (number[depth] + 1 - max(number[depth] - 9, 0) * 2);
    } else {
        //try sus mode
        int ways = 0;
        number[depth - 2] += 10;
        ways += (number[depth] - max(number[depth] - 10, 0) * 2) * considerAll(depth - 1);
        number[depth - 2] -= 10;
        ways += (number[depth] + 1 - max(number[depth] - 9, 0) * 2) * considerAll(depth - 1);
        return ways;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, length;
        cin >> n;

        for(int i = 0; i < 10; i++)
            number[i] = 0;

        for(int i = 0; i < 10; i++){
            number[i] = n % 10;
            n /= 10;
            if(!n){
                length = i;
                break;
            }
        }

        cout << (considerAll(length) - 2) << '\n';
    }

    return 0;
}