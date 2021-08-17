#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool checked_message[26] = {true,};
    vector<pair<int, char>> messages;
    int people, msg_count, msg_answer;

    cin >> people >> msg_count >> msg_answer;
    msg_answer--;

    for(int i = 1; i <= msg_count; i++){
        pair<int, char> input;
        cin >> input.first >> input.second;
        messages.emplace_back(input);
    }

    if(messages[msg_answer].first == 0){
        cout << "-1\n";
        return 0;
    }

    for(int i = msg_count; i >= msg_answer || messages[msg_answer].first == messages[i].first; --i){
        checked_message[(int)(messages[i].second - 'A')] = true;
    }
    
    for(int i = 0; i < people; i++){
        if(!checked_message[i])
            cout << (char)(i + 'A') << ' ';
    }

    return 0;
}