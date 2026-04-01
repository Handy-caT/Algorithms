
pub fn length_of_longest_substring(s: String) -> i32 {
    const ALPHABET_LENGTH: usize = 95;
    fn clear_window(w: &mut (bool, i32, [bool; ALPHABET_LENGTH])) {
        *w = (false, 0, [false; ALPHABET_LENGTH]);
    }

    fn char_index(c: char) -> usize {
        c as usize - ' ' as usize
    }

    let mut winner = 0;

    let chars = s.chars();
    // (dead, len, alph_check)
    let mut windows_matrix = [(false, 0, [false; ALPHABET_LENGTH]); ALPHABET_LENGTH];

    for (i, c) in chars.enumerate() {
        let idx = i % ALPHABET_LENGTH;
        let limit = if i >= ALPHABET_LENGTH {
            clear_window(&mut windows_matrix[idx]);
            ALPHABET_LENGTH
        } else {
            i + 1
        };

        for j in 0..limit {
            let (dead, len, alph_check) = &mut windows_matrix[j];
            if *dead {
                continue
            }

            if alph_check[char_index(c)] {
                *dead = true;
                if *len > winner {
                    winner = *len
                }
            } else {
                *len += 1;
                alph_check[char_index(c)] = true;
            }
        }
    }

    let limit = if s.len() >= ALPHABET_LENGTH {
        ALPHABET_LENGTH
    } else {
        s.len()
    };
    for i in 0..limit {
        if windows_matrix[i].0 {
            continue
        }

        if windows_matrix[i].1 > winner {
            winner = windows_matrix[i].1;
        }
    }


    winner
}

#[cfg(test)]
mod tests {
    use crate::leetcode::med::longest_substring_without_repeationg_chars::length_of_longest_substring;

    #[test]
    fn test_length_of_longest_substring() {
        assert_eq!(length_of_longest_substring("abcabcbb".to_string()), 3);
        assert_eq!(length_of_longest_substring("abc".to_string()), 3);
    }
}