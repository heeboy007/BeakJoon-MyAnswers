#include<iostream>
#include<cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //원래 이렇게 푸는것 보다는 그냥 판별식을 이용하는게 맞아보이지만 뭐 어땡
    int t;
    cin >> t;
    while(t--){
        int a1, b1, a2, b2, result;
        double r1, r2, r;
        cin >> a1 >> b1 >> r1 >> a2 >> b2 >> r2;
        r = sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
        if(r1 < r2){ //정렬, r1이 언제나 크다.
            double t = r2;
            r2 = r1;
            r1 = t;
        }
        if(r > r1){ //두 원의 중심이 서로의 밖에 있음.
            if(r > r1 + r2) //만나지 않음
                result = 0;
            else if(r == r1 + r2) // 접함.
                result = 1;
            else // 두 번 만남.
                result = 2;
        } else if(r == r1){ //두 원중 하나의 중심이 다른 원의 반지름에 위치
            result = 2; //0 < r2 < r1 == r 이므로 언제나 2번 만남.
        } else if(r > 0.0){ //하나의 중심이 반지름 내부에 있음.
            if(r1 > r + r2)
                result = 0; //만나지 않음
            else if(r1 == r + r2) 
                result = 1; //접함
            else
                result = 2; //두번 만남
        } else{ //두원의 중심이 일치
            result = (r1 == r2 ? -1 : 0);
        }
        cout << result << '\n';
    }

    return 0;
}