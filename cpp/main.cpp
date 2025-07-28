#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <map>

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

    //217. Contains Duplicate
    bool containsDuplicate(vector<int>& nums) {
        std::map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1) return true;
        }
        return false;
    }

    bool containsDuplicate1(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }

    //283. Move Zeroes
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[insertPos] = nums[i];
                insertPos++;
            }
        }

        for (int i = insertPos; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }

    //15. 3Sum
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) {
                break;
            }
            // Уникаємо дублікатів для першого елемента
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                long long sum = (long long)nums[i] + nums[left] + nums[right]; // Використовуємо long long

                if (sum == 0) {
                    result.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }

    //56. Merge Intervals
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
                return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i = 0; i < intervals.size(); i++) {
            vector<int>& last_merged = result.back();
            vector<int>& current = intervals[i];

            if(last_merged[1] >= current[0]) {
                last_merged[1] = max(last_merged[1], current[1]);
            } else {
                result.push_back(current);
            }
        }

        return result;
    }

    //238. Product of Array Except Self
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = nums[0];
        int zero_mark = 0;

        for (int i = 1; i < nums.size(); i++) {
            if(sum == 0 && zero_mark == 0 ) {
                sum = nums[i];
                zero_mark++;
                continue;
            }

            if(nums[i] != 0) {
                sum *= nums[i];
            } else {
                zero_mark++;
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(zero_mark == 0) {
                nums[i] = sum / nums[i];
            } else if(zero_mark == 1  && nums[i] == 0) {
                nums[i] = sum;
            } else {
                nums[i] = 0;
            }
        }

        return nums;
    }
    
    //238. Product of Array Except Self
    std::vector<int> productExceptSelf2(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n, 1);
        int prefix_product = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix_product;
            prefix_product *= nums[i];
        }
        int postfix_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= postfix_product;
            postfix_product *= nums[i];
        }

};

void printVectorPairs(std::vector<std::vector<int>> &intervals){
    for(auto &interval: intervals) {
        std::cout<<interval[0] << " " << interval[1] << std::endl;
    }
}

int main(int argc, char *argv[]) {
    Solution s;
    std::vector<int> nums = {1,0};
    std::vector<std::vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    std::cout << intervals.size() << std::endl;

    // printVectorPairs(intervals);
    // sort(intervals.begin(), intervals.end());
    // printVectorPairs(intervals);
    s.merge(intervals);
    return 0;
}
