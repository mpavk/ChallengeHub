use std::collections::HashSet;

fn remove_whitespace(s: &str) -> String {
  s.chars().filter(|c| !c.is_whitespace()).collect()
}

/// Check a Luhn checksum.
///
pub fn is_valid_luhn_algorithm(code: &str) -> bool {
  let clear_code:String = remove_whitespace(code);

  if clear_code.len() <= 1 {
    return false;
  }

  let mut sum = 0;
  let mut is_second = false;

  for c in clear_code.chars().rev() {
    if let Some(digit) = c.to_digit(10) {
      let mut temp = digit;
      if is_second {
        temp*=2;
        if temp > 9 {
          temp -=9;
        }
      }
      sum+= temp;
      is_second = !is_second;
    } else {
      return false;
    }
  }

  sum % 10 == 0
}

pub fn is_armstrong_number(num: u32) -> bool {
  let string_num = num.to_string();
  let mut sum = 0;
  for i in string_num.chars() {
    sum += i.to_digit(10).unwrap().pow(string_num.len() as u32);
  }
  sum == num
}

pub fn square_of_sum(n: u32) -> u32 {
  let sum: u32 = (1..=n).sum();
  sum * sum
}


pub fn sum_of_squares(n: u32) -> u32 {
  (n*(n+1)*(2*n+1))/6
}

pub fn difference(n: u32) -> u32 {
  square_of_sum(n) - sum_of_squares(n)
}

pub fn square(s: u32) -> u64 {
  2_u64.pow(s-1)
}

pub fn total() -> u64 {
  (1..=64).map(|s| square(s)).sum()
}

pub fn is_leap_year(year: u64) -> bool {
  (year % 4 == 0 && year % 100 != 0) || year % 400 == 0
}


//This algorithm uses less memory but takes time to execute
pub fn nth(n: u32) -> u32 {
  let mut count = 0;
  let mut count_divider = 0;
  let mut current_number = 2;
  loop {
    for j in 2..current_number+1 {
      if current_number % 2 == 0 && current_number !=2 {
        break;
      }
      if current_number % j == 0 {
        count_divider += 1;
      }
    }
    if count_divider == 1 {
      count += 1
    }
    count_divider = 0;
    if count != n {
      current_number +=1;
    } else {
      return current_number;
    }
  }
}

pub fn factors(n: u64) -> Vec<u64> {
  let mut v:Vec<u64> = Vec::new();
  let mut num = n;
  loop {
    for i in 2..num+1{
      if num%i == 0 {
        num = num/i;
        v.push(i);
        break
      }
    }
    if num == 1 {
      return v;
    }
  }
}

pub fn build_proverb(list: &[&str]) -> String {
  if list.is_empty() {
    return String::new(); // Return an empty string if the list is empty
  }

  let mut result = Vec::new();

  for pair in list.windows(2) {
    result.push(format!("For want of a {} the {} was lost.", pair[0], pair[1]));
  }

  result.push(format!("And all for the want of a {}.", list[0]));

  result.join("\n")
}

pub fn raindrops(n: u32) -> String {
  let mut result = String::new();

  if n % 3 == 0 {
    result += "Pling";
  }
  if n % 5 == 0 {
    result += "Plang";
  }
  if n % 7 == 0 {
    result += "Plong";
  }

  if result.is_empty() {
    n.to_string()
  } else {
    result
  }
}

pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
  let mut set = HashSet::new();
  for num in factors {
    if num  == &0 {
      continue;
    }
    for i in 0..limit  {
      if i % num == 0  {
        set.insert(i);
      }
    }
  }

  set.iter().sum()
}
pub fn reply(message: &str) -> &str {
  let trimmed = message.trim();
  if trimmed.is_empty() {
    "Fine. Be that way!"
  } else if trimmed.ends_with('?') && trimmed.chars().any(|c| c.is_alphabetic()) && trimmed == trimmed.to_uppercase() {
    "Calm down, I know what I'm doing!"
  } else if trimmed.chars().any(|c| c.is_alphabetic()) && trimmed == trimmed.to_uppercase() {
    "Whoa, chill out!"
  } else if trimmed.ends_with('?') {
    "Sure."
  } else {
    "Whatever."
  }
}
#[derive(Debug)]
pub struct HighScores{
  scores: Vec<u32>,
}

