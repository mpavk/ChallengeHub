struct Solution;

impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
      for i in 0..nums.len() {
        if nums[i] == target || nums[i] > target {
           return i as i32;
        }
      }
      nums.len() as i32
    }

    pub fn max_profit_easy(prices: Vec<i32>) -> i32 {
      let mut max_profit = 0;
      let mut temp = prices[0];
      for i in 0..prices.len() - 1 {
        if temp > prices[i+1] {
          temp = prices[i+1];
          continue;
        } else if temp < prices[i+1] {
            if prices[i+1] - temp > max_profit {
              max_profit = prices[i+1] - temp;
            }
        }
      }
      max_profit
    }

    pub fn max_profit(prices: Vec<i32>) -> i32 {
      let mut max_profit = 0;
      let mut max_profit_sum = 0;
      let mut temp = prices[0];
      for i in 0..prices.len() - 1 {
        if temp > prices[i+1] {
          temp = prices[i+1];
          max_profit_sum = max_profit_sum + max_profit;
          continue;
        } else if temp < prices[i+1] {
          if prices[i+1] - temp > max_profit {
            max_profit = prices[i+1] - temp;
          }
        }
      }
      max_profit_sum
    }
}

fn main() {
  // println!("{}", Solution::search_insert(vec![1, 3, 4], 5)); [7,1,5,3,6,4]
  println!("{}", Solution::max_profit(vec![7,1,5,3,6,4]));
  println!("{}", Solution::max_profit(vec![7,6,4,3,1]));

}
