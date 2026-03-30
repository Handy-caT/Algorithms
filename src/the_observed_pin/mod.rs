use std::collections::HashMap;

fn recursive(variants: &[Vec<char>]) -> Vec<String> {
    let mut results = vec![];
    if variants.len() == 1 {
        return variants[0].iter().map(|c| c.to_string()).collect();
    } else {
        let res = recursive(&variants[1..]);
        for ch in &variants[0] {
            let updated_res = res.iter().map(|s| {
                let mut s = s.clone();
                s.insert(0, *ch);
                s
            }).collect::<Vec<_>>();
            results.extend(updated_res);
        }
    }

    results
}

fn get_pins(observed: &str) -> Vec<String> {
    let map = HashMap::from([
        ('1', vec!['1', '2', '4']),
        ('2', vec!['2', '1', '5', '3']),
        ('3', vec!['3', '2', '6']),
        ('4', vec!['4', '1', '5', '7']),
        ('5', vec!['5', '2', '4', '6', '8']),
        ('6', vec!['6', '3', '5', '9']),
        ('7', vec!['7', '4', '8']),
        ('8', vec!['8', '7', '5', '9', '0']),
        ('9', vec!['9', '6', '8']),
        ('0', vec!['0', '8']),
    ]);

    let chars = observed.chars().collect::<Vec<char>>();
    let variants = chars.into_iter().map(|c| map.get(&c).expect("all chars possible are covered").clone()).collect::<Vec<_>>();

    recursive(&variants)
}

#[cfg(test)]
mod tests {
    use super::get_pins;
    use itertools::Itertools;


    #[test]
    fn sample_tests() {
        assert_eq!(get_pins("8").iter().sorted().collect::<Vec<&String>>(),
                   vec!["0", "5", "7", "8", "9"]);
        assert_eq!(get_pins("11").iter().sorted().collect::<Vec<&String>>(),
                   vec!["11", "12", "14",  "21", "22", "24",  "41", "42", "44"]);
        assert_eq!(get_pins("369").iter().sorted().collect::<Vec<&String>>(),
                   vec!["236", "238", "239",  "256", "258", "259",  "266", "268", "269",  "296", "298", "299",
                        "336", "338", "339",  "356", "358", "359",  "366", "368", "369",  "396", "398", "399",
                        "636", "638", "639",  "656", "658", "659",  "666", "668", "669",  "696", "698", "699"]);
    }
}
