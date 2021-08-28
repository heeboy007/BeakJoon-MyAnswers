#include<iostream>
#include<cmath>

using namespace std;

double distance(pair<int, int> c1, pair<int, int> c2){
    return sqrt((c1.first - c2.first) * (c1.first - c2.first) + (c1.second - c2.second) * (c1.second - c2.second));
}

pair<int, int> indexing(pair<int, int> start, pair<int, int> end, int index){
    index %= 4;
    switch (index)
    {
    case 0:
        return start;
    case 1:
        return {start.first, end.second};
    case 2:
        return end;
    case 3:
        return {start.second, end.first};
    }
    return {0, 0};
}

void app(){
    pair<int, int> box, box2;
    pair<int, int> cord1, cord2;
    pair<int, int> face_from, face_to;
    int index_info;
    cin >> box.first >> box.second;
    cin >> cord1.first >> cord1.second >> cord2.first >> cord2.second;
    cin >> box2.first >> box2.second;
    double dist = -1.0;
    bool invalid_x = (cord2.first - cord1.first + box2.first) > box.first;
    bool invalid_y = (cord2.second - cord1.second + box2.second) > box.second;
    if(invalid_x && invalid_y){
        cout << "-1\n";
        return;
    }
    double result;
    for(int i = 0; i < 4; i++){
            index_info = i;
            face_from = indexing({0, 0}, box, index_info);
            face_to = indexing(cord1, cord2, index_info);
            pair<int, int> abs_dist = {box2.first - abs(face_from.first - face_to.first), box2.second - abs(face_from.second - face_to.second)};
            
            if(abs_dist.first < abs_dist.second){
                if(invalid_x)
                    result = (double)abs_dist.second;
                else
                    result = (double)abs_dist.first;
            } else {
                if(invalid_y)
                    result = (double)abs_dist.first;
                else
                    result = (double)abs_dist.second;
            }
        if()
    }
    if(result <= 0.0){
        cout << "0\n";
    } else {
        cout << result << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--){
        app();
    }

    return 0;
}