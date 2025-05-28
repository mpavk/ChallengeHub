#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int max = 0;
        for (auto &str : strs ) {
            for (int j = 0; j < str.length(); j++) {
                if (( str[j]>= 65 && str[j] <= 90) || ( str[j]>= 97 && str[j] <= 122)) {
                    if(str.length() > max){
                        max = str.length();
                    }
                    break;
                } else if (j == str.length()-1){
                    if(stoi(str) > max){
                        max = stoi(str);
                        break;
                    }
                }
            }
        }
        return max;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
