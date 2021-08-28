#include<iostream>
#include<cstring>

using namespace std;

int main(){

    int block_height[257];
    int n, m, b;
    int min = 64000001, min_layer = 0;
    cin >> n >> m >> b;

    memset(block_height, 0, sizeof(block_height));

    for(int i = 0; i < m * n; i++){
        int input;
        cin >> input;
        block_height[input]++;
    }
    
    for(int i = 0; i < 257; i++){
        int upper_sum = 0, fill_sum = 0; 
        for(int j = 0; j < 257; j++){
            if(j >= i)
                upper_sum += (j - i) * block_height[j];
            else
                fill_sum += (i - j) * block_height[j];
        }
        if(fill_sum <= b + upper_sum){
            if(min >= fill_sum + upper_sum * 2){
                min = fill_sum + upper_sum * 2;
                min_layer = i;
            }
        }
        //cout << min << ' ' << min_layer << '\n';
    }

    cout << min << ' ' << min_layer;

    return 0;

}