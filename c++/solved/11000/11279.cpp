#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, less<int>> pq;
    int n;
    cin >> n;
    while(n--){
        int input;
        cin >> input;
        if(input){
            pq.push(input);
        } else{
            if(pq.empty()){
                cout << "0\n";
            } else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}