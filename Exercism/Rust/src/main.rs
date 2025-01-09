
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

fn run_test_luhn_algorithm(){
  println!("{}", is_valid_luhn_algorithm("4539319503436467"));
  println!("{}", is_valid_luhn_algorithm("055 444 285"));
  println!("{}", is_valid_luhn_algorithm("059"));
  println!("{}", is_valid_luhn_algorithm("091"));
}

fn main() {
  // run_test_luhn_algorithm();
}
