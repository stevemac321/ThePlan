use std::fs::File;
use std::io::{self, BufRead, BufReader};
use std::path::Path;

#[derive(PartialEq)]
enum WordState {
    In,
    Out,
}

fn kandr_page_20() -> io::Result<()> {
    let path = Path::new("btree.h");
    let file = File::open(path)?;
    let reader = BufReader::new(file);

    let mut state = WordState::Out;
    let mut nl = 0;
    let mut nw = 0;
    let mut nc = 0;

    for line in reader.lines() {
        let line = line?;
        nl += 1;
        nc += line.len() + 1; // +1 for the newline character

        for c in line.chars() {
            state = match (state, c) {
                (WordState::Out, ' ') | (WordState::Out, '\t') => WordState::Out,
                (WordState::Out, _) => {
                    nw += 1;
                    WordState::In
                },
                (WordState::In, ' ') | (WordState::In, '\t') => WordState::Out,
                (WordState::In, _) => WordState::In,
            };
        }
    }

    println!("Lines: {}, Words: {}, Characters: {}", nl, nw, nc);
    Ok(())
}

fn main() -> io::Result<()> {
    kandr_page_20()
}
