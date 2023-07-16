#include <iostream>
#include <cmath>

using namespace std;

double dist(pair<int, int> a, pair<int, int> b){
    return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}

int main()
{
    cout.precision(0);
    
    pair<int, int> p[4];
    for(int i = 0; i < 4; i++){
        cin >> p[i].first >> p[i].second;
    }
    
    double ia = dist(p[0], p[1]);
    double ib = dist(p[0], p[2]);
    double ic = dist(p[0], p[3]);
    double ab = dist(p[1], p[2]);
    double ac = dist(p[1], p[3]);
    double bc = dist(p[2], p[3]);

    double minimum = 90000.0;
    
    minimum = (minimum > (ia + ab + bc) ? (ia + ab + bc) : minimum);
    minimum = (minimum > (ia + ac + bc) ? (ia + ac + bc) : minimum);
    minimum = (minimum > (ib + ab + ac) ? (ib + ab + ac) : minimum);
    minimum = (minimum > (ib + bc + ac) ? (ib + bc + ac) : minimum);
    minimum = (minimum > (ic + ac + ab) ? (ic + ac + ab) : minimum);
    minimum = (minimum > (ic + bc + ab) ? (ic + bc + ab) : minimum);
    
    cout << (int)minimum;
    
    return 0;
}
