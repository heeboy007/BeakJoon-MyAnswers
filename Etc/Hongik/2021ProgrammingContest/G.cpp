#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, idx = 1, list_idx = -1;
    vector<int> place;
    ostringstream output;
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        int input;
        cin >> input;
        if(input)
            place.push_back(i);
    }

    for(int i = 0; i < q; i++){
        int input, input2;
        vector<int>::iterator it;
        cin >> input;
        switch (input)
        {
        case 1:
            cin >> input2;
            if((it = find(place.begin(), place.end(), input2)) == place.end()){
                place.insert(std::upper_bound (place.begin(), place.end(), input2), input2);
            } else {
                place.erase(it);
            }
            break;
        case 2:
            cin >> input2;
            idx = (idx + input2) % n;
            if(!idx)
                idx = n;
            if(place.empty())
                list_idx = -1;
                break;
            while(place[list_idx] < idx && list_idx < place.size())
                list_idx++;
            if(list_idx == place.size())
                list_idx = 0;
            else
                list_idx--;
            break;
        case 3:
            if(place.empty())
                output << "-1\n";
            else{
                int count = 0;
                int start = idx;
                if(place[list_idx] < idx){
                    output << (n - idx + place[list_idx]) << '\n';
                } else {
                    output << (place[list_idx] - idx) << '\n';
                }
            }
            break;
        }
    }

    cout << output.str();

    return 0;
}