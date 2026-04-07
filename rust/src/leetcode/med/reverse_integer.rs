
pub fn reverse(mut x: i32) -> i32 {
    let sign = x.signum();
    x *= sign;

    let mut y: i32 = 0;
    while x > 0 {
        let (next, part) = (x / 10, x % 10);
        let Some(res) = y.checked_mul(10) else {
            return 0
        };
        let Some(res) = res.checked_add(part) else {
            return 0
        };

        x = next;
        y = res;
    }

    y * sign
}

#[cfg(test)]
mod tests {
    use crate::leetcode::med::reverse_integer::reverse;

    #[test]
    fn it_works() {
        assert_eq!(reverse(123), 321);
        assert_eq!(reverse(-123), -321);
        assert_eq!(reverse(120), 21);
        assert_eq!(reverse(1534236469), 0);
    }
}