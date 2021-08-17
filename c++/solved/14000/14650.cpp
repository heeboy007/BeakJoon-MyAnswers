#include<iostream>

using namespace std;

int counter = 0;

//sum until now, depth left to explore.
void rescursive(int sum, int depth){
    if(!depth){
        if(!(sum % 3))
            counter += 1;
        return;
    }
    rescursive(sum + 0, depth - 1);
    rescursive(sum + 1, depth - 1);
    rescursive(sum + 2, depth - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    rescursive(1, n - 1);
    rescursive(2, n - 1);

    cout << counter;

    return 0;
}