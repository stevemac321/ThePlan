use std::sync::Arc;
use std::sync::atomic::{AtomicI32, Ordering};
use std::thread;

fn closure1() {
    // Declare an atomic integer with an initial value of 0
    let atomic_int = Arc::new(AtomicI32::new(0));

    // Number of threads to spawn
    let num_threads = 10;

    // Vector to hold the thread handles
    let mut handles = vec![];

    for _ in 0..num_threads {
        // Clone the atomic integer for the thread
        let atomic_int_clone = Arc::clone(&atomic_int);

        // Spawn a thread and pass a closure to increment the atomic integer
        let handle = thread::spawn(move || {
            // Closure that increments the atomic integer
            let increment = || {
                atomic_int_clone.fetch_add(1, Ordering::SeqCst);
            };

            // Call the closure
            increment();
        });

        // Store the thread handle
        handles.push(handle);
    }

    // Wait for all threads to finish
    for handle in handles {
        handle.join().unwrap();
    }

    // Print the final value of the atomic integer
    println!("Final value: {}", atomic_int.load(Ordering::SeqCst));
}

fn closure2() {
    // Declare an atomic integer with an initial value of 0
    let atomic_int = Arc::new(AtomicI32::new(0));

    // Clone the atomic integer for use in the closure
    let atomic_int_clone = Arc::clone(&atomic_int);

    // Define the closure ahead of time
    let increment_closure = move || {
        atomic_int_clone.fetch_add(1, Ordering::SeqCst);
        println!("Atomic value incremented by thread.");
    };

    // Spawn a thread and pass the previously defined closure
    let handle = thread::spawn(increment_closure);

    // Wait for the thread to finish
    handle.join().unwrap();

    // Print the final value of the atomic integer
    println!("Final value: {}", atomic_int.load(Ordering::SeqCst));
}

fn main() {
    closure1();
    closure2();
}
