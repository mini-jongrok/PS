#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void    addDays(map<string, int>& priv_date, int months);
void    makeTerm(map<string, int>& term_map, vector<string> terms);
void    dateToInt(map<string, int>& m_date, string date);

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> term_map;
    makeTerm(term_map, terms);
    map<string, int> i_today;
    dateToInt(i_today, today);
    
    for (int i = 0; i < privacies.size(); ++i)
    {
        map<string, int> priv_date;
        istringstream   iss(privacies[i]);
        string date;
        string term_type;
        iss >> date >> term_type;
        dateToInt(priv_date, date);

        // type에 따라 priv_date + expire date
        addDays(priv_date, term_map[term_type]);
        // today 와 대소비교. priv_date > today : 보존.
        if (priv_date["YEAR"] < i_today["YEAR"])
            answer.push_back(i + 1);
        else if (priv_date["YEAR"] == i_today["YEAR"] && \
                priv_date["MONTH"] < i_today["MONTH"])
            answer.push_back(i + 1);
        else if (priv_date["YEAR"] == i_today["YEAR"] && \
                priv_date["MONTH"] == i_today["MONTH"] &&\
                priv_date["DAY"] < i_today["DAY"])
            answer.push_back(i + 1);
    }
    return answer;
}

void addDays(map<string, int>& priv_date, int months)
{
    // 일단 하루 제거
    priv_date["DAY"] -= 1;
    if (priv_date["DAY"] == 0)
        priv_date["DAY"] = 28, priv_date["MONTH"] -= 1;
    if (priv_date["MONTH"] == 0)
        priv_date["MONTH"] = 12, priv_date["YEAR"] -= 1;
    
    // months 더해주기.
    priv_date["YEAR"] += months / 12;
    priv_date["MONTH"] += months % 12;
    if (priv_date["MONTH"] > 12)
        priv_date["MONTH"] %= 12, priv_date["YEAR"] += 1;
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
