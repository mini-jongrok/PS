#include <iostream>
#include <deque>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
deque<int> party[51];
set<int> truth;
bool person_graph[51][51];

void input();
void solve();
void find_truth();

int main()
{
    input();
    solve();
    return 0;
}

void solve() {
    int ret = m;

    find_truth();

    for (int i = 0; i < m; ++i)
    {
        for (auto & t : truth)
        {
            if (find(party[i].begin(), party[i].end(), t) != party[i].end())
            {
                ret--;
                break;
            }
        }
    }
    cout << ret << "\n";
}

void find_truth()
{
    bool visit[51];
    memset(visit, false, sizeof(visit));
    deque<int> q;
    for (auto & t : truth)
    {
        q.push_back(t);
        visit[t] = true;
    }
    while (q.size())
    {
        int p = q.front();
        q.pop_front();
        for (int i = 1; i < n + 1; ++i)
        {
            if (i == p)
                continue;
            if (person_graph[p][i] == true && visit[i] == false)
            {
                q.push_back(i);
                visit[i] = true;
                truth.insert(i);
            }
        }
    }
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(person_graph, false, sizeof(person_graph));
    cin >> n >> m;
    int truth_num;
    cin >> truth_num;
    for (int i = 0; i < truth_num; ++i)
    {
        int tmp;
        cin >> tmp;
        truth.insert(tmp);
    }
    
    for (int i = 0; i < m; ++i)
    {
        int participant_num;
        cin >> participant_num;
        for (int j = 0; j < participant_num; ++j)
        {
            int tmp;
            cin >> tmp;
            party[i].push_back(tmp);
        }

        for (int j = 0; j < party[i].size(); ++j)
        {
            int person_row = party[i][j];
            for (int k = j + 1; k < party[i].size(); ++k)
            {
                int person_col = party[i][k];
                person_graph[person_row][person_col] = true;
                person_graph[person_col][person_row] = true;
            }
        }
    }
}