#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int chartoint(char ch){
    if(ch <= 'Z'){
        ch -= 65;
    } else {
        ch -= 97;
    }
    return (int)ch;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    int arr[26];
    int max = 0;
    char output = '?';

    for(int i = 0; i < 26; i++){
        arr[i] = 0;
    }

    for(char ch : str){
        if(++arr[chartoint(ch)] > max){
            max = arr[chartoint(ch)];
        }
    }

    for(int i = 0; i < 26; i++){
        if(arr[i] == max){
            if(output != '?'){
                output = '?';
                break;
            } else {
                output = (char)(i + 65);
            }
        }
    }
    cout << output;

    return 0;
}