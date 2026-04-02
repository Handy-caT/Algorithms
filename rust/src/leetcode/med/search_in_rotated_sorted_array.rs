
pub fn search(nums: Vec<i32>, target: i32) -> i32 {
    fn search_inner(nums: &[i32], target: i32) -> i32 {
        let head = nums[0];
        let tail = *nums.last().unwrap();

        if head < tail {
            return nums.binary_search(&target).map(|v| v as i32).unwrap_or(-1)
        }

        let med = nums.len() / 2;
        let med_val = nums[med];

        if med_val == target {
            return med as i32
        }
        if med == 0 {
            return -1
        }

        let left_sorted = med_val > head;

        if left_sorted {
            if target >= head && target <= med_val {
                search_inner(&nums[..med], target)
            } else {
                let res = search_inner(&nums[med..], target);
                if res == -1 {
                    -1
                } else {
                    med as i32 + res
                }
            }
        } else {
            if target >= med_val && target <= tail {
                let res = search_inner(&nums[med..], target);
                if res == -1 {
                    -1
                } else {
                    med as i32 + res
                }
            } else {
                search_inner(&nums[..med], target)
            }
        }
    }

    search_inner(&nums, target)
}

#[cfg(test)]
mod tests {
    use crate::leetcode::med::search_in_rotated_sorted_array::search;

    #[test]
    fn it_works() {
        // let vec = vec![4,5,6,7,0,1,2];
        // assert_eq!(search(vec.clone(), 0), 4);
        // assert_eq!(search(vec.clone(), 3), -1);
        // assert_eq!(search(vec, 5), 1);
        //
        // let vec = vec![2,3,4,5,6,7,8,9,1];
        // assert_eq!(search(vec, 9), 7);

        let vec = vec![3, 5, 1];
        assert_eq!(search(vec, 3), 0);
    }
}