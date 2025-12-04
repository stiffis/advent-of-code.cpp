#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

bool is_general_rep(std::string s) {
    int L = s.size();
    for (int tam_patron = 1; tam_patron <= L / 2; tam_patron++) {
        if (L % tam_patron != 0)
            continue;
        std::string patron = s.substr(0, tam_patron);
        bool coincide = true;
        for (int i = tam_patron; i < L; i += tam_patron) {
            if (s.substr(i, tam_patron) != patron) {
                coincide = false;
                break;
            }
        }
        if (coincide)
            return true;
    }
    return false;
}

long long sum_range(std::string range) {
    long long sum_rang = 0;
    size_t pos = range.find('-');
    std::string a = range.substr(0, pos);
    std::string b = range.substr(pos + 1);
    long long A = stoll(a);
    long long B = stoll(b);
    for (long long i = A; i <= B; i++) {
        if (is_general_rep(std::to_string(i))) {
            sum_rang += i;
        }
    }
    return sum_rang;
}

int main() {
    std::ifstream archivo("input");

    long long res = 0;
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string range;
        while (std::getline(ss, range, ',')) {
            res += sum_range(range);
        }
    }

    std::cout << "Sum of ID's: " << res << std::endl;
    archivo.close();
    return 0;
}
