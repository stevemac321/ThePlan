fn process_array(arr: &[i32], s: i32) -> (i32, i32) {
    let mut left: usize = 0;
    let mut total: i32 = 0;

    for right in 0..arr.len() {
        total += arr[right];

        // Adjust the sliding window if the total exceeds s
        while total > s && left < right {
            total -= arr[left];
            left += 1;
        }

        // Check if we found the desired sum
        if total == s {
            return (left as i32 + 1, right as i32 + 1);
        }
    }
    (-1, -1)
}

fn main() {
    let my_array = [1, 2, 3, 8, 5, 60, 2, 4, 6];
    let result = process_array(&my_array, 12);
    println!("{},{}", result.0, result.1); // Expected output: 2,4
}


