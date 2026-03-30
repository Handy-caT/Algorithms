
#[derive(Copy, Clone)]
struct Point {
    pub x: usize,
    pub y: usize,
}

impl Point {
    pub fn down(self) -> Point {
        Point {
            x: self.x + 1,
            y: self.y
        }
    }

    pub fn up(self) -> Point {
        Point {
            x: self.x - 1,
            y: self.y
        }
    }

    pub fn left(self) -> Point {
        Point {
            x: self.x,
            y: self.y - 1
        }
    }

    pub fn right(self) -> Point {
        Point {
            x: self.x,
            y: self.y + 1
        }
    }
}

fn move_right(matrix: &[Vec<i32>], start: Point, steps: usize) -> (Point, Vec<i32>) {
    let array_to_step = &matrix[start.x];
    let way = array_to_step.iter().skip(start.y).take(steps).copied().collect::<Vec<_>>();
    let final_step = Point {
        x: start.x,
        y: start.y + steps - 1
    };
    (final_step, way)
}

fn move_down(matrix: &[Vec<i32>], start: Point, steps: usize) -> (Point, Vec<i32>) {
    let way = matrix.iter().skip(start.x).map(|arr| arr[start.y]).take(steps).collect::<Vec<_>>();
    let final_step = Point {
        x: start.x + steps - 1,
        y: start.y
    };
    (final_step, way)
}

fn move_left(matrix: &[Vec<i32>], start: Point, steps: usize) -> (Point, Vec<i32>) {
    let array_to_step = &matrix[start.x];
    let way = array_to_step.iter().rev().skip(matrix.len() - 1 - start.y).take(steps).copied().collect::<Vec<_>>();
    let final_step = Point {
        x: start.x,
        y: start.y + 1 - steps
    };
    (final_step, way)
}

fn move_up(matrix: &[Vec<i32>], start: Point, steps: usize) -> (Point, Vec<i32>) {
    let way = matrix.iter().rev().skip(matrix.len() - 1 - start.x).map(|arr| arr[start.y]).take(steps).collect::<Vec<_>>();
    let final_step = Point {
        x: start.x  + 1 - steps,
        y: start.y
    };
    (final_step, way)
}

fn snail(matrix: &[Vec<i32>]) -> Vec<i32> {
    let matrix_size = matrix.len();
    let mut point = Point { x: 0, y: 0 };
    let mut all_steps = vec![];

    let cycle_steps = (matrix_size + 2 - 1) /2;
    let mut steps = matrix_size;

    for _ in 0..cycle_steps {
        let (last_step, steps_right) = move_right(matrix, point, steps);
        all_steps.extend(steps_right);

        if steps == 1 {
            break;
        }

        let (last_step, steps_down) = move_down(matrix, last_step.down(), steps - 1);
        all_steps.extend(steps_down);

        let (last_step, steps_left) = move_left(matrix, last_step.left(), steps - 1);
        all_steps.extend(steps_left);

        let (last_step, steps_left) = move_up(matrix, last_step.up(), steps - 2);
        all_steps.extend(steps_left);

        point = last_step.right();
        steps -= 2;
    }

    all_steps
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn sample_test1() {
        let square = &[
            vec![1,2,3],
            vec![4,5,6],
            vec![7,8,9],
        ];
        let expected = vec![1,2,3,6,9,8,7,4,5];
        assert_eq!(snail(square), expected);
    }

    #[test]
    fn sample_test2() {
        let square = &[
            vec![1,2,3],
            vec![8,9,4],
            vec![7,6,5],
        ];
        let expected = vec![1,2,3,4,5,6,7,8,9];
        assert_eq!(snail(square), expected);
    }

    #[test]
    fn sample_test3() {
        let square: &[Vec<i32>; 1] = &[Vec::new()];
        let expected = Vec::new();
        assert_eq!(snail(square), expected, "Failed with empty input");
    }

    #[test]
    fn sample_test4() {
        let square = &[vec![1]];
        let expected = vec![1];
        assert_eq!(snail(square), expected);
    }
}
