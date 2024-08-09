fn main() {
   let first = String::from("Jon");
   let full = add_suf(first);
   println!("{full}");
   let a = first;
}
fn add_suf(mut name: String) ->String {
   name.push_str(" Jr.");
   name
}
