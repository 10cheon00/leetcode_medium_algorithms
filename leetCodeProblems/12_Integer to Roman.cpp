#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        char roman[8] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
        int index = 6, remainder;
        string result = "";

        while (num) {
            remainder = num % 10;
            if (remainder == 4) {
                // 5+1
                result.push_back(roman[index - 1]);
                result.push_back(roman[index]);
            }
            else if (remainder == 9) {
                // 9+1
                result.push_back(roman[index - 2]);
                result.push_back(roman[index]);
            }
            else {
                // just push
                for (int i = 0; i < remainder % 5; ++i) {
                    result.push_back(roman[index]);
                }
                if (remainder >= 5) {
                    result.push_back(roman[index - 1]);
                }
            }
            index -= 2;
            num /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


int main() {
    /*
    I   =   1
    V   =   5

    X   =   10
    L   =   50

    C   =   100
    D   =   500

    M   =   1000

    4와 9를 나타내기 위해서,
    I+V => IV == 4,
    I+X => IX == 9,
    C+D => CD == 400,
    이런 방법을 사용함.
    */
    Solution* s = new Solution();
    printf("%s", s->intToRoman(2568).c_str());
}