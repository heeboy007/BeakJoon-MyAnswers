#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <complex>

using namespace std;
typedef complex<double> base;

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()

void fft(vector<base> &a, bool invert){
    int n = SZ(a);
    for(int i = 1, j = 0; i < n; i++){
        int bit = n >> 1;
        while(j >= bit){
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if(i < j)
            swap(a[i], a[j]);
    }
    
    for(int len = 2; len <= n; len <<= 1){
        double ang = 2 * M_PI / len * (invert ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for(int i = 0; i < n; i += len){
            base w(1);
            for(int j = 0; j < len / 2; j++){
                base u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    
    if(invert){
        for(int i = 0; i < n; i++){
            a[i] /= n;
        }
    }
}

void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res){
    vector<base> fa(ALL(a)), fb(ALL(b));
    int n = 1, m = SZ(a) + SZ(b) - 1;
    while(n < m) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for(int i = 0; i < n; i++){
        fa[i] *= fb[i];
    }
    fft(fa, true);
    res.resize(n);
    for(int i = 0; i < n; i++){
        res[i] = (int)abs(round(fa[i].real()));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, count = 0;
    vector<int> a(200005), res;
    cin >> n;
    a[0] = 1;
	while(n--){
	    int input;
	    cin >> input;
	    a[input] = 1;   
	}
    multiply(a, a, res);

    /*for(int i = 0; i < a.size(); i++){
        cout << i << " : " << a[i] << '\n';
    }*/

    cin >> m;
    while(m--){
        int input;
        cin >> input;
        if(res[input]){
            count++;
        }
    }
    
    /*for(int i = 0; i < 100; i++){
        cout << i << " : " << res[i] << '\n';
    }*/
    
    cout << count;
    
	return 0;
}
