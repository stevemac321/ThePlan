#[derive(Debug)]  // these are attributes
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }
}
impl Rectangle { // copy ctor
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}
fn test_methods() {
    let rc = Rectangle {
        width: 30,
        height: 50,
    };
   println!(
        "The area of the rectangle is {} square pixels.",
        rc.area()
    );  
}




// Use String so you don't lose ownership.
struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}

fn test_structs() {
    let mut u1 = User {
        active: true,
        username: String::from("comet"),
        email: String::from("comet@gmail.com"),
        sign_in_count: 1,
    };
    print_user(&u1);
    u1.email = String::from("comet@live.com");
    print_user(&u1);
    let u2 = build_user(u1.username, u1.email);
    print_user(&u2);

    let u3 = User {
        active: u2.active,
        ..u2
    };
    print_user(&u3);

}

fn build_user(username: String, email: String) -> User {
    User {
        active: true,
        username: username, // optional, because the field name matches the parameter name.
        email: email,
        sign_in_count: 1
    }
}
fn print_user(ru: &User) {
    println!("{},{},{},{}", ru.active, ru.username, ru.email, ru.sign_in_count);
}
struct Color(i32, i32, i32);
struct Point(i32, i32, i32);
fn print_color(tup: &Color) {

    println!("{},{},{}", tup.0, tup.1, tup.2);
}
fn test_tuple() {

    let black = Color(0,0,0);
    print_color(&black);
    let origin = Point(0,0,0);
}
fn main() {
    test_structs();
    test_tuple();
    test_methods();
}

