use std::fs::File;
use std::io::{self, Read};
use std::num::ParseIntError;
use std::path::Path;
use std::option::Option;

fn test_divide() {
    fn divide(a: i32, b: i32) -> Result<i32, String> {
        if b == 0 {
            Err("Division by zero".to_string())
        } else {
            Ok(a / b)
        }
    }

    let result = divide(10, 0);
    match result {
        Ok(value) => println!("Result: {}", value),
        Err(error) => println!("Error: {}", error),
    }
}

fn test_parse_number() {
    fn parse_number(s: &str) -> Result<i32, std::num::ParseIntError> {
        s.parse::<i32>()
    }

    let result = parse_number("42");
    match result {
        Ok(number) => println!("Parsed number: {}", number),
        Err(e) => println!("Failed to parse number: {}", e),
    }
}

fn test_read_file() {
    fn read_file(path: &str) -> Result<String, std::io::Error> {
        let file = std::fs::File::open(path);
        match file {
            Ok(mut f) => {
                let mut contents = String::new();
                match f.read_to_string(&mut contents) {
                    Ok(_) => Ok(contents),
                    Err(e) => Err(e),
                }
            }
            Err(e) => Err(e),
        }
    }

    match read_file("example.txt") {
        Ok(contents) => println!("File contents: {}", contents),
        Err(e) => println!("Error reading file: {}", e),
    }
}

fn test_read_and_parse() {
    fn read_and_parse(path: &str) -> Result<i32, String> {
        let mut file = File::open(path).map_err(|e| e.to_string())?;
        let mut contents = String::new();
        file.read_to_string(&mut contents).map_err(|e| e.to_string())?;
        let number: i32 = contents.trim().parse().map_err(|e: ParseIntError| e.to_string())?;
        Ok(number)
    }

    match read_and_parse("number.txt") {
        Ok(number) => println!("Parsed number: {}", number),
        Err(e) => println!("Error: {}", e),
    }
}

fn test_open_and_parse() {
    fn open_and_parse() -> Result<i32, String> {
        let file_result = std::fs::File::open("number.txt");
        match file_result {
            Ok(file) => {
                let mut buf_reader = std::io::BufReader::new(file);
                let mut contents = String::new();
                match buf_reader.read_to_string(&mut contents) {
                    Ok(_) => match contents.trim().parse::<i32>() {
                        Ok(n) => Ok(n),
                        Err(_) => Err("Failed to parse the number".to_string()),
                    },
                    Err(_) => Err("Failed to read the file".to_string()),
                }
            }
            Err(_) => Err("Failed to open the file".to_string()),
        }
    }

    match open_and_parse() {
        Ok(number) => println!("Number: {}", number),
        Err(e) => println!("Error: {}", e),
    }
}

fn test_divide_with_default() {
    fn divide(a: i32, b: i32) -> Result<i32, String> {
        if b == 0 {
            Err("Division by zero".to_string())
        } else {
            Ok(a / b)
        }
    }

    let result = match divide(10, 0) {
        Ok(value) => value,
        Err(_) => 0, // Provide a default value on error
    };
    println!("Result: {}", result);
}

fn test_find_file() {
    fn find_file(filename: &str) -> Result<Option<String>, std::io::Error> {
        if Path::new(filename).exists() {
            let contents = std::fs::read_to_string(filename)?;
            Ok(Some(contents))
        } else {
            Ok(None)
        }
    }

    match find_file("example.txt") {
        Ok(Some(contents)) => println!("File found: {}", contents),
        Ok(None) => println!("File not found"),
        Err(e) => println!("Error: {}", e),
    }
}

fn main() {
    test_divide();
    test_parse_number();
    test_read_file();
    test_read_and_parse();
    test_open_and_parse();
    test_divide_with_default();
    test_find_file();
}

