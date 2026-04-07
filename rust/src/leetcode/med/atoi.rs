
pub fn my_atoi(s: String) -> i32 {
    let trimmed = s.trim();
    let mut res = 0;

    if trimmed.len() == 0 {
        return 0;
    }

    let mut chars = trimmed.chars();
    let first = chars.next().expect("non empty as checked before");
    if !first.is_numeric() && first != '-' && first != '+' {
        return 0;
    }

    let sign: i32 =  if first == '-' {
        -1
    } else {
        1
    };

    if first.is_numeric() {
        res *= 10;
        res += first as i32 - '0' as i32;
    }

    loop {
        let Some(char) = chars.next() else {
            break
        };

        if !char.is_numeric() {
            break
        } else {
            let Some(mul_res) = res.checked_mul(10) else {
                return if sign.is_negative() {
                    i32::MIN
                } else {
                    i32::MAX
                }
            };
            let Some(sum_res) = mul_res.checked_add(char as i32 - '0' as i32) else {
                return if sign.is_negative() {
                    i32::MIN
                } else {
                    i32::MAX
                }
            };
            res = sum_res
        }
    }

    res * sign
}

#[cfg(test)]
mod tests {
    use crate::leetcode::med::atoi::my_atoi;

    #[test]
    fn it_works() {
        assert_eq!(my_atoi("42".to_string()), 42);
        assert_eq!(my_atoi( " -042".to_string()), -42);
        assert_eq!(my_atoi("1337c0d3".to_string()), 1337);
        assert_eq!(my_atoi("0-1".to_string()), 0);
        assert_eq!(my_atoi("words and 987".to_string()), 0);
        assert_eq!(my_atoi("-91283472332".to_string()), i32::MIN);
    }
}