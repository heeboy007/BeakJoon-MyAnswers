#include<iostream>

#define LL long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LL input;
    while(cin >> input){
      LL start = 1;
      int index = 1;
      while(start % input){
        start = start * 10 + 1;
        start %= input;
        index++;
      }
      cout << index << '\n';
    }
  
    return 0;
}