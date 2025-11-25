use std::io;
use rand::Rng;

fn get_sequence_input() -> String {
    loop {
        println!("Enter a sequence of 0s and 1s (0=tails, 1=heads):");
        
        let mut input = String::new();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");
        
        let sequence = input.trim().to_string();
        
        // Validate that it only contains 0s and 1s
        if sequence.chars().all(|c| c == '0' || c == '1') && !sequence.is_empty() {
            return sequence;
        } else {
            println!("Invalid input! Please enter only 0s and 1s.");
        }
    }
}

fn calculate_theoretical_expectation(sequence: &str, total_flips: usize) -> f64 {
    let n = sequence.len();
    
    // Probability of sequence occurring = (1/2)^n = 0.5^n
    let probability = 0.5_f64.powi(n as i32);
    
    // Number of possible windows in total_flips
    let num_windows = total_flips - n + 1;
    
    // Expected occurrences
    let expectation = num_windows as f64 * probability;
    
    expectation
}

fn generate_random_flips(num_flips: usize) -> Vec<u8> {
    let mut rng = rand::thread_rng();
    let mut flips = Vec::new();
    
    for _ in 0..num_flips {
        flips.push(rng.gen_range(0..=1));
    }
    
    flips
}

fn count_sequence_occurrences(flips: &Vec<u8>, sequence: &str) -> usize {
    let seq_bytes: Vec<u8> = sequence.chars()
        .map(|c| c.to_digit(10).unwrap() as u8)
        .collect();
    
    let mut count = 0;
    let seq_len = seq_bytes.len();
    
    // Sliding window approach - check every possible position
    for i in 0..=(flips.len() - seq_len) {
        let window = &flips[i..i + seq_len];
        if window == &seq_bytes[..] {
            count += 1;
        }
    }
    
    count
}

fn run_multiple_experiments(sequence: &str, total_flips: usize, num_experiments: usize) -> f64 {
    let mut total_occurrences = 0;
    
    println!("\nRunning {} experiments with {} flips each...", num_experiments, total_flips);
    
    for i in 0..num_experiments {
        let random_flips = generate_random_flips(total_flips);
        let count = count_sequence_occurrences(&random_flips, sequence);
        total_occurrences += count;
        
        if (i + 1) % 100 == 0 {
            println!("Completed {} experiments...", i + 1);
        }
    }
    
    // Average occurrences across all experiments
    let average_occurrences = total_occurrences as f64 / num_experiments as f64;
    
    average_occurrences
}

fn main() {
    println!("=== Coin Flip Sequence Expectation Calculator ===\n");
    
    let sequence = get_sequence_input();
    let total_flips = 10000;
    let num_experiments = 1000; // Run 1000 trials and average
    
    println!("\nSequence: {}", sequence);
    println!("Sequence length: {}", sequence.len());
    println!("Flips per experiment: {}", total_flips);
    println!("Number of experiments: {}", num_experiments);
    
    // Calculate theoretical expectation
    let theoretical_expectation = calculate_theoretical_expectation(&sequence, total_flips);
    
    // Run experimental simulations
    let experimental_expectation = run_multiple_experiments(&sequence, total_flips, num_experiments);
    
    // Display results
    println!("\n=== RESULTS ===");
    println!("Theoretical expectation: {:.4} occurrences", theoretical_expectation);
    println!("Experimental expectation (averaged over {} trials): {:.4} occurrences", 
             num_experiments, experimental_expectation);
    println!("Difference: {:.4}", (experimental_expectation - theoretical_expectation).abs());
    println!("Percentage error: {:.2}%", 
             ((experimental_expectation - theoretical_expectation).abs() / theoretical_expectation * 100.0));
}