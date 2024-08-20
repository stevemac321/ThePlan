/*
use std::cmp::PartialOrd;

struct Node<T> {
    element: T,
    next: Option<Box<Node<T>>>,
}

impl<T> Node<T>
where
    T: PartialOrd + PartialEq + Clone,
{
    pub fn new(e: T) -> Self {
        Node {
            element: e,
            next: None,
        }
    }
}

struct List<T> {
    head: Option<Box<Node<T>>>,
    len: usize,
}
impl<T> List<T>
where
    T: PartialOrd + PartialEq + Clone,
{
    pub fn new() -> Self {
        List{
            head: None,
            len: 0,
        }
    }
    pub fn Insert(&self, elem: T) {
        if self.head.is_none() {
            self.head = Some(Box::new(Node::new(elem)));
        } else {
            
            let mut n = Some(Box::new(Node::new(elem)));
            n.next = self.head.take(); // this guts self.head
            self.head = Some(n);  //this revives self.head
            self.len += 1;
        }
    }
    pub fn Print(&self) {
        let mut p = &self.head;
        while Some(&n) = p {
            print!("{} ->", n.element);
            p = &n.next;
        }
        println!("");
    }
}
fn main() {

}
*/
//Mine is above, does not compile, Chat came up with this one, it compiles.
// It does not have any traits PartialEq and PartialOrd.
use std::fmt::Display;

#[derive(Debug)]
struct Node<T> {
    element: T,
    next: Option<Box<Node<T>>>,
}

impl<T> Node<T> {
    fn new(element: T) -> Self {
        Node { element, next: None }
    }
}

#[derive(Debug)]
struct LinkedList<T> {
    head: Option<Box<Node<T>>>,
    len: usize,
}

impl<T: Display> LinkedList<T> {
    fn new() -> Self {
        LinkedList {
            head: None,
            len: 0,
        }
    }

    fn push_front(&mut self, element: T) {
        let mut new_node = Box::new(Node::new(element));
        new_node.next = self.head.take();
        self.head = Some(new_node);
        self.len += 1;
    }

    fn pop_front(&mut self) -> Option<T> {
        self.head.take().map(|node| {
            self.head = node.next;
            self.len -= 1;
            node.element
        })
    }

    fn peek_front(&self) -> Option<&T> {
        self.head.as_ref().map(|node| &node.element)
    }

    fn len(&self) -> usize {
        self.len
    }

    fn is_empty(&self) -> bool {
        self.len == 0
    }

    fn print(&self) {
        let mut current = &self.head;
        while let Some(ref node) = current {
            print!("{} -> ", node.element);
            current = &node.next;
        }
        println!("None");
    }
}

fn main() {
    let mut list = LinkedList::new();

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    list.print(); // Expected output: 3 -> 2 -> 1 -> None

    println!("Popped: {:?}", list.pop_front()); // Expected output: Some(3)
    list.print(); // Expected output: 2 -> 1 -> None

    println!("Peek: {:?}", list.peek_front()); // Expected output: Some(2)

    println!("List length: {}", list.len()); // Expected output: 2
    println!("Is list empty? {}", list.is_empty()); // Expected output: false
}

