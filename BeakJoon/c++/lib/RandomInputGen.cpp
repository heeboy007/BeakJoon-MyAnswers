#include <random>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, dp[1001];
vector<pair<int,int>> V;

//here번째 여행을 출발 하고 나서 부터 가능한 최소 공백
int solve(int here){
	if(here == m) return 0;
	int &ret = dp[here];
	if(ret != -1) return ret;

	ret = 10000;
	for(int i=here+1; i<m; ++i){
		//여행 일정이 겹치면 패스한다.
		if(V[i].first <= V[here].second) continue;
		ret = min(ret, max(V[i].first - V[here].second -1, solve(i)));
	}
	//여행을 더 이상 가지 않는 경우
	ret = min(ret, n - V[here].second);
	return ret;
}

//Thanks for Green55 for comparing the answers, couldn't done without him...
int right(){
	sort(V.begin(), V.end());
	memset(dp, -1, sizeof(dp));
	int ans = 1000;
	for(int i=0; i<m; ++i){
		//V[i].first-1 = 처음 여행 출발 전까지의 공백
		ans = min(ans, max(V[i].first-1,solve(i)));
	}
	return ans;
}

int wrong(vector<vector<int>> travels){
    pair<int, int> dp[1001];
    //vector<vector<int>> travels(1001);

    dp[0].first = 0;
    dp[0].second = 0;

    int last = 0;
    for(int i = 1; i <= n; i++){
        if(!travels[i].empty()){
            int minimum = 1001;
            for(int start : travels[i]){
                for(int j = 1; j <= start; j++)
                    minimum = min(max(start - dp[j - 1].second - 1, dp[j - 1].first), minimum);
            }
            dp[i].first = minimum;
            dp[i].second = i;
        } else {
            dp[i] = dp[i - 1];
        }
    }

    int minimum = 1001;
    for(int j = 1; j <= n; j++)
        minimum = min(max(n - dp[j - 1].second, dp[j - 1].first), minimum);
    minimum = min(max(n - dp[n].second, dp[n].first), minimum);

    return minimum;
}

bool app(){
    std::random_device rd;
    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    std::mt19937 gen(rd());
    // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    std::uniform_int_distribution<int> dis(1, 100);

    vector<pair<int, int>> travels;
    vector<vector<int>> travels_2(1001);

    n = dis(gen);
    m = dis(gen);

    std::uniform_int_distribution<int> dis_2(1, n);
    int a, b;
    for(int i = 0; i < m; i++){
        a = dis_2(gen);
        b = dis_2(gen);
        if(a < b){
            travels.push_back({a, b});
            travels_2[b].push_back(a);
        }
        else{
            travels.push_back({b, a});
            travels_2[a].push_back(b);
        }
    }
    V.clear();
    V = travels;

    int w = wrong(travels_2);
    int r = right();
    if(w != r){
        cout << "Found, Inputs are : \n";
        cout << n << '\n' << m << '\n';
        for(pair<int, int> p : travels){
            cout << p.first << ' ' << p.second << '\n';
        }
        return false;
    }
    return true;
}

int main(){
    int trying = 0;
    while(app()){
        cout << "Try : " << ++trying << '\n';
        cout << "Not Found, Keep Finding.\n";
    }
}