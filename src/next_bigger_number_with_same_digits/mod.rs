fn next_bigger_number(n: u64) -> Option<u64> {
    todo!()
}

pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
    let mut i = 0;
    let mut j = 0;

    while i < m as usize && j < n as usize {
        let current_1 = nums1[i];
        let current_2 = nums2[j];

        if current_1 >= current_2 {
            nums1.insert(i, current_2);
            nums1.remove(m as usize);
            j += 1;
        } else {
            i += 1;
        }
    }

    if j < n as usize - 1  {
        for k in j..n as usize {
            nums1.insert(i, nums2[k]);
            nums1.remove(m as usize);
            i += 1;
        }
    }
}

#[cfg(test)]
mod tests {
    use crate::next_bigger_number_with_same_digits::{merge, next_bigger_number};

    #[test]
    fn sample_tests() {
        let mut v1 = vec![1,2,3,0,0,0];
        let mut v2 = vec![2,5,6];
        merge(&mut v1, 3, &mut v2,3);

        println!("{:?}", v1)
    }
}

