#include <iostream>
#include <vector>
using namespace std;

int highest = 0;
vector<vector<int>> g;

int test(vector<int> &students) {
    int total = 0;
    total += g[students[0]][students[1]];
    total += g[students[1]][students[0]];

    total += g[students[1]][students[2]];
    total += g[students[2]][students[1]];

    total += g[students[2]][students[3]] * 2;
    total += g[students[3]][students[2]] * 2;

    total += g[students[3]][students[4]] * 2;
    total += g[students[4]][students[3]] * 2;
    return total;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void f(vector<int> &students, int size = 5) {
    if (size == 1) {
        int a = test(students);
        if (a > highest) highest = a;
        return;
    }
    for (int i = 0; i < size; i++) {
        f(students,size-1);
        if (size % 2 == 0)
            swap(students[i], students[size-1]);
        else
            swap(students[0], students[size-1]);
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        vector<int> gi(5);
        for (int j = 0; j < 5; j++)
            cin >> gi[j];
        g.push_back(gi);
    }
    
    vector<int> students = {0,1,2,3,4};
    f(students);
    cout << highest << endl;
    return 0;
}
