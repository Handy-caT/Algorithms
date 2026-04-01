#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut result_node = None;
    let mut current_node = &mut result_node;

    let mut l1_tail = l1;
    let mut l2_tail = l2;

    let mut additional_1 = false;
    while l1_tail.is_some() && l2_tail.is_some() {
        let x = l1_tail.as_ref().unwrap().val;
        let y = l2_tail.as_ref().unwrap().val;

        let mut sum = x + y;
        if additional_1 {
            sum +=1;
            additional_1 = false;
        }

        if sum > 9 {
            sum -= 10;
            additional_1 = true;
        }

        let new_node = ListNode::new(sum);
        if current_node.is_none() {
            result_node = Some(Box::new(new_node.clone()));
            current_node = &mut result_node
        } else {
            current_node.as_mut().map(|n| n.next = Some(Box::new(new_node.clone())));
            let new_curr = current_node.as_mut().map(|n| &mut n.next).unwrap();
            current_node = new_curr
        }

        l1_tail = l1_tail.as_ref().unwrap().next.clone();
        l2_tail = l2_tail.as_ref().unwrap().next.clone();
    }

    while l1_tail.is_some() {
        let mut x = l1_tail.as_ref().unwrap().val;
        if additional_1 {
            x += 1;
            additional_1 = false;
        }

        if x > 9 {
            x = 0;
            additional_1 = true;
        }

        let new_node = ListNode::new(x);
        current_node.as_mut().map(|n| n.next = Some(Box::new(new_node.clone())));
        let new_curr = current_node.as_mut().map(|n| &mut n.next).unwrap();
        current_node = new_curr;

        l1_tail = l1_tail.as_ref().unwrap().next.clone();
    }

    while l2_tail.is_some() {
        let mut x = l2_tail.as_ref().unwrap().val;
        if additional_1 {
            x += 1;
            additional_1 = false;
        }

        if x > 9 {
            x = 0;
            additional_1 = true;
        }

        let new_node = ListNode::new(x);
        current_node.as_mut().map(|n| n.next = Some(Box::new(new_node.clone())));
        let new_curr = current_node.as_mut().map(|n| &mut n.next).unwrap();
        current_node = new_curr;

        l2_tail = l2_tail.as_ref().unwrap().next.clone();
    }

    if additional_1 {
        let new_node = ListNode::new(1);
        current_node.as_mut().map(|n| n.next = Some(Box::new(new_node.clone())));
    }

    result_node
}
