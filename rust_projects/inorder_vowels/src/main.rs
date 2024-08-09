enum State {
    None,
    A,
    E,
    I,
    O,
    U,
    Done,
}

fn inorder_vowels(words: &[char]) -> (i32, i32) {
    let mut vowels = vec!['u', 'o', 'i', 'e', 'a'];
    let mut state = State::None;
    let mut count = 0;
    let mut total = 0;

    for &c in words {
        if c == ' ' {
            if matches!(state, State::Done) {
                count += 1;
            }
            state = State::None;
            vowels = vec!['u', 'o', 'i', 'e', 'a'];
            total += 1;
        } else if let Some(&expected) = vowels.last() {
            if c.to_ascii_lowercase() == expected {
                vowels.pop();
                state = match state {
                    State::None => State::A,
                    State::A => State::E,
                    State::E => State::I,
                    State::I => State::O,
                    State::O => State::U,
                    State::U => State::Done,
                    State::Done => State::Done,
                };
            }
        }
    }

    if matches!(state, State::Done) {
        count += 1;
    }
    total += 1;

    (count, total)
}

fn main() {
    let words: [char; 68] = ['a', 'b', 's', 't', 'e', 'm', 'i', 'o', 'u', 's', ' ', 'f', 'a', 'c', 'e', 't', 'i',
    'o', 'u', 's', ' ', 'a', 'e', 'r', 'i', 'f', 'o', 'r', 'm', ' ', 'a', 'r', 's', 'e', 'n', 'i', 'o', 'u', 's',
    ' ', 'a', 'n', 'e', 'm', 'i', 'o', 'u', 's', ' ', 'c', 'a', 'e', 's', 'i', 'u', 'm', ' ', 'b', 'a', 'c', 'o',
     'n', ' ', 'q', 'u', 'e', 'u', 'e'];

    let (count, total) = inorder_vowels(&words);
    println!("Words with vowels in order: {}/{}", count, total);
}
