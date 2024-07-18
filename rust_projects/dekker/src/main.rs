use std::sync::{Arc, Mutex, Condvar};
use std::thread;

struct Dekker {
    flag: [bool; 2],
    turn: usize,
}

impl Dekker {
    fn new() -> Self {
        Dekker {
            flag: [false, false],
            turn: 0,
        }
    }

    fn enter(&mut self, id: usize, cvar: &Condvar, lock: &Mutex<()>) {
        let other = 1 - id;
        self.flag[id] = true;
        while self.flag[other] {
            if self.turn != id {
                self.flag[id] = false;
                let mut guard = lock.lock().unwrap();
                while self.turn != id {
                    guard = cvar.wait(guard).unwrap();
                }
                self.flag[id] = true;
            }
        }
    }

    fn exit(&mut self, id: usize, cvar: &Condvar) {
        self.turn = 1 - id;
        self.flag[id] = false;
        cvar.notify_all();
    }
}

fn test_dekker() {
    let dekker = Arc::new((Mutex::new(Dekker::new()), Condvar::new(), Mutex::new(())));
    
    let dekker1 = Arc::clone(&dekker);
    let handle1 = thread::spawn(move || {
        let (dekker, cvar, lock) = &*dekker1;
        loop {
            let mut d = dekker.lock().unwrap();
            d.enter(0, cvar, lock);
            println!("Thread 1 in critical section");
            d.exit(0, cvar);
        }
    });

    let dekker2 = Arc::clone(&dekker);
    let handle2 = thread::spawn(move || {
        let (dekker, cvar, lock) = &*dekker2;
        loop {
            let mut d = dekker.lock().unwrap();
            d.enter(1, cvar, lock);
            println!("Thread 2 in critical section");
            d.exit(1, cvar);
        }
    });

    handle1.join().unwrap();
    handle2.join().unwrap();
}

fn print_array(arr: &[i32]) {
    for &num in arr {
        print!("{} ", num);
    }
    println!();
}

fn remove_duplicates(arr: &mut [i32]) -> usize {
    if arr.len() < 2 {
        return arr.len();
    }

    let mut left = 0;
    for right in 1..arr.len() {
        if arr[right] != arr[left] {
            left += 1;
            arr[left] = arr[right];
        }
    }
    left + 1
}

fn main() {
    let mut a1 = vec![1, 2, 2, 3, 3, 4, 5, 6];
    let len = remove_duplicates(&mut a1);
    print_array(&a1[..len]);

    let mut a2 = vec![2, 2, 2, 2];
    let len = remove_duplicates(&mut a2);
    print_array(&a2[..len]);

    test_dekker();
}
/*
Commentary:

1. **Function Definition and Return Type**:
   - `fn print_array(arr: &[i32])`: Defines a function named `print_array` that takes a slice of integers (`&[i32]`) as an argument.
   - `fn remove_duplicates(arr: &mut [i32]) -> usize`: Defines a function named `remove_duplicates` that takes a mutable slice of integers (`&mut [i32]`) and returns a `usize` (unsigned integer type).

2. **Printing to the Console**:
   - `println!`: A macro to print to the console, followed by a newline.
   - `print!`: A macro to print to the console without a newline.
   - `{}`: A placeholder for variables inside the string.

3. **Mutable and Immutable References**:
   - `arr: &mut [i32]`: `&` denotes a reference, and `&mut` denotes a mutable reference, allowing the function to modify the contents of the array.

4. **Vector Initialization and Slicing**:
   - `let mut a1 = vec![1, 2, 2, 3, 3, 4, 5, 6];`: Initializes a mutable vector using the `vec![]` macro.
   - `print_array(&a1[..len]);`: Uses slicing syntax `[..len]` to create a view into the vector from the start to `len`.

5. **Loop and Conditional Logic**:
   - `for &num in arr`: Iterates over each element in the array by reference.
   - `1..arr.len()`: A range that iterates from 1 to the length of the array minus one.
   - `if arr[right] != arr[left]`: Conditional statement to compare values.

6. **Incrementing Index and Assigning Values**:
   - `left += 1;`: Increments the `left` index.
   - `arr[left] = arr[right];`: Assigns the value from `arr[right]` to `arr[left]`.

7. **Returning a Value**:
   - `left + 1`: Returns the new length of the array after removing duplicates.
*/

