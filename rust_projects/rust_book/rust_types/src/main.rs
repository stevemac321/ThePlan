/*
In Rust, the mutability of a slice is determined by how you borrow it, but the underlying object's mutability also 
plays a crucial role. Here’s how it works:

1. **Immutable Object, Immutable Slice**: If an object (e.g., an array or `Vec`) is immutable, you can only create 
an immutable slice of it. Attempting to create a mutable slice would result in a compilation error. This is because
 Rust's borrow checker enforces the immutability policy of the underlying object.

2. **Immutable Object, Mutable Slice**: You cannot create a mutable slice from an immutable object. The object in memory
 owns the mutability policy, so if the object itself is immutable, the slice must also be immutable.

3. **Mutable Object, Immutable Slice**: You can create an immutable slice from a mutable object. The slice won't allow 
modifications, but other code holding a mutable reference to the object can still modify it.

4. **Mutable Object, Mutable Slice**: You can create a mutable slice from a mutable object, allowing modifications to 
the underlying object through the slice. The mutability of the slice directly reflects the mutability of the underlying object.

### Summary

- **Mutability is a property of both the object and the slice**. The object’s mutability determines whether you can 
create a mutable or immutable slice.

- **An immutable object enforces immutability on its slices**. You cannot bypass this by declaring a mutable slice.
- **A mutable object can provide both mutable and immutable slices** depending on how you borrow it. 

This system ensures safety and prevents data races in concurrent scenarios, making Rust’s borrowing rules robust and 
reliable.
*/

/*
Explanation:
Borrowing:

In each example, we see borrowing in action when we pass references to arrays or strings (&[T], &str, &[char]).
Borrowing allows the function to access the data without taking ownership, so the original owner can still use 
the data afterward.

Ownership Transfer:
For types like Vec<T> and String, passing them directly to a function without a reference transfers ownership.
After ownership is transferred, the original owner can no longer use the variable.

Fixed-Size Arrays:
Fixed-size arrays like [i32; 5] can also be transferred by ownership or borrowed as slices, although ownership 
transfer is less common.

Strings and String Slices:
String is a heap-allocated growable string, while &str is a string slice, typically a reference to a string literal or a 
part of a String.This code provides a comprehensive overview of ownership and borrowing in Rust across different types 
and scenarios.
*/

fn main() {
    test_integer_array_on_stack();
    test_string_slice_str();
    test_vector_heap_allocated();
    test_array_of_characters();
    test_string_ownership_borrowing();
}
/*
It's more accurate to say that the calling code is "enabling a borrow" for the function. Here's why: Borrowing in Rust 
refers to temporarily allowing another part of the code to access data without taking ownership. When you pass a 
reference (&T) to a function, you are enabling that function to borrow the data.
The function is the one actually performing the borrow, as it receives the reference and uses the data without taking 
ownership.  The calling code provides the reference, thereby enabling the function to borrow the data. It still retains
ownership of the original data, ensuring that after the function call completes, the calling code can continue using 
the data.  So, the borrowing action is initiated by the function, but it is enabled by the calling code through the act 
of passing a reference.
*/

// Example 1: Integer Array on the Stack
fn test_integer_array_on_stack() {
    // Declare a fixed-size array on the stack
    let arr: [i32; 5] = [1, 2, 3, 4, 5];
    
    // Borrow the array as a slice and pass it to a function
    process_integer_slice(&arr);

    // Pass ownership of the array to another function (not typical for fixed-size arrays)
    process_integer_array(arr);

    // arr cannot be used here because ownership was transferred
}

fn process_integer_slice(slice: &[i32]) {
    println!("Processing integer slice: {:?}", slice);
}

fn process_integer_array(arr: [i32; 5]) {
    println!("Processing integer array: {:?}", arr);
}

// Example 2: String Slice (`&str`)
fn test_string_slice_str() {
    // String literal, which is a `&str`
    let s: &str = "hello";
    
    // Borrow the string slice
    process_string_slice(s);

    // Ownership of `&str` is already a reference, no ownership transfer typical
}

fn process_string_slice(s: &str) {
    println!("Processing string slice: {}", s);
}

// Example 3: Vector (Heap-Allocated, Dynamic Size)
fn test_vector_heap_allocated() {
    // Declare a vector, which is heap-allocated and can grow
    let v: Vec<i32> = vec![1, 2, 3, 4, 5];

    // Borrow the vector as a slice
    process_integer_slice(&v);

    // Transfer ownership of the vector to another function
    process_vector(v);

    // v cannot be used here because ownership was transferred
}

fn process_vector(v: Vec<i32>) {
    println!("Processing vector: {:?}", v);
}

// Example 4: Array of Characters (`char`) with References
fn test_array_of_characters() {
    // Declare a fixed-size array of characters
    let chars: [char; 4] = ['a', 'b', 'c', 'd'];
    
    // Borrow the array as a slice
    process_char_slice(&chars);

    // Transfer ownership (not common for fixed-size arrays)
    process_char_array(chars);

    // chars cannot be used here because ownership was transferred
}

fn process_char_slice(slice: &[char]) {
    println!("Processing char slice: {:?}", slice);
}

fn process_char_array(arr: [char; 4]) {
    println!("Processing char array: {:?}", arr);
}

// Example 5: String (`String`) - Ownership and Borrowing
fn test_string_ownership_borrowing() {
    // Create a heap-allocated string
    let s: String = String::from("hello");

    // Borrow the string as a `&str`
    process_string_slice(&s);

    // Transfer ownership of the string
    process_string(s);

    // s cannot be used here because ownership was transferred
}

fn process_string(s: String) {
    println!("Processing string: {}", s);
}
