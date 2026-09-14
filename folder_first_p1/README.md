# Industrial-programming

Практическое занятие 1

Автор: Литвак Кристина, ЭФБО-08-26
Задание 5

#include <iostream>
#include <vector>
using namespace std;


int main(){
    int c = 0;
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 9, 10};
    int n = v.size();
    for(int i = 0; i <= n; ++i){
        if (c != v[i]){
            cout << c;
            break;
        }
        ++c;
    }
}
