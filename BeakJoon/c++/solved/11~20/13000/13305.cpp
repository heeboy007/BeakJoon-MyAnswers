#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int track[n], stops[n];
    for(int i = 1; i < n; i++)
        cin >> track[i];
    for(int i = 0; i < n; i++)
        cin >> stops[i];
    
    int min_cost = stops[0];
    long long money = 0;
    for(int i = 1; i < n; i++){
        money += min_cost * (long long)track[i];
        min_cost = min(min_cost, stops[i]);
    }
    cout << money;

    return 0;
}