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
fn test_inorder_vowels() {
    let words: [char; 68] = ['a', 'b', 's', 't', 'e', 'm', 'i', 'o', 'u', 's', ' ', 'f', 'a', 'c', 'e', 't', 'i',
    'o', 'u', 's', ' ', 'a', 'e', 'r', 'i', 'f', 'o', 'r', 'm', ' ', 'a', 'r', 's', 'e', 'n', 'i', 'o', 'u', 's',
    ' ', 'a', 'n', 'e', 'm', 'i', 'o', 'u', 's', ' ', 'c', 'a', 'e', 's', 'i', 'u', 'm', ' ', 'b', 'a', 'c', 'o',
     'n', ' ', 'q', 'u', 'e', 'u', 'e'];

    let (count, total) = inorder_vowels(&words);
    println!("Words with vowels in order: {}/{}", count, total);
}

use std::fs::File;
use std::io::{self, Read, Write, BufReader, BufWriter};
use std::path::Path;

#[derive(PartialEq)]
enum CommentState {
    Normal,
    MaybeComment,
    InComment,
    MaybeEndComment,
}

fn remove_comments() -> io::Result<()> {
    let input_path = Path::new("btree.h");
    let output_path = Path::new("btree_no_comments.h");

    let input_file = File::open(input_path)?;
    let mut reader = BufReader::new(input_file);
    let output_file = File::create(output_path)?;
    let mut writer = BufWriter::new(output_file);

    let mut input = String::new();
    reader.read_to_string(&mut input)?;

    let mut state = CommentState::Normal;
    let mut output = String::new();

    for c in input.chars() {
        state = match (state, c) {
            (CommentState::Normal, '/') => CommentState::MaybeComment,
            (CommentState::Normal, _) => {
                output.push(c);
                CommentState::Normal
            },
            (CommentState::MaybeComment, '*') => CommentState::InComment,
            (CommentState::MaybeComment, _) => {
                output.push('/');
                output.push(c);
                CommentState::Normal
            },
            (CommentState::InComment, '*') => CommentState::MaybeEndComment,
            (CommentState::InComment, _) => CommentState::InComment,
            (CommentState::MaybeEndComment, '/') => CommentState::Normal,
            (CommentState::MaybeEndComment, '*') => CommentState::MaybeEndComment,
            (CommentState::MaybeEndComment, _) => CommentState::InComment,
        };
    }

    // Handle any trailing '/' if we ended in MaybeComment state
    if state == CommentState::MaybeComment {
        output.push('/');
    }

    writer.write_all(output.as_bytes())?;
    Ok(())
}

fn main() -> io::Result<()> {
    inorder_vowels();
    remove_comments()
}
