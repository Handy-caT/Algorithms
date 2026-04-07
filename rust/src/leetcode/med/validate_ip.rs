
pub fn valid_ip_address(query_ip: String) -> String {
    fn try_parse_v4(ip: &str) -> bool {
        let parts: Vec<_> = ip.split(".").collect();
        if parts.len() != 4 {
            return false;
        }
        for part in parts {
            let Ok(num) = i32::from_str_radix(part, 10) else {
                return false;
            };

            if num < 0 || num > 255 {
                return false;
            }

            if &num.to_string() != part {
                return false;
            }
        }

        true
    }

    fn try_parse_v6(ip: &str) -> bool {
        let parts: Vec<_> = ip.split(":").collect();
        if parts.len() != 8 {
            return false;
        }
        for part in parts {
            let Ok(_) = i32::from_str_radix(part, 16) else {
                return false;
            };

            if part.len() != 4 {
                return false;
            }
        }

        true
    }


    if try_parse_v4(&query_ip) {
        return "IPv4".to_string()
    }

    if try_parse_v6(&query_ip) {
        return "IPv6".to_string()
    }

    "Neither".to_string()
}

#[cfg(test)]
mod tests {
    use crate::leetcode::med::validate_ip::valid_ip_address;

    #[test]
    fn it_works() {
        assert_eq!(valid_ip_address("1.1.1.1".to_string()), "IPv4".to_string());
        assert_eq!(valid_ip_address("2001:0db8:85a3:0:0:8A2E:0370:7334".to_string()), "IPv6".to_string());
        assert_eq!(valid_ip_address("2001:db8:85a3:0:0:8A2E:0370:7334".to_string()), "IPv6".to_string());
        assert_eq!(valid_ip_address("256.256.256.256".to_string()), "Neither".to_string())
    }
}