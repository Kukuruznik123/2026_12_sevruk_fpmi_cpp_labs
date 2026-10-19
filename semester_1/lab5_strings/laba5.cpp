#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> crush(const std::string& s, char ch){
    std::vector<std::string> ans;
    std::string word = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ch){
            if(word != "") ans.push_back(word);
            word = "";
        }
        else word += s[i];
    }
    ans.push_back(word);
    return ans;
}

std::string solve(const std::string& s){
    std::string ans = "";
    std::vector<std::string> ips = crush(s, ' ');
    for(int i = 0; i < ips.size(); i++){
        std::vector<std::string> ip = crush(ips[i], '.');
        if(ip.size() != 4) continue;
        bool t = true;
        for(int j = 0; j < 4; j++){
            int val = 0;
            for(int h = 0; h < std::min(int(ip[j].size()), 4); h++){
                int ascii = (int)ip[j][h];
                if(ip[j].size() > 1 && val == 0 && ascii == 48){
                    val = -1;
                    break;
                }
                if(ascii >= 48 && ascii <= 57){
                    val = val * 10 + (ascii - 48);
                } else {
                    val = -1;
                    break;
                }
            }
            if(val < 0 || val > 255){
                t = false;
                break;
            }
        }
        if(t) ans = ans + ips[i] + ' ';
    }
    return ans;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string s;
    std::cout << "Введите что душе угодно, а я найду среди всего текста валидные IPv4-адреса\n";
    std::getline(std::cin, s);
    std::cout << solve(s);


    return 0;
}
