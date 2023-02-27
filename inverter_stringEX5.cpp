/* Ex 5 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "seraoS ovatsuG"; // string a ser invertida
    int n = str.length();

    // inverte a string
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }

    // imprime a string invertida
    cout << "String invertida: " << str << endl;

    return 0;
}
