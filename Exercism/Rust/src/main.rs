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
}

fn main() {
    println!("{}", Solution::search_insert(vec![1, 3, 4], 5));
}
