struct Solution {}

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for i in 0..nums.len() {
            for j in i + 1..nums.len() {
                if (nums[i] + nums[j]) == target {
                    return vec![i as i32, j as i32];
                }
            }
        }
        vec![]
    }

    pub fn maximum_value(strs: Vec<String>) -> i32 {
        let mut max = 0;

        for s in strs {
            match s.parse::<i32>() {
                Ok(number) => {
                    if number > max {
                        max = number;
                    }
                }
                Err(e) => {
                    if s.len() as i32 > max {
                        max = s.len() as i32;
                    }
                }
            }
        }

        max
    }
}
fn main() {
    Solution::maximum_value(vec!["gtrfds".to_string()]);
}
