#include<iostream>

using namespace std;

long lines[10003];

long get_count(long mid, int k){
    long curr_total = 0;
    for(int i = 0; i < k; i++){
        curr_total += lines[i] / mid;
    }
    return curr_total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n = 0, k = 0; 
    long start = 1, end = 1;
    cin >> k >> n;
    for(int i = 0; i < k; i++){
        cin >> lines[i];
        if(lines[i] > end)
            end = lines[i];
    }

    long mid = (start + end) / 2;
    while(start < end){
        long result = get_count(mid, k);
        if(result >= n) //enough go right!
            start = mid;
        else  //not enough go left!
            end = mid;
        mid = (start + end) / 2;
        //cout << start << '/' << mid << '/' << end << '/' << result << '\n';

        if(start == mid){
            if(get_count(mid, k) == get_count(mid + 1, k)){
                start++;
                mid++;
            } else {
                end--;
            }
        }

        //cout << start << '/' << mid << '/' << end << '\n';
    }

    cout << mid;

    return 0;
}