impl HighScores {
  pub fn new(scores: &[u32]) -> Self {
    HighScores {
      scores: scores.to_vec(),
    }
  }

  pub fn scores(&self) -> &[u32] {
    &self.scores[0..]
  }

  pub fn latest(&self) -> Option<u32> {
    self.scores.last().copied()
  }

  pub fn personal_best(&self) -> Option<u32> {
    self.scores.iter().max().copied()
  }

  pub fn personal_top_three(&self) -> Vec<u32> {
    let mut n = 0;
    if self.scores.is_empty() {
      return vec![]
    } else if self.scores.len() <= 3 {
      n = self.scores.len();
    } else {
      n = 3;
    }
    let mut v = self.scores.clone();
    v.sort_unstable_by(|a, b| b.cmp(a));;
    v[..n].to_vec()
  }
}

pub fn brackets_are_balanced(string: &str) -> bool {
  let mut stack: Vec<char> = Vec::new();
  for i in string.chars() {
    if i == '{' || i == '[' || i == '(' {
      stack.push(i);
    } else if i == ')' || i == '}' || i == ']' {
      if let Some(&last) = stack.last() {
        if (i == ')' && last == '(') ||
          (i == '}' && last == '{') ||
          (i == ']' && last == '[')
        {
          stack.pop();
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
  }
  stack.is_empty()
}


fn run_test_luhn_algorithm(){
  println!("{}", is_valid_luhn_algorithm("4539319503436467"));
  println!("{}", is_valid_luhn_algorithm("055 444 285"));
  println!("{}", is_valid_luhn_algorithm("059"));
  println!("{}", is_valid_luhn_algorithm("091"));

}
pub fn collatz(n: u64) -> Option<u64> {
  let mut count = 0;
  let mut exp = n;
  if n == 0 {
    return None;
  }
  loop {
    if exp == 1 {
      return Some(count)
    }
    if exp % 2 == 0 {
      exp /= 2 ;
    } else {
      exp = exp*3 + 1;
    }
    count += 1;
  }
}

pub fn private_key(p: u64) -> u64 {
  use std::time::{SystemTime, UNIX_EPOCH};

  let now = SystemTime::now()
    .duration_since(UNIX_EPOCH)
    .expect("System time is before the UNIX EPOCH")
    .as_nanos();
  let seed = (now % p as u128) as u64;
  2 + seed % (p - 2)
}


pub fn public_key(p: u64, g: u64, a: u64) -> u64 {
  mod_exp(g, a, p)
}

pub fn secret(p: u64, b_pub: u64, a: u64) -> u64 {
  mod_exp(b_pub, a, p)
}

fn mod_exp(base: u64, exp: u64, modulus: u64) -> u64 {
  let mut result = 1;
  let mut base = base % modulus;
  let mut exp = exp;

  while exp > 0 {
    if exp % 2 == 1 {
      result = (result * base) % modulus;
    }
    base = (base * base) % modulus;
    exp /= 2;
  }

  result
}

pub fn series(digits: &str, len: usize) -> Vec<String> {
  if digits.len() < len || digits.is_empty() {
   return  vec![];
  }
  let mut v = Vec::new();
  for i in 0..digits.len() {
    if i+len <= digits.len() {
      let n = i + len;
      v.push(digits[i..n].to_string());
    }
  }
  v
}

pub fn egg_count(display_value: u32) -> usize {
  let mut count = 0;
  let mut number = display_value;
  while number > 0 {
    count += number & 1;
    number >>= 1;
  }
  count as usize
}





fn main() {
  // run_test_luhn_algorithm();
  // println!("{}", square_of_sum(100));
  // println!("{}", sum_of_squares(100));
  // println!("{}", difference(100));
  // println!("{}", is_leap_year(1600));
  // println!("{}", nth(10000));
  // println!("{:?}",factors(60));
  // println!("{}", sum_of_multiples(4, &[3, 0]));
  // println!("{}", brackets_are_balanced("{}["));
  // println!("{}", collatz(1_000_000).unwrap());
  println!("{:?}", series("777777", 3));
}

