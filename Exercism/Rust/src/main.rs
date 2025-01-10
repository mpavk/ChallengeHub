
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


fn run_test_luhn_algorithm(){
  println!("{}", is_valid_luhn_algorithm("4539319503436467"));
  println!("{}", is_valid_luhn_algorithm("055 444 285"));
  println!("{}", is_valid_luhn_algorithm("059"));
  println!("{}", is_valid_luhn_algorithm("091"));
}

fn main() {
  // run_test_luhn_algorithm();
  // println!("{}", square_of_sum(100));
  // println!("{}", sum_of_squares(100));
  // println!("{}", difference(100));
  // println!("{}", is_leap_year(1600));
  // println!("{}", nth(10000));
  println!("{:?}",factors(60));

}
