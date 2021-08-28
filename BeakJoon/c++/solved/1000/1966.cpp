#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, int> Doc;

void app(){
    int count_per_prio[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int track, doc_count, print = 1;
    queue<Doc*> docs;

    cin >> doc_count >> track;
    for(int i = 0; i < doc_count; i++){
        Doc* doc = new Doc();
        doc->first = i;
        cin >> doc->second;
        count_per_prio[doc->second]++;
        docs.push(doc);
    }

    for(int i = 9; i >= 0; i--){
        while(count_per_prio[i] > 0){
            Doc* doc;
            do{
                doc = docs.front();
                docs.pop();
                if(doc->second == i){ //print it!
                    break;
                } else {
                    docs.push(doc);
                }
            } while(true);

            if(doc->first == track){
                cout << print << '\n';
                return;
            }

            delete doc;

            count_per_prio[i]--;
            print++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        app();
    }

    return 0;
}