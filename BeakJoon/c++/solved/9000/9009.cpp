#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 44;
    int fib[44] = {
        1,
        1,
        2,
        3,
        5,
        8,
        13,
        21,
        34,
        55,
        89,
        144,
        233,
        377,
        610,
        987,
        1597,
        2584,
        4181,
        6765,
        10946,
        17711,
        28657,
        46368,
        75025,
        121393,
        196418,
        317811,
        514229,
        832040,
        1346269,
        2178309,
        3524578,
        5702887,
        9227465,
        14930352,
        24157817,
        39088169,
        63245986,
        102334155,
        165580141,
        267914296,
        433494437,
        701408733,
    };

    int t;
    cin >> t;
    while(t--){
        stack<int> p;
        int x;
        cin >> x;
        for(int i = n - 1; i > 0 && x; i--){
            if(fib[i] <= x){
                p.push(fib[i]);
                x -= fib[i];
            }
        }

        while(!p.empty()){
            int output = p.top();
            p.pop();
            cout << output << ' ';
        }
        cout << '\n';
    }

    return 0;
}