#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    int n;
    int a[1000];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    for (int i = 0; i < n; ++i){
        if (i == n - 1){
            cout << a[i] << "." << endl;
            break;
        }
        cout << a[i] << ", ";
    }
    return 0;
}