#include<iostream>
#include<unordered_map>
#include<stack>
#include<cstdio>

using namespace std;

unordered_map<char, pair<int, int>> matrix;

int check(string line){
    stack<char> s;
    stack<pair<int, int>> previous;
    int count = 0;
    for(int i = 0; i < line.length(); i++){
        if(line[i] == '('){
            //make dummy
            if(previous.size() < s.size())
                previous.push({0, 0});
            s.push('(');
        }
        else if(line[i] == ')'){
            if(previous.size() >= s.size()){
                pair<int, int> b = previous.top();
                previous.pop();
                if(!previous.empty()){
                    if(previous.top().first == 0){
                        previous.top() = b;
                    } else {
                        if(previous.top().second != b.first)
                            return -1;
                        count += previous.top().first * b.first * b.second;
                        previous.top().second = b.second;
                    }
                }
            }
            s.pop();
        }
        else {
            if(previous.size() < s.size())
                previous.push(matrix[line[i]]);
            else {
                if(!previous.empty()){
                    if(previous.top().first == 0){
                        previous.pop();
                        previous.push(matrix[line[i]]);
                    } else {
                        pair<int, int> a = previous.top(), b = matrix[line[i]];
                        if(a.second != b.first)
                            return -1;
                        count += a.first * b.first * b.second;
                        a.second = b.second;
                        previous.pop();
                        previous.push(a);
                    }
                }
            }
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char ch;
        pair<int, int> input;
        cin >> ch >> input.first >> input.second;
        matrix[ch] = input;
    }
    string line;
    getline(cin, line);
    while(getline(cin, line)){
        int result = check(line);
        if(result == -1)
            cout << "error\n";
        else
            cout << result << '\n';
    }

    return 0;
}