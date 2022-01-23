#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n, k;
    cin >> n;
    queue<long> q;
    for(int i = 0; i < n; i++){
        long input;
        cin >> input;
        q.push(input);
    }
    cin >> k;
    
    if(k == q.front()){
        cout << 'T';
        return 0;
    }

    bool up = (k < q.front());
    bool consistant = true;
    q.pop();

    for(int i = 2; i <= n; i++){
        if((k * i < q.front()) != up || (k * i == q.front())){
            consistant = false;
            break;
        }
        q.pop();
    }

    cout << (consistant ? 'F' : 'T');

    return 0;
}