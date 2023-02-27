/* EX 4 */
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // Define o faturamento de cada estado em um mapa
    map<string, double> faturamento = {
        {"SP", 67836.43},
        {"RJ", 36678.66},
        {"MG", 29229.88},
        {"ES", 27165.48},
        {"Outros", 19849.53}
    };

    // Calcula o faturamento total
    double faturamento_total = 0.0;
    for (auto const& [estado, valor] : faturamento) {
        faturamento_total += valor;
    }

    // Calcula e imprime o percentual de representação de cada estado
    for (auto const& [estado, valor] : faturamento) {
        double percentual = (valor / faturamento_total) * 100.0;
        cout << "O estado " << estado << " representa " << percentual << "% do faturamento total\n";
    }

    return 0;
}
