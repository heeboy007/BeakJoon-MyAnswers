#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void app(){
    int on, n, curr = 0, target = 0, addition;
    vector<int> a, b;

    cin >> n;
    on = n;
    addition = n / 4 - 1;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        curr += input;
        a.push_back(input);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n / 4; i++){
        curr -= a[i];
    }
    
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        target += input;
        b.push_back(input);
    }
    sort(b.begin(), b.end());
    for(int i = 0; i < n / 4; i++){
        target -= b[i];
    }

    while(curr < target){
        n++;
        if(!(n % 4)){
            if(on >= n / 4){
                curr -= a[n / 4 - 1];
            }
            else{
                curr -= 100;
            }
        } else {
            if(addition >= 0){
                target += b[addition];
                addition--;
            }
        }
        curr += 100;
        //cout << "Step : " << n << " Cur: " << curr << " Tar: " << target << '\n';
    }
    cout << n - on << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        app();
    }

    return 0;
}