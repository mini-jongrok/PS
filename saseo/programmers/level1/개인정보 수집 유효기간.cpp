#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void    addDays(string& date, const int& months);
void    dateToInt(map<string, int>& m_date, string date);
void    makeTerm(map<string, int>& term_map, vector<string> terms);

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> term_map;
    makeTerm(term_map, terms);
    
    for (int i = 0; i < privacies.size(); ++i)
    {
        istringstream   iss(privacies[i]);
        string date;
        string term_type;
        iss >> date >> term_type;
        addDays(date, term_map[term_type]);
        if (date <= today)
            answer.push_back(i + 1);
    }
    return answer;
}

void    addDays(string& date, const int& months)
{
    map<string, int> map_date;
    dateToInt(map_date, date);
    
    // months 더해주기.
    map_date["YEAR"] += months / 12;
    map_date["MONTH"] += months % 12;
    if (map_date["MONTH"] > 12)
        map_date["MONTH"] %= 12, map_date["YEAR"] += 1;
    
    // date 변경
    ostringstream oss;
    oss << map_date["YEAR"] << ".";
    if (map_date["MONTH"] < 10) oss << "0";
    oss << map_date["MONTH"] << ".";
    if (map_date["DAY"] < 10) oss << "0";
    oss << map_date["DAY"];
    date = oss.str();
}

void    dateToInt(map<string, int>& m_date, string date)
{
    // date string pattern : YYYY.MM.DD
    vector<string> date_type = {"YEAR", "MONTH", "DAY"};
    vector<vector<int> > ranges = {{0, 4}, {5, 2}, {8, 2}};
    
    for (int i = 0; i < date_type.size(); ++i)
    {
        int tmp = stoi(date.substr(ranges[i][0], ranges[i][1]));
        m_date[date_type[i]] = tmp;
    }
}

void    makeTerm(map<string, int>& term_map, vector<string> terms)
{
    for (int i = 0; i < terms.size(); ++i)
    {
        string term_type;
        int expire_duration;
        istringstream   iss;
        iss.str(terms[i]);
        iss >> term_type >> expire_duration;
        term_map[term_type] = expire_duration;
    }
}
