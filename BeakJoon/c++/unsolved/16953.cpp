#include <bits/stdc++.h>
using namespace std;

//킹늘의 교훈 : DFS도 좋을 때가 있다.

long A, B, answer=10000000;

void dfs(long cur, long depth){
    if(B<cur) {return;}
    
    if(cur==B){
        answer= min(answer, depth); return;
    }
    
    dfs(cur*2, depth+1);
    dfs((cur*10)+1, depth +1);
}
int main(){
    cin>>A>>B;
    dfs(A,1);
    
    cout<<(answer==10000000? -1:answer)<<"\n";
    return 0;
}