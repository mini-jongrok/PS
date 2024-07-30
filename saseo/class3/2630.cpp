#include <iostream>
#include <utility>

using namespace std;
int n;
int paper[130][130];

void input();
pair<int, int> seperate(pair<int, int> left_top, int length);
bool isSingleColor(pair<int, int> left_top, int length);

int main() {
    input();
    pair<int, int> result = seperate(make_pair(0, 0), n);
    cout << result.first << "\n" << result.second << "\n";
    return 0;
}

pair<int, int> seperate(pair<int, int> left_top, int length) {
    if (length < 1)
        return make_pair(0, 0);
    if (isSingleColor(left_top, length) == true) {
        int color = paper[left_top.first][left_top.second];
        if (color == 0) return make_pair(1, 0);
        return make_pair(0, 1);
    }
    // 네 개로 구역을 나눠서 값을 리턴받는다.
    int half = length / 2;
    pair<int, int> parts[4];
    parts[0] = seperate(left_top, half);
    parts[1] = seperate(make_pair(left_top.first, left_top.second + half), half);
    parts[2] = seperate(make_pair(left_top.first + half, left_top.second), half);
    parts[3] = seperate(make_pair(left_top.first + half, left_top.second + half), half);

    pair<int, int> res = make_pair(0, 0);
    for (int i = 0; i < 4; ++i) {
        res.first += parts[i].first;
        res.second += parts[i].second;
    }
    return res;
}

bool isSingleColor(pair<int, int> left_top, int length) {
    bool res = true;
    int color = paper[left_top.first][left_top.second];
    for (int i = left_top.first; i < left_top.first + length; ++i) {
        for (int j = left_top.second; j < left_top.second + length; ++j) {
            int tmp = paper[i][j];
            if (tmp != color)
                return false;
        }
    }
    return res;
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> paper[i][j];
    }
}