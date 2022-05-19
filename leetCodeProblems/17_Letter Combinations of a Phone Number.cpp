#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    char letterMap[8][5] = {
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
    int letterMapLength[8] = { 3,3,3,3,3,4,3,4 };
public:
    vector<string>letterCombinations(string digits) {
        vector<string> answer;

        if (digits.length() == 0) {
            return answer;
        }

        int mapIndex[4] = { 0, };
        int casesNumber = 1, casesCount = 0;
        for (int i = 0; i < digits.length(); ++i) {
            casesNumber *= letterMapLength[digits[i] - '2'];
        }
        
        while(casesCount++ < casesNumber){
            // generate answer
            string result = "";
            for (int i = 0; i < digits.length(); ++i) {
                result.push_back(letterMap[digits[i] - '2'][mapIndex[i]]);
            }
            answer.push_back(result);
            // increase indexes
            mapIndex[0]++;
            for (int i = 0; i < digits.length(); ++i) {
                if (mapIndex[i] == letterMapLength[digits[i] - '2']) {
                    mapIndex[i] = 0;
                    if (i < 3) {
                        mapIndex[i + 1]++;
                    }
                }
            }
        }
        return answer;
    };
};


int main() {
    Solution* s = new Solution();
    s->letterCombinations("5678");
    delete s;
}