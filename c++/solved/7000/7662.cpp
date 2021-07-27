#include<iostream>
#include<queue>
#include<unordered_map>
#include<functional>

using namespace std;

//여기 있는 이중 우선순위 큐가 돌아가는 방법은 lazy update이다.
//두 큐 모두 중간에 존재하지 않는 값 (반대 큐에는 없는 값)이 들어가 있을 수 있다.
//top이나 pop을 이용할 때, "제일 위에 있는"값만 신경쓰면 되므로, map에 정보를 개수 정보를 저장하고
//만약 반대 큐에서는 이미 없어진 값이었다면 완전히 소거한 다음 실제 제거, 참조 작업을 진행하는 것이다.

void app(){
    priority_queue<long> pq, rq;
    unordered_map<long, long> check;
    long n, input;
    char cmd;
    cin >> n;
    while(n--){
        cin >> cmd >> input;
        if(cmd == 'I'){
            //unordered_map에 어떤 값이 몇 개 들어있는지에 대한 완전한 정보를 저장한다.
            //이를 실제 큐에 반영하는 것은 top이나 pop을 이용해야할 때만 하면 된다.
            check[input]++;
            //값을 일반 큐와 리버스 큐(반대로 음수값을 붙여 저장, 최댓값을 반전시키는 효과.)에 push
            pq.push(input);
            rq.push(-input);
        } else { // cmd == 'D'
            if(input > 0){
                //큐가 비지 않았고, 최댓값에 대해서 check값이 0이라면.
                //즉, 최솟값을 지우면서 존재하지 않게된 값을 비운다.
                while(!pq.empty() && !check[pq.top()])
                    pq.pop();
                if(!pq.empty()){
                    check[pq.top()]--; //정말 존재하는 값을 지운 것이므로 반영
                    pq.pop();
                }
            } else {
                //큐가 비지 않았고, 최솟값에 대해서 check값이 0이라면.
                //즉, 최댓값을 지우면서 존재하지 않게된 값을 비운다.
                while(!rq.empty() && !check[-rq.top()])
                    rq.pop();
                if(!rq.empty()){
                    check[-rq.top()]--; //정말 존재하는 값을 지운 것이므로 반영
                    rq.pop();
                }
            }
        }
    }
    //허황된 값이 큐의 top에 위치하면 곤란하므로. 
    while(!pq.empty() && !check[pq.top()])
        pq.pop();
    while(!rq.empty() && !check[-rq.top()])
        rq.pop();
    
    //둘 중 하나라도 완전히 비었다면(아마 둘다 빌 것이다. 둘 다 업데이트를 하였으므로...)
    if(pq.empty() || rq.empty()){
        cout << "EMPTY\n";
    } else {
        cout << pq.top() << ' ' << -rq.top() << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while(n--){
        app();
    }

    return 0;
}