/* EX 4 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

int main() {
    ifstream file("dados.json");
    json billing_data;
    file >> billing_data;

    vector<double> billing_amounts;
    for (auto& record : billing_data) {
        int day = record["dia"].get<int>();
        double value = record["valor"].get<double>();
        if (day >= 1 && day <= 28) {
            billing_amounts.push_back(value);
        }
    }

    double min_value = *min_element(billing_amounts.begin(), billing_amounts.end());
    double max_value = *max_element(billing_amounts.begin(), billing_amounts.end());
    double avg_value = accumulate(billing_amounts.begin(), billing_amounts.end(), 0.0) / billing_amounts.size();
    int days_above_avg = 0;
    for (auto& value : billing_amounts) {
        if (value > avg_value) {
            days_above_avg++;
        }
    }

    cout << "Menor valor de faturamento: " << min_value << endl;
    cout << "Maior valor de faturamento: " << max_value << endl;
    cout << "Número de dias em que o faturamento foi maior do que a média: " << days_above_avg << endl;

    return 0;
}
