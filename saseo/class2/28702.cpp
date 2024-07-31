#include <iostream>
#include <string>
using namespace std;

void printStr(const int & num);
int getNum(const string& str);

int main() {
    string first, second, third, forth;
    cin >> first >> second >> third;

    int first_i, second_i, third_i, forth_i;
    first_i = getNum(first);
    second_i = getNum(second);
    third_i = getNum(third);

    if (first_i != 0)
        printStr(first_i + 3);
    else if (second_i != 0)
        printStr(second_i + 2);
    else
        printStr(third_i + 1);
    return 0;
}

void printStr(const int & num) {
    int r_three = num % 3;
    int r_five = num % 5;
    if (r_three == 0 && r_five == 0)
        cout << "FizzBuzz";
    else if (r_three == 0)
        cout << "Fizz";
    else if (r_five == 0)
        cout << "Buzz";
    else
        cout << num;
    cout << "\n";
}

int getNum(const string& str) {
    if (str.compare("Fizz") == 0 || str.compare("Buzz") == 0 || str.compare("FizzBuzz") == 0)
        return 0;
    return stoi(str, nullptr, 10);
}