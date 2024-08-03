// Define a singly linked list node
#[derive(Debug)]
pub struct SListNode<T> {
    pub data: T,
    pub next: Option<Box<SListNode<T>>>,
}

// Define the singly linked list
#[derive(Debug)]
pub struct SList<T> {
    pub head: Option<Box<SListNode<T>>>,
}

// Macro to create a new list
macro_rules! slist_new {
    () => {
        SList { head: None }
    };
}

// Macro to create a new node
macro_rules! slist_node {
    ($data:expr) => {
        SListNode {
            data: $data,
            next: None,
        }
    };
}

// Macro to insert an element at the head of the list
macro_rules! slist_insert_head {
    ($list:expr, $data:expr) => {
        {
            let mut new_node = Box::new(slist_node!($data));
            new_node.next = $list.head.take();
            $list.head = Some(new_node);
        }
    };
}

// Macro to iterate over each element
macro_rules! slist_foreach {
    ($list:expr, $var:ident, $body:block) => {
        {
            let mut current = &$list.head;
            while let Some(ref node) = current {
                let $var = &node.data;
                $body
                current = &node.next;
            }
        }
    };
}

fn main() {
    // Create a new list
    let mut list: SList<i32> = slist_new!();

    // Insert elements into the list
    slist_insert_head!(list, 10);
    slist_insert_head!(list, 20);
    slist_insert_head!(list, 30);

    // Print the list
    println!("List: {:?}", list);

    // Iterate over each element
    slist_foreach!(list, value, {
        println!("Value: {}", value);
    });
}
