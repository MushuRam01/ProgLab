use std::io;

fn get_integer_input() -> i32 {
    loop {
        println!("Please enter an integer:");
        
        let mut input = String::new();
        
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");
        
        match input.trim().parse() {
            Ok(num) => return num,
            Err(_) => println!("Invalid input! Please enter a valid integer."),
        }
    }
}

// Brute force primality check - checks all numbers from 2 to n-1
fn is_prime_brute_force(n: i32) -> bool {
    if n <= 1 {
        return false;
    }
    if n == 2 {
        return true;
    }
    
    for i in 2..n {
        if n % i == 0 {
            return false;
        }
    }
    true
}

// Optimized primality check - only checks up to sqrt(n) and skips even numbers
fn is_prime_optimized(n: i32) -> bool {
    if n <= 1 {
        return false;
    }
    if n == 2 {
        return true;
    }
    if n % 2 == 0 {
        return false;
    }
    
    let limit = (n as f64).sqrt() as i32;
    
    for i in (3..=limit).step_by(2) {
        if n % i == 0 {
            return false;
        }
    }
    true
}

// Check if the difference between two numbers is exactly 2
fn is_difference_two(a: i32, b: i32) -> bool {
    (a - b).abs() == 2
}

fn main() {
    println!("=== TASK 1: Check if two numbers are twin primes ===");
    let num1 = get_integer_input();
    let num2 = get_integer_input();
    
    let is_num1_prime = is_prime_optimized(num1);
    let is_num2_prime = is_prime_optimized(num2);
    
    if is_num1_prime && is_num2_prime {
        if is_difference_two(num1, num2) {
            println!("{} and {} are twin primes!", num1, num2);
        } else {
            println!("{} and {} are both prime but not twin primes.", num1, num2);
        }
    } else {
        println!("Both numbers need to be prime for twin primes.");
        if !is_num1_prime {
            println!("{} is not prime.", num1);
        }
        if !is_num2_prime {
            println!("{} is not prime.", num2);
        }
    }
    
    println!("\n=== TASK 2: Find all twin prime pairs below a number ===");
    let limit = get_integer_input();
    
    let mut primes: Vec<i32> = Vec::new();
    
    // Check 2 separately
    if 2 <= limit && is_prime_optimized(2) {
        primes.push(2);
    }
    
    // Check all odd numbers
    for i in (3..limit).step_by(2) {
        if is_prime_optimized(i) {
            primes.push(i);
        }
    }
    
    println!("Primes found: {:?}", primes);
    println!("\nTwin prime pairs:");
    
    for i in 0..primes.len() {
        for j in (i + 1)..primes.len() {
            if is_difference_two(primes[i], primes[j]) {
                println!("({}, {})", primes[i], primes[j]);
            }
        }
    }
}