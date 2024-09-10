#include <iostream>
#include <string>
#include <format>

std::string convertDateToBinary(std::string date) {
    std::string buf {};
    std::string res {};

    for (int i = 0; i < std::size(date); i++) {
        buf += date[i];

        if (date[i] == '-' || i == (std::size(date) - 1)) {
            int dt = std::stoi(buf);
            buf = "";

            //res += std::format("{:b}", dt);
            // представление в бинарном виде можно переписать
            // просто переводить циклом while
            std::string rv {};
            while (dt > 0) {
                if (dt % 2 == 0) {
                    rv = "0" + rv;
                } else {
                    rv = "1" + rv;
                }

                dt /= 2;
            }

            res += rv;

            if (date[i] == '-') {
                res += "-";
            }
        }
    }

    return res;
}

int main() {
    
    std::cout << convertDateToBinary("2080-02-29") << std::endl;
    
    return 0;
}