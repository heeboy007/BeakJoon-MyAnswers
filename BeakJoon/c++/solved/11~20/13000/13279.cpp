
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

#define INT long long
#define MOD 100003
 
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
        //base wlen(cos(ang), sin(ang));
        for(int i = 0; i < n; i += len){
            //base w(1);
            for(int j = 0; j < len / 2; j++){
                //base u = a[i + j], v = a[i + j + len / 2] * w;
                base u = a[i + j], v = a[i + j + len / 2] * base(cos(ang * j), sin(ang * j));
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                //w *= wlen;
            }
        }
    }
    
    if(invert){
        for(int i = 0; i < n; i++){
            a[i] /= n;
        }
    }
}

void multiply(const vector<INT> &a, const vector<INT> &b, vector<INT> &res){
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
        res[i] = (INT)abs(round(fa[i].real())) % MOD;
    }
}

vector<INT> inputs;

vector<INT> dnq(INT index, INT size){
    vector<INT> res;
    if(size == 2){
        //cout << index << ':' << inputs[index] << '\n';
        //cout << index + 1 << ':' << inputs[index + 1] << '\n';
        multiply({inputs[index], 1}, {inputs[index + 1], 1}, res);
        return res;
    }
    vector<INT> res1, res2;
    INT curr = size >> 1;
    res1 = dnq(index, curr);
    res2 = dnq(index + curr, curr);
    multiply(res1, res2, res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m = 1, offset = 0;
    vector<INT> res;
    cin >> n;
    
    if(n == 1){
        int input;
        cin >> input;
        cin >> n;
        cin >> n;
        cout << input % MOD;
        return 0;
    }
    
    while(m < n) m <<= 1;
    
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        inputs.push_back(input);
    }
    inputs.resize(m);
    
    res = dnq(0, m);
    
    offset = res.size();
    
    while(!res[offset - 1]){
        res.pop_back();
        --offset;
    }
    
    cin >> n;
    while(n--){
        int input;
        cin >> input;
        cout << res[offset - input - 1] << '\n';
    }
    
    return 0;
}
