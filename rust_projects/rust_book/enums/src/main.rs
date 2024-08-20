fn test_some() {
    {
        let config_max = Some(3u8);
        match config_max {
            Some(max) => println!("The maximum is configured to be {max}"),
            _ => (), 
        }
    }
    {
        let config_max = Some(3u8);
        // use "let Some" when you want to ignore the None case.
            if let Some(max) = config_max {
                println!("The maximum is configured to be {max}");
        }
    }

}
fn divide(numerator: f64, denominator: f64) -> Option<f64> {
    if denominator == 0.0 {
        None
    } else {
        Some(numerator / denominator)
    }
}

fn test_none() {
    {
        let result = divide(4.0, 2.0);
        match result {
            Some(value) => println!("Result: {}", value),
            None => println!("Cannot divide by zero"),
        }
    }
    {
        let result = divide(4.0, 2.0);
        // use "let Some" when you want to ignore the None case.
            if let Some(value) = result {
                println!("Result: {}", value);
            }
    }
}
fn main() {
    test_some();
    test_none();
}

