use std::io::{self, Write};
use plotters::prelude::*;

// Function to get user input for a single value
fn get_input(prompt: &str) -> f64 {
    let mut input = String::new();
    print!("{}", prompt);
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut input).unwrap();
    
    // Try to parse the input as f64, and return a default value if invalid
    input.trim().parse().unwrap_or(0.1) // Default value 0.1 for F0 and C
}

// Function to get user input for upper limit (usize)
fn get_upper_limit_input(prompt: &str) -> usize {
    let mut input = String::new();
    print!("{}", prompt);
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut input).unwrap();

    // Try to parse the input as usize, and return a default value if invalid
    input.trim().parse().unwrap_or(10) // Default value 10 for upper limit
}

fn logistic_map(c: f64, f0: f64, upper_limit: usize) -> Vec<f64> {
    let mut sequence = Vec::new();
    
    // Starting value F0
    let mut fi = f0;
    sequence.push(fi);

    // Recursively calculate values up to the upper limit
    for i in 1..upper_limit {
        fi = c * fi * (1.0 - fi);
        sequence.push(fi);
    }
    
    sequence
}

// Function to plot the logistic map sequence
fn plot_sequence(sequence: &[f64], filename: &str) {
    let root = BitMapBackend::new(filename, (800, 600)).into_drawing_area();
    root.fill(&WHITE).unwrap();
    
    let mut chart = ChartBuilder::on(&root)
        .caption("Logistic Map Sequence", ("sans-serif", 30))
        .build_ranged(0..sequence.len() as u32, -1.0..1.0)
        .unwrap();

    chart
        .configure_mesh()
        .x_desc("Iteration")
        .y_desc("Value")
        .draw()
        .unwrap();

    chart
        .draw_series(LineSeries::new(
            sequence.iter().enumerate().map(|(x, &y)| (x as u32, y)),
            &RED,
        ))
        .unwrap()
        .label("F(i)")
        .legend(|(x, y)| PathElement::new(vec![(x, y)], &RED));

    chart
        .configure_series_labels()
        .draw()
        .unwrap();
}

fn main() {
    // Call get_input three times to get F0, C, and upper_limit
    let f0 = get_input("Enter the initial value F0: ");
    let c = get_input("Enter the constant C: ");
    let upper_limit = get_upper_limit_input("Enter the upper limit for iterations: ");
    
    // Generate the logistic map sequence
    let sequence = logistic_map(c, f0, upper_limit);

    // Print the sequence
    println!("Logistic map sequence up to F{}:", upper_limit - 1);
    for (i, value) in sequence.iter().enumerate() {
        println!("F({}) = {}", i, value);
    }

    // Plot the sequence
    plot_sequence(&sequence, "logistic_map_plot.png");

    println!("Plot saved as 'logistic_map_plot.png'");
}
