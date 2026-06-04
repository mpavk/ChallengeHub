#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <string_view>

using namespace std;

void printVectorPairs(std::vector<std::vector<int>> &intervals){
    for(auto &interval: intervals) {
        std::cout<<interval[0] << " " << interval[1] << std::endl;
    }
}

void printVector(std::vector<int> &arr){
    for(auto &num: arr) {
        std::cout<<num << " ";
    }
    std::cout<<std::endl;
}

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
    vector<int> productExceptSelf2(std::vector<int>& nums) {
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
        return result;
    }

    //551. Student Attendance Record I

    bool checkRecord(string s) {
        int absent = 0, late = 0;
        for(auto ch: s){
            if(ch == 'A'){
                late = 0;
                absent++;
                if(absent > 2) {
                    return false;
                }
           } else if (ch == 'L') {
               late++;
               if(late > 2){
                   return false;
               }
           } else {
               late = 0;
           }
        }
        return true;
    }

    std::vector<int> productQueries(int n, std::vector<std::vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        std::vector<int> powers;
        for (int i = 0; i < 31; ++i) {
            if ((n >> i) & 1) {
                powers.push_back(1 << i);
            }
        }
        std::vector<int> answers;
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            long long product = 1;
            for (int j = left; j <= right; ++j) {
                product = (product * powers[j]) % MOD;
            }
            answers.push_back(static_cast<int>(product));
        }

        return answers;
    }

    //2839. Check if Strings Can be Made Equal With Operations I
    bool canBeEqual(string s1, string s2) {
        if (s1 == s2) return true;
        for(int i = 0, j = 2; i < s1.size() && j < s1.size(); i++, j++) {
            char temp = s1[i];
            if (s1[i]!=s2[i]){
                s1[i] = s1[j];
                s1[j] = temp;
            }
            if (s1 == s2) return true;
        }
        return false;
    }

    // 3101. Count Alternating Subarrays
    long long countAlternatingSubarrays(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        long long total_count = 0;
        int current_streak = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                current_streak++;
            } else {
                current_streak = 1;
            }
            total_count += current_streak;
        }
        return total_count;
    }

    bool isPalindrome(int x) {
        long int reversed = 0;
        int temp_number = x;

        if (x < 0) return false;

        while (temp_number != 0) {
            reversed = (reversed * 10) + (temp_number % 10);
            temp_number /= 10;
        }
        return (reversed == x);
    }

    int removeElement(vector<int>& nums, int val) {
        int count = nums.size() - 1;
        if (count == -1 ) {
            return 0;
        } else if (count == 0 && nums[0] != val ){
            return 1;
        }

        int i = 0;
        while(i != (count + 1)){
            if(nums[i] == val){
                if(nums[count] != val){
                    swap(nums[i], nums[count]);
                } else {
                    count--;
                }
            } else {
                i++;
            }
        }

        return count;
    }

    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        return "";
    }

    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            else if (nums[mid] < target) {
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }
        return left;
    }

    int lengthOfLastWord(string s) {
        int length = 0;
        for(int i = s.length() - 1 ; i >= 0; i--){
            if(s[i]== ' ' && length == 0){
                continue;
            } else if (s[i] == ' ' && length != 0){
                return length;
            } else{
                length++;
            }
        }
        return length;
    }

    bool repeatedSubstringPattern(string s) {
        if (s.empty()) {
                return false;
        }
        std::string t = s + s;
        return t.find(s, 1) != s.length();
    }

    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1;
        int curr = 1;
        for (int i = 2; i <= n; i++) {
            int next = prev + curr;
            prev = curr;
            curr = next;
        }
        return curr;
    }

    int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2){
            return 1;
        }
        int fibCurrent = 1;
        int fibPrev = 1;
        int temp = fibCurrent;
        for(int i = 3; i<=n; i++){
           temp = fibCurrent;
           fibCurrent = fibCurrent + fibPrev;
           fibPrev = temp;
        }
        return fibCurrent;
    }

    bool isHappy(int n) {
        std::unordered_set<int> seenNumbers;
        while (n != 1 && seenNumbers.find(n) == seenNumbers.end()) {
            seenNumbers.insert(n);
            int sumOfSquares = 0;
            int currentNumber = n;
            while (currentNumber > 0) {
                int digit = currentNumber % 10;
                sumOfSquares += digit * digit;
                currentNumber /= 10;
            }
            n = sumOfSquares;
        }
        return n == 1;
    }

    bool isUgly(int n){
        int i = 2;
        if (n<=0) {
            return false;
        }
        while(n != 1 && n != -1 ){
            if(n % i == 0){
                if(i>5){
                    if( i == n ) {
                        return false;
                    }
                    for(int j = 2; j <= sqrt(i);j++){
                       if (i%j == 0){
                           continue;
                       } else {
                           return false;
                       }
                   }
                }
                n = n/i;
                i = 1;
            }
            i++;
       }
        return true;
    }

    int formula(vector<vector<int>> arr, int i, int j){
        int sum = (arr[i][j-1] + arr[i][j] + arr[i][j-1]) + arr[i+1][j] + (arr[i+2][j-1] + arr[i+2][j] + arr[i+2][j-1]);
        return sum;
    }

    int hourglassSum(vector<vector<int>> arr) {
        int max_sum;
        for (int i = 0; i < arr.size()-1; i++) {
            for(int j = 0; j < arr[i].size()-1; j++){
                if (j-1>= 0 && j<=arr[i].size()){
                    if (i+2 < arr[i].size()) {
                        int sum = (arr[i][j-1] + arr[i][j] + arr[i][j+1]) + arr[i+1][j] + (arr[i+2][j-1] + arr[i+2][j] + arr[i+2][j+1]);
                        if (sum > max_sum) {
                            max_sum = sum;
                        }
                        sum = 0;
                    }
                }
            }
        }
        return max_sum;
    }

    vector<int> rotateLeft(int d, vector<int> arr) {
        std::vector<int> result(arr.size());
        for(int i = arr.size()-1; i >= 0;i--) {
            if (i - d < 0) {
                int f = (arr.size()) - (d-i);
                result[f] = arr[i];
            } else {
                result[i-d] = arr[i];
            }
        }
        return result;
    }

    vector<int> dynamicArray(int n, vector<vector<int>> queries) {
        std::vector<std::vector<int>> arr(n); // N порожніх векторів
        std::vector<int> result;
        int lastAnswer = 0;

        for (int i = 0; i < queries.size(); i++) {
            int type = queries[i][0];
            int x = queries[i][1];
            int y = queries[i][2];

            int idx = (x ^ lastAnswer) % n;

            if (type == 1) {
                arr[idx].push_back(y);
            }
            else if (type == 2) {
                int element_idx = y % arr[idx].size();
                lastAnswer = arr[idx][element_idx];
                result.push_back(lastAnswer);
            }
        }
        return result;
    }

    bool isValid(string s) {
        std::stack<char> st;
        for(auto ch: s){
            if (ch == '{' || ch == '[' || ch == '(') {
                st.push(ch);
            } else if (ch == ')' || ch == ']' || ch == '}') {
                if(st.empty()) return false;

                if( (ch == ')'  && st.top() == '(') || (ch == ']'  && st.top() == '[') || (ch == '}'  && st.top() == '{')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }

    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i >= 0; i--){
            if (digits[i] == 9 ){
                digits[i] = 0;
            } else {
                digits[i] = digits[i] + 1;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }

    bool wordPattern(string pattern, string s) {
        std::unordered_map<string_view, char> kv;
        std::unordered_set<char> char_keys;

        std::string_view sv(s);
        int start = 0;
        int p_idx = 0;
        string temp_str;
        while(start < sv.length()) {
            if(p_idx >= pattern.length()) return false;

            size_t end = sv.find(' ', start);
            if(end == std::string_view::npos){
                end = sv.length();
            }

            std::string_view word = sv.substr(start, end - start);
            char current_char = pattern[p_idx];

            auto it = kv.find(word);
            if (it != kv.end()){
                if (it->second != current_char) {
                    return false;
                }
            } else {
                if (char_keys.contains(current_char)) {
                    return false;
                }
               kv[word] = current_char;
               char_keys.insert(current_char);
            }
            start = end + 1;
            p_idx++;
        }
        return p_idx == pattern.length();
    }

    int singleNumber(vector<int>& nums) {
        int temp  = 0;
        for(int num : nums ){
            temp ^= num;
        }

        return temp;
    }

    int thirdMax(vector<int>& nums) {

    }

    int strStr(string haystack, string needle) {
        if (haystack == needle){
            return 0;
        }
        for(int i = 0; i <= haystack.size() - needle.size(); i++) {
            if (needle.size() > haystack.size()){
                return -1;
            }
            string temp_str = haystack.substr(i, needle.size());
            if (temp_str == needle) {
                return i;
            }
        }
        return -1;
    }

    void reverseString(vector<char>& s) {
        int j = s.size() - 1;
        for(int i = 0; i <= j; i++){
            char temp_s = s[j];
            s[j] = s[i];
            s[i] = temp_s;
            j--;
        }
    }

    char findTheDifference(string s, string t) {
        char temp_s = 0;
        char temp_t = t[t.size()-1];
        for (int i = 0; i < s.size(); i++){
            temp_s ^= s[i];
            temp_s ^= t[i];
        }
        return temp_t^temp_s;
    }

    vector<string> fizzBuzz(int n) {
        vector<string> numbers_string;
        for(int i = 1; i <= n; i++) {
            if (i%3 == 0 and i%5 == 0) {
                numbers_string.push_back("FizzBuzz");
            } else if (i%3 == 0) {
                numbers_string.push_back("Fizz");
            } else if (i%5==0) {
                numbers_string.push_back("Buzz");
            } else {
                numbers_string.push_back(std::to_string(i));
            }
        }
        return numbers_string;
    }

    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result(numRows);
        for (int i = 0; i < numRows; i++){
            result[i].resize(i+1, 1);
            for (int k = 1; k < i; k++) {
                result[i][k] = result[i - 1][k - 1] + result[i - 1][k];
            }
        }
        return result;
    }

    bool detectCapitalUse(string word) {
        int counter = 0;
        for(int i = 0; i < word.size(); i++ ){
            if (int(word[i])>= 65 && int(word[i]) <= 90){
                counter++;
            }
        }
        std::cout<<counter<<std::endl;
        if (counter == word.size()){
            return true;
        } else if( counter==1 and (int(word[0])>= 65 && int(word[0]) <= 90)) {
            return true;
        } else if (counter == 0 && word.size() != 0) {
            return true;
        }

        return false;
    }

    int firstUniqChar(std::string s) {
        int charCount[256] = {0};

        for(char c : s) {
            charCount[c]++;
        }

        int n = s.size();
        for(int i = 0; i < n; i++){
            if (charCount[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }

    string licenseKeyFormatting1(string s, int k) {

        int count = 0;
        for(char const& c: s){
            if(c != '-'){
                count++;
            }
        }

        string result = "";

        int counter_added_sym = 0;

        for(int i = s.size()-1; i>=0; i--){
            if (s[i]!= '-'){
                if(counter_added_sym>0 && counter_added_sym%k==0){
                    result.push_back('-');
                }

                result.push_back(toupper(s[i]));
                counter_added_sym++;
            }

        }
        reverse(result.begin(), result.end());
        return result;
    }

    string licenseKeyFormatting(string s, int k) {

        int count = 0;
        for(char const& c: s){
            if(c != '-'){
                count++;
            }
        }

        if(s.size() == 1 && s[0] == '-'){
            return "";
        }

        string result = "";

        int full_groups = 0;
        int balance = -1;
        full_groups = count/k;
        balance = count%k;
        int group_members_counter = 0;
        int group_counter = 1;
        int all_groups = (balance>0) ? full_groups+1 : full_groups;

        for(int i = 0; i < s.size(); i++){
            if (s[i]!= '-'){
                result.push_back(std::toupper(s[i]));
                group_members_counter++;

                if((balance == group_members_counter && balance != 0) || group_members_counter == k){
                    if(i != s.size()-1 && group_counter < all_groups){
                         result.push_back('-');
                    }
                     group_members_counter = 0;
                     group_counter++;
                     balance = -1;
                }
            }
        }

        return result;
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int counter = 0;

        for(int i = 0; i<flowerbed.size(); i++){
            if(flowerbed[i] == 0 ) {
                bool left = (i == 0) || ( flowerbed[i-1] == 0);
                bool right = (i == flowerbed.size()-1) || (flowerbed[i+1] == 0);

                if (left && right) {
                    flowerbed[i] = 1;
                    counter++;
                }

            }
        }

        if(counter >= n) {
            return true;
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    // s.generate(5);
    // std::cout<<s.licenseKeyFormatting1("--a-a-a-a--", 1)<<std::endl;
    // std::cout<<1%4<<std::endl;

    vector<int> v = {1,0,0,0,0,1};
    std::cout<<s.canPlaceFlowers(v, 2)<<std::endl;
}
