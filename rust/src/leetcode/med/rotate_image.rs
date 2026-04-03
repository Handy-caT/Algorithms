
pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
    let n = matrix.len();
    for i in 0..n {
        for j in (i+1)..n {
            unsafe {
                let p1 = &mut matrix[i][j] as *mut i32;
                let p2 = &mut matrix[j][i] as *mut i32;
                std::ptr::swap(p1, p2);
            }
        }
    }

    for i in 0..n {
        matrix[i].reverse()
    }
}