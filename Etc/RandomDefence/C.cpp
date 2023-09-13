#include<iostream>
#include<queue>

using namespace std;

int a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> a >> b;
    queue<pair<int, int>> matches, done;
    for(int i = 1; i <= n; i += 2){
        pair<int, int> match;
        match.first = i;
        match.second = i+1;
        if(i == n  && (n % 2)){
            match.first = match.second = i;
        }
        matches.push(match);
    }
    int round = 1;
    while(round){
        int index = 1;
        while(!matches.empty()){
            pair<int, int> match1 = matches.front();
            matches.pop();
            if(match1.first <= a && a <= match1.second && match1.first <= b && b <= match1.second){
                cout << round;
                return 0;
            } else {
                if((index % 2)){
                    if(matches.size() == 2){
                        done.push( { match1.first, n } );
                    } else {
                        done.push( { match1.first, matches.front().second } );
                    }
                }
            }
            index++;
        }
        while(!done.empty()){
            matches.push(done.front());
            done.pop();
        }
        round++;
    }

    return 0;
}