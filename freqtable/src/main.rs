// src/main.rs
use std::fs;
use std::process;

// We define a constant for the size of our frequency array: 26 letters + 1 for space.
const FREQ_SIZE: usize = 27;
// Define the output file name
const OUTPUT_FILE: &str = "frequency_table.txt";

fn main() {
    let input_file_path = "rustinput.txt";
    
    // --- PART 1: Read the Input File ---
    println!("Attempting to read file: {}", input_file_path);

    let contents_result = fs::read_to_string(input_file_path);

    let contents = match contents_result {
        Ok(contents_data) => {
            println!("--- File Contents Read Successfully ---");
            contents_data
        },
        Err(error) => {
            eprintln!("\nError: Could not read file '{}'.", input_file_path);
            eprintln!("Specific OS Error: {}", error);
            eprintln!("Ensure the file exists in the root directory (next to Cargo.toml).");
            process::exit(1); 
        }
    };
    
    // --- PART 2: Calculate Frequencies ---
    
    // Initialize the frequency array with 27 zeros. 
    // Index 0-25 are for 'a' through 'z', and Index 26 is for ' '.
    let mut frequencies: [u32; FREQ_SIZE] = [0; FREQ_SIZE];
    
    // Process the content character by character
    for char_code in contents.chars() {
        // Convert the character to lowercase to handle both 'A' and 'a' the same way
        let lower_char = char_code.to_ascii_lowercase();
        
        match lower_char {
            // Case 1: If it is a lowercase letter ('a' through 'z')
            'a'..='z' => {
                // Calculate index: 'a' is 97 in ASCII. ('a' - 'a') gives 0, ('b' - 'a') gives 1, etc.
                let index = (lower_char as u8 - b'a') as usize;
                // Increment the count at the calculated index
                frequencies[index] += 1;
            },
            // Case 2: If it is a space
            ' ' => {
                // Space is always at the last index
                frequencies[FREQ_SIZE - 1] += 1;
            },
            // Case 3: Ignore any other characters (like tabs, newlines, or special characters)
            _ => {
                // We assume input is clean, but ignoring unknown characters is safe.
            }
        }
    }
    
    // --- PART 3: Generate the Output String ---

    let mut output_content = String::from("Character Frequency Table:\n\n");
    
    // A function to append text to the output string
    let mut append_line = |line: &str| {
        output_content.push_str(line);
        output_content.push('\n');
    };
    
    // Loop through indexes 0 to 25 for letters 'a' through 'z'
    for i in 0..26 {
        // Convert the index back to a character: 0 + 'a' -> 'a'
        let char_label = (b'a' + i as u8) as char;
        let line = format!("  '{}': {}", char_label, frequencies[i]);
        append_line(&line);
    }
    
    // Handle the space character (Index 26)
    let space_line = format!("' ': {}", frequencies[FREQ_SIZE - 1]);
    append_line(&space_line);

    // --- PART 4: Write the Output File ---
    
    println!("\nAttempting to write results to: {}", OUTPUT_FILE);

    // fs::write() is a convenient function that handles creating, opening, and writing 
    // the entire string to a file, returning a Result<(), Error>.
    match fs::write(OUTPUT_FILE, output_content) {
        Ok(_) => {
            println!("--- Successfully wrote frequency table to '{}' ---", OUTPUT_FILE);
            println!("You can now check the new file in your 'freqtable' directory.");
        },
        Err(error) => {
            eprintln!("\nCritical Error: Failed to write to file '{}'.", OUTPUT_FILE);
            eprintln!("Specific OS Error: {}", error);
            process::exit(1);
        }
    }
}
