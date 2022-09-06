#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

typedef complex<double> base;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void fft(vector<base> &a, bool invert){
    //make number a as polynomial
    int n = sz(a);
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
    
    //actual transformation by dvq
    for(int len = 2; len <= n; len <<= 1){
        double ang = 2 * M_PI / len * (invert ? -1 : 1); //spin angle
        base wlen(cos(ang), sin(ang)); //apply spinning step w_n^k
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
        for(int i = 0; i < n; i++)
            a[i] /= n;
    }
}

void multiply(const vector<long long> &a, const vector<long long> &b, vector<long long> &res){
    vector<base> fa(all(a)), fb(all(b));
    //find smallest 2^n bigger than m
    int n = 1, m = sz(a) + sz(b) - 1;
    while(n < m) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for(int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    res.resize(n);
    for(int i = 0; i < m; i++) //floor values
        res[i] = (long long)(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    vector<long long> a, b, res;
    cin >> n;
  
    for(int i = 0; i < n; i++){
        long long input;
        cin >> input;
        a.push_back(input);
    }
    a.insert(a.end(), all(a));
    
    /*for(int i = 0; i < a.size(); i++){
        cout << a[i] << '\n';
    }*/
    
    for(int i = 0; i < n; i++){
        long long input;
        cin >> input;
        b.push_back(input);
    }
    reverse(all(b));
    
    multiply(a, b, res);
    
    /*for(int i = 0; i < sz(res) - 1; i++){
        if(res[i] >= 10){
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }
    }
    
    //final digit needs to be pushed back
    if(res.back() >= 10)
        res.push_back(res.back() / 10);
    
    //leading zero remove
    while(!res.empty() && res.back() == 0)
        res.pop_back();
    
    //if res == 0 then push back 0 again
    if(res.empty())
        res.push_back(0);
    
    reverse(all(res));*/
    
    long long ans = 0;
    for(long long i : res)
        ans = max(i, ans);
    cout << ans;
    
	return 0;
}
