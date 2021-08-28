#include<iostream>

using namespace std;

long long fibs[100];

long long fibo(int n){
    if(n == 0 || n == 1){
        return fibs[n];
    }
    else if(fibs[n] > 0){
        return fibs[n];
    }
    else{
        return fibs[n] = (fibs[n - 2] > 0 ? fibs[n - 2] : fibo(n - 2)) + 
            (fibs[n - 1] > 0 ? fibs[n - 1] : fibo(n - 1));
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < 100; i++){
        fibs[i] = -1; //not using memset here.
        //memset is supposed to set BYTES not TYPES.
    }

    fibs[0] = 0;
    fibs[1] = 1;

    cout << fibo(n);

    return 0;
}