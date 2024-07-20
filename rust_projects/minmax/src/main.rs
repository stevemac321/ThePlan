fn max_subarray_sum(arr: &[i32]) -> i32 {
    let mut max_sum = arr[0];
    let mut current_sum = 0;
    
    for &num in arr {
        current_sum = num.max(current_sum + num);
        max_sum = max_sum.max(current_sum);
    }
    
    max_sum
}

fn process_array(arr: &[i32]) -> (bool, i32, i32) {
    if arr.is_empty() {
        println!("The array is empty.");
        return (false, 0, 0);
    }

    // Access the first element
    let first_element = arr[0];
    println!("The first element is: {}", first_element);

    // Initialize min and max with the first element
    let mut min = first_element;
    let mut max = first_element;

    // Iterate from the second element onwards
    for &item in &arr[1..] {
        if item < min {
            min = item;
        }
        if item > max {
            max = item;
        }
    }

    (true, min, max)
}

fn main() {
    let my_array = [44, 88, 1, -7, 66, 3];
    let result = process_array(&my_array);
    println!("Success: {}, Min: {}, Max: {}", result.0, result.1, result.2);
}

