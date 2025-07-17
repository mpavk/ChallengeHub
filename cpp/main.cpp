#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

    // 26. Remove Duplicates from Sorted Array
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }

        int unique_index = 1;
        for(int i = 1; i < nums.size(); i++) {
            if((nums[i] != nums[i-1])) {
                nums[unique_index] = nums[i];
                unique_index++;
            }
        }

        return unique_index;
    }


    //121. Best Time to Buy and Sell Stock
    int maxProfit(vector<int>& prices) {
        int max_sum = 0;
        int max = prices[0];
        int min = prices[0];

        for(int i = 0; i < prices.size(); i++){
            if (prices[i] > max) {
                max = prices[i];
            }

            if (prices[i] < min || (i == prices.size() - 1)) {
                if (max_sum < max - min) {
                    max_sum = max - min;
                }
                max = prices[i];
                min = prices[i];
            }
        }
        return max_sum;
    }


};

int main(int argc, char *argv[]) {
    Solution s;
    std::vector<int> nums = {7,1,5,3,6,4};
    std::cout<<s.maxProfit(nums)<<std::endl;
    return 0;
}
