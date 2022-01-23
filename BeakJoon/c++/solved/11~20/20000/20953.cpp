#include<iostream>
#include<sstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 0;
    cin >> T;
    ostringstream strstream;

    for(int i = 0; i < T; i++){
        uint64_t a = 1, b = 1;
        cin >> a >> b;
        a += b;
        strstream << (a * a * a - a * a) / 2 << '\n';
    }
    cout << strstream.str();

    return 0;
}