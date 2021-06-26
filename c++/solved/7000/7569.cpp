#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Data_Person
{
    int weight;
    int tall;
    int score;
} Person;

bool compare(Person *p1, Person *p2){
    if(p1->tall < p2->tall && p1->weight < p2->weight){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<Person> persons; 
    cin >> N;
    
    for(int i = 0; i < N; i++){
        Person p;
        cin >> p.weight >> p.tall;
        p.score = 0;
        persons.push_back(p);
    }

    for(int i = 0; i < N; i++){
        Person *curr_com = &persons[i];
        int score = 1;
        for(int j = 0; j < N; j++){
            Person *next_com = &persons[j];
            if(compare(curr_com, next_com))
                score++;
        }
        curr_com->score = score;
    }

    for(Person p : persons){
        cout << p.score << ' ';
    }
    return 0;
}