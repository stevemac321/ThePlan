use std::thread;
use std::time::Duration;

fn test1() {
     let handle = thread::spawn(|| {
        for i in 1..10 {
            println!("worker thread {i}");
            thread::sleep(Duration::from_millis(1));
        }
    });
    handle.join().unwrap();
    for i in 1..5 {
        println!("main thread {i}");
        thread::sleep(Duration::from_millis(1));
    }
}
fn main() {
    test1();
}
