#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long maximum = 0;
    string N;
    cin >> N;
    sort(N.begin(), N.end());

    do{
        for(int i = 1; i < N.size(); i++){
            string l, r;
            for(int j = 0; j < i; j++) 
                l += N[j];
            for(int j = i; j < N.size(); j++) 
                r += N[j];
            if(l[0] != '0' && r[0] != '0')
                maximum = max(maximum, stol(l) * stol(r));
        }
    } while(next_permutation(N.begin(), N.end()));

    cout << maximum;

    return 0;
}