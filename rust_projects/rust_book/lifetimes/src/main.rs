struct Book<'a> {
    title: &'a str,
}

fn test_books() {
    let titles = ["The Rust Programming Language", "Programming Rust", "Rust by Example"];

    // Create an array of Books with lifetimes tied to the titles array
    let books: [Book; 3] = [
        Book { title: &titles[0] },
        Book { title: &titles[1] },
        Book { title: &titles[2] },
    ];

    // Print the titles of the books
    for book in &books {
        println!("Title: {}", book.title);
    }
}


fn test_returns() {

 let string1 = String::from("long string is long");
    let string2 = "xyz";

    let result = longest(string1.as_str(), string2);
    println!("The longest string is {}", result);
}

fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}
fn main() {
	test_books();
	test_returns();

}


