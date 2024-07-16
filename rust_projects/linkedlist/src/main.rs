use std::fmt::Debug;

#[derive(Debug)]
struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

#[derive(Debug)]
struct LinkedList<T> {
    head: Option<Box<Node<T>>>,
}

impl<T: Debug> LinkedList<T> {
    fn new() -> Self {
        LinkedList { head: None }
    }

    fn append(&mut self, data: T) {
        let new_node = Box::new(Node {
            data,
            next: self.head.take(),
        });
        self.head = Some(new_node);
    }

    fn traverse(&self) {
        let mut current = &self.head;
        while let Some(ref node) = current {
            println!("{:?}", node.data);
            current = &node.next;
        }
    }
    fn remove_first(&mut self) -> Option<T> {
        if let Some(head) = self.head.take() {
            self.head = head.next;
            Some(head.data)
        } else {
            None
        }
    }
}
fn main() {
    let mut list = LinkedList::new();
    list.append(1);
    list.append(2);
    list.append(3);

    list.traverse();
    println!("Removed: {:?}", list.remove_first());
    list.traverse();
}
