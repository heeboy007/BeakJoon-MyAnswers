#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char str[20];
    int n = 0, index = 0, ans = 1; 
    cin >> n;

    for(int i = 0; i < n; i++){
        if(index % 10 == 6){
            string comp = to_string(index);
            int mode = 1;
            for(int j = comp.length() - 1; j >= 0; j--){
                if(comp[j] == '6')
                    mode *= 10;
                else
                    break;
            }
            
            char format_a[15] = "%d666%0xd\n";
            char format_b[15] = "666%0xd\n";
            format_a[7] = (int)log10l(mode) + 48;
            format_b[5] = (int)log10l(mode) + 48;

            for(int j = 0; j < mode; j++){
                if(index / mode){
                    sprintf(str, format_a, index / mode, j);
                }
                else{
                    sprintf(str, format_b, j);
                }
                i++;
                if(i == n){
                    break;
                }
            }
            i--;
        }
        else{
            if(index)
                sprintf(str, "%d666\n", index);
            else
                sprintf(str, "666\n");
        }
        index++;
    }

    printf(str);

    return 0;
}