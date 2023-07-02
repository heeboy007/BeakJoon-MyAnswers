//AC

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    while(n--){
        string s;
        cin >> s;
        
        bool is_re = false;
        int until = s.size() / 2;
        char prev = s[0];
        for(int i = 0; i < until; i++){
            //cout << "Prev : " << prev << '\n';
            //cout << "Curr : " << s[i] << '\n'; 
            if(prev != s[i]){
                is_re = true;
                break;
            }
            prev = s[i];
        }
        
        cout << (is_re ? "YES\n" : "NO\n");
    }

    return 0;
}
