#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>

std::time_t Now() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(now);
}
auto FormatTime(time_t time, bool is_utc_format) {
#if defined(_MSC_VER)
    #pragma warning(push)
    #pragma warning(disable: 4996)
#elif defined(__GNUC__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

    return is_utc_format
           ? std::put_time(std::gmtime(&time), "%x %X")
           : std::put_time(std::localtime(&time), "%x %X");

#if defined(_MSC_VER)
    #pragma warning(pop)
#elif defined(__GNUC__)
    #pragma GCC diagnostic pop
#endif
}

void writeLog(std::ofstream &log, std::string s){
    log << FormatTime(Now(), false) << " | " << s << '\n';
}

void checkOpening(std::ofstream &log, std::fstream &fil, std::string s, bool t){
    writeLog(log, "Пытаемся открыть файл \"" + s + '\"');
    if(t) fil.open(s, std::ios::in);
    else fil.open(s, std::ios::out);
    if(!fil){
        writeLog(log, "Не удалось открыть \"" + s + '\"');
        exit(-1);
    } else writeLog(log, "Файл \"" + s + "\" успешно открыт");
}

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

void solve(const std::string& s, std::fstream &output, std::ofstream &log){
    //std::string ans = "";
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
        if(t){
            writeLog(log, "Найден IPv4-адрес " + ips[i]);
            output << ips[i] << '\n';
            writeLog(log, "Адрес записан в output.txt");
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //std::cout << FormatTime(Now(), false);
    std::string s;
    std::ofstream log("log.txt");
    if(!(log)){
        exit(-1);
    }
    std::fstream input;
    std::fstream output;
    checkOpening(log, input, "input.txt", 1);
    checkOpening(log, output, "output.txt", 0);
    writeLog(log, "Читаем входные данные из input.txt");
    std::getline(input, s);
    writeLog(log, "Прочитана строка: " + s);
    writeLog(log, "Начинаем поиск IPv4-адресов");
    solve(s, output, log);

    input.close();
    output.close();
    log.close();
    return 0;
}
