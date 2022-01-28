#include<iostream>

using namespace std;

int counter(int n) {
    int i;
    for(i=0; n != 0; i++)
        n &= (n - 1);
    return i;
}

int maxbits(int n){
    int i = 1; 
    while (n = (n >> 1))
        ++i;
    return i;
}

void prob(){
    int n, target, up_count = 1;
    cin >> n >> target;
    if(counter(target) > (maxbits(n) - 1) / 2){
        cout << "-1\n"; 
        return;
    } else if(!target){
        int arr[n / 2] = { 0 }, count = 0;
        for(int i = 0; i < n / 4; i++){
            cout << i << ' ' << n - i - 1<< ' ';
        }
        cout << '\n';
        for(int i = n / 4; i < n / 2; i++){
            cout << i << ' ' << n - i - 1<< ' ';
        }
        cout << '\n';
    } else {
        int arr[n / 2] = { 0 }, count = 1;
        arr[0] = target;
        for(int i = 1; i < n; i = i << 1){
            if(target & i)
                continue;
            else
                arr[count++] = target ^ i;
        }
        cout << "0 ";
        for(int i = 0; i < n; i++){
            int x = i ^ target;
            if(x == (x&-x))
                continue;
            if(((i & target) == target) || count >= n / 2)
                arr[count++] = i;
            else
                cout << i << ' ';
        }
        cout << '\n';
        for(int i = 0; i < n / 2; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        prob();
    }

    return 0;
}