#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
    std::string s;
    std::vector<std::string> v;

    getline(std::cin, s);

    char arr[81];
    int arrLen = 0;

    for (unsigned int i = 0; i <= s.size(); i++)
    {   
        if (s[i] >= '0' && s[i] <= '9') {
            arr[arrLen] = s[i];
            arrLen++;
        } else {
            if (arrLen != 0) {
                arr[arrLen+1] = '\0';
                v.push_back(std::string(arr));
                arrLen = 0;
            }
        }
    }

    std::cout << "共有整数个数：" << v.size() << std::endl;
    for (auto val : v)
    {
        static int lineNumber = 1;
        int num = std::stoi(val);
        std::cout << lineNumber << ": " << num << std::endl;
        ++lineNumber;
    }
    
    return 0;
}