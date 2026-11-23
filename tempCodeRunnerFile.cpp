#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<long long> karatsuba(vector<long long> a, vector<long long> b) {
    int n = a.size();
    vector<long long> res(2 * n, 0);
    if (n <= 4) {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                res[i + j] += a[i] * b[j];
        return res;
    }
    int h = n / 2;
    // пополам
    vector<long long> a0(a.begin(), a.begin() + h);
    vector<long long> a1(a.begin() + h, a.end());
    vector<long long> b0(b.begin(), b.begin() + h);
    vector<long long> b1(b.begin() + h, b.end());

    // Суммы половин (a0 + a1) и (b0 + b1), без переносов
    vector<long long> sa(h), sb(h);
    for (int i = 0; i < h; i++) {
        sa[i] = a0[i] + a1[i];
        sb[i] = b0[i] + b1[i];
    }

    // Три рекурсивных умножения
    vector<long long> z0 = karatsuba(a0, b0);
    vector<long long> z2 = karatsuba(a1, b1);
    vector<long long> z1 = karatsuba(sa, sb);

    // z1 = (a0+a1)*(b0+b1) - z0 - z2
    for (int i = 0; i < 2 * h; i++) {
        z1[i] -= z0[i] + z2[i];
    }

    // Собираем: z0 + z1 * B^h + z2 * B^(2h), то есть сдвиги на h и 2h разрядов
    for (int i = 0; i < 2 * h; i++) {
        res[i] += z0[i];
        res[i + h] += z1[i];
        res[i + 2 * h] += z2[i];
    }
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = 1;
    while (n < (int)s1.length() || n < (int)s2.length())
        n *= 2;

    // в массивы преобразование
    vector<long long> a(n, 0), b(n, 0);
    for (int i = 0; i < (int)s1.length(); i++) 
        a[i] = s1[s1.length() - 1 - i] - '0';
    for (int i = 0; i < (int)s2.length(); i++)
        b[i] = s2[s2.length() - 1 - i] - '0';
    vector<long long> c = karatsuba(a, b);
    // перенос
    int len = 2 * n;
    for (int i = 0; i < len - 1; i++) {
        c[i + 1] += c[i] / 10;
        c[i] = c[i] % 10;
    }

    while (len > 1 && c[len - 1] == 0) 
        len--;
    for (int i = len - 1; i >= 0; i--) 
        cout << c[i];
    cout << endl;

    return 0;
}