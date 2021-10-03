#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, sorted = 0;
    cin >> c;
    
    vector<int> n;
    vector<int> temp;

    for(int i = 0; i < c; i++){
        int input;
        cin >> input;
        n.push_back(input);
    }

    cout << "3\n";
    for(int i = 1; i <= c / 4 + sorted; i++){
        if(i == n[i - 1]){
            sorted++;
            continue;
        }
        temp.push_back(i);
        temp.push_back(n[i - 1]);
        cout << i << ' ' << n[i - 1] << ' ';
    }

    sort(temp.begin(), temp.end());
    cout << '\n';    

    for(int i = c / 4 + 1; i <= c / 2; i++){
        temp.push_back(i);
        temp.push_back(n[i - 1]);
        cout << i << ' ' << n[i - 1] << ' ';
    }

    sort(temp.begin(), temp.end());
    cout << '\n';

    for(int i = c / 2; i < c; i++){
        cout << n[i] << ' ';
    }
    cout << '\n';

    return 0;
}