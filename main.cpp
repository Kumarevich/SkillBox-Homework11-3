#include <iostream>
#include <cmath>
#include <string>

bool checkin_point(std::string ipAdr) {
    int point = 0;
    int l = ipAdr.length() - 1;
    if (ipAdr[0] == '.' || ipAdr[l] == '.') {
        return false;
    } else {
        for (int i = 1; i < l; ++i) {
            if (ipAdr[i] == '.') {
                if (ipAdr[i - 1] == '.' || ipAdr[i + 1] == '.') {
                    return false;
                } else {
                    ++point;
                }
            }
        }
    }
    return (point == 3);
}

bool checking_part(std::string part) {
    int l = part.length() - 1;
    int dig = 0;
    if ((l > 0 && part[0] == '0') || l >= 3) {
        return false;
    } else {
        dig = std::stoi(part);
    }
    if (dig < 0 || dig > 255) {
        return false;
    } else {
        return true;
    }
}

bool checking_ip(std::string ipAdr) {
    std::string part = "";
    int l = ipAdr.length() - 1;
    if (!checkin_point(ipAdr)) {
        return false;
    } else {
        for (int i = 0; i <= l; ++i) {
            if (ipAdr[i] != '.') {
                part += ipAdr[i];
            } else {
                if (!checking_part(part)) {
                    return false;
                } else {
                    part = "";
                }
            }
        }
    }
    return true;
}

int main() {
    std::cout << "Input IP: ";
    std::string ipAdr;
    std::cin >> ipAdr;
    if (checking_ip(ipAdr)) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
    return 0;
}
