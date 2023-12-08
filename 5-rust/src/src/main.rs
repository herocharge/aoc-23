use std::io;

fn main() {
    let mut inp = String::new();
    io::stdin()
        .read_line(&mut inp)
        .expect("Failed to read line");
    inp = inp.chars().take(inp.len() - 1).collect();
    let mut seedinp: Vec<&str> = inp.split(' ').collect();
    seedinp.remove(0);
    let seeds: Vec<i128> = seedinp.iter()
        .map(|&x| {
            let result: Result<i128,_> = x.parse();
            return result.unwrap_or_else(|err| {
                eprintln!("Error: parsing numbers: {} {}", x,  err);
                0
            });
            /*match result {
	        Ok(parsed_number) => {
	           println!("Successfully parsed: {}", parsed_number);
               parsed_number
	           // Now 'parsed_number' is an i128
	       }
	       Err(error) => {
	           println!("Failed to parse: {}", error);

	               // Handle the error (e.g., provide a default value or return an error)
	        }
	        }*/
        }).collect();
    let mut empt = String::new();
    io::stdin().read_line(&mut empt).expect("Failed to readline");
    let mut eles = Vec::<i128>::new();
    eles = seeds.clone();
    loop {
       let mut relation = String::new();
        io::stdin().read_line(&mut relation).expect("Failed to readline");
        let mut fin = false;
        if relation.contains("location") {
            fin = true;
        }
        let mut new_eles = eles.clone();
        loop {
            let mut mp_inp = String::new();
            io::stdin().read_line(&mut mp_inp).expect("Failed to readline");
            if mp_inp.len() <= 1 {
                break
            }
            mp_inp = mp_inp.chars().take(mp_inp.len() - 1).collect();
            let mut s_inp: Vec<&str> = mp_inp.split(' ').collect();
            let dst_start : i128 = s_inp[0].parse().unwrap_or_else(|err| {
                eprintln!("Error: getting numbers {} {}", s_inp[0], err);
                0
            });
            let src_start : i128 = s_inp[1].parse().unwrap_or_else(|err| {
                eprintln!("Error: getting numbers {} {}", s_inp[1], err);
                0
            });
            let r_len : i128 = s_inp[2].parse().unwrap_or_else(|err| {
                eprintln!("Error: getting numbers {} {}", s_inp[2], err);
                0
            });
            println!("src {}, dest {}, range {}", src_start, dst_start, r_len);
            for i in 0..eles.len() {
                if src_start <= eles[i] && src_start + r_len >= eles[i] {
                    new_eles[i] = eles[i] - src_start + dst_start;
                }
            }
        }
        eles = new_eles.clone();
        if fin {
            break
        }
        
    }
    if let Some(minimum) = eles.iter().min() {
        println!("Minimum element: {}", minimum);
    } else {
        println!("Vector is empty");
    }
    println!("Hello, world! {}", seeds[0]);
}
