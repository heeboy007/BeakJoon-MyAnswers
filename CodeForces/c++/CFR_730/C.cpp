#include<iostream>

using namespace std;

#define Epsilon 0.00000000001

double chance(double c, double m, double p, double v, int depth){
    double output = p * depth;
    bool is_c_valid = c > Epsilon, is_m_valid = m > Epsilon;
    if(is_c_valid){ //c is valid
        double choose_c = min(v, c);
        if(is_m_valid) //m is valid
            output += c * chance(c - choose_c, m + choose_c / 2, p + choose_c / 2, v, depth + 1);
        else //m is invalid
            output += c * chance(c - choose_c, 0.0, p + choose_c, v, depth + 1);
    }
    if(is_m_valid){ //invalid
        double choose_m = min(v, m);
        if(is_c_valid) //m is valid
            output += m * chance(c + choose_m / 2, m - choose_m, p + choose_m / 2, v, depth + 1);
        else //m is invalid
            output += m * chance(0.0, m - choose_m, p + choose_m, v, depth + 1);
    }
    return output;
}

void app(){
    double c, m, p, v;
    cin >> c >> m >> p >> v;
    cout << chance(c, m, p, v, 1) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(13);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        app();
    }

    return 0;
}