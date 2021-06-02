#include <iostream>
#include <cmath>

bool checkin_point(std::string ipAdr) {
    int point = 0;
    int l = ipAdr.length() - 1;
    if (ipAdr[0] == 46 || ipAdr[l] == 46) {
        return false;
    } else {
        for (int i = 1; i < l; ++i) {
            if (ipAdr[i] == 46 && (ipAdr[i - 1] == 46 || ipAdr[i + 1] == 46)) {
                return false;
            } else if (ipAdr[i] == 46) {
                ++point;
            }
        }
    }
    if (point == 3) {
        return true;
    } else {
        return false;
    }
}

bool checking_part(std::string part) {
    int l = part.length() - 1;
    int dig = 0;
    if (l > 0 && part[0] == '0' || part.length() > 3) {
        return false;
    } else {
        for (int i = 0; i <= l; ++i) {
            if (part[i] < 48 || part[i] > 57) {
                return false;
            } else {
                dig += (part[i] - '0') * pow(10, (l - i));
            }
        }
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
            if (ipAdr[i] != 46) {
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
