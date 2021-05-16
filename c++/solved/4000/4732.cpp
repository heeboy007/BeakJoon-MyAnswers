#include<iostream>
#include<vector>
#include<regex>
#include<string>

using namespace std;
const char* bnotes[] = {"-", "Bb", "Cb", "B#", "Db", "-", "Eb", "Fb", "E#", "Gb", "-", "Ab"};
const char* rnotes[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

bool is_integer(const std::string & s){
    return std::regex_match(s, std::regex("-?[0-9]+"));
}

int note_to_int(const string & s){
    int return_int = 0;
    int i = 0;
    for(const char * note : rnotes){
        if(s == note){
            return_int = i;
        }
        i++;
    }
    i = 0;
    for(const char * note : bnotes){
        if(s == note){
            return_int = i;
        }
        i++;
    }
    return return_int;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    do{
        vector<int> notes = vector<int>();

        do{
            string input;
            cin >> input;
            if(input == "***"){
                return 0;
            } else if(is_integer(input)){
                int move = std::stoi(input) % 12;
                for(int note : notes){
                    int alt = note + move;
                    if(alt < 0){
                        alt += 12;
                    } else if (alt >= 12){
                        alt -= 12;
                    }
                    cout << rnotes[alt] << ' ';
                }
                cout << '\n';
                break;
            } else {
                notes.push_back(note_to_int(input));
            }
        } while(true);
    } while(true);

    return 0;
}