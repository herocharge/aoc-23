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
    let mut seeds_start = Vec::<i128>::new();
    let mut seeds_range = Vec::<i128>::new();
    for i in (0..seeds.len()).step_by(2) {
        seeds_start.push(seeds[i]);
        seeds_range.push(seeds[i+1]);
    }
    let mut empt = String::new();
    io::stdin().read_line(&mut empt).expect("Failed to readline");
    let mut eles_start = Vec::<i128>::new();
    eles_start = seeds_start.clone();
    let mut eles_range = seeds_range.clone();
    loop {
       let mut relation = String::new();
        io::stdin().read_line(&mut relation).expect("Failed to readline");
        let mut fin = false;
        if relation.contains("location") {
            fin = true;
        }
        let mut new_eles_start = eles_start.clone();
        let mut new_eles_range = eles_range.clone();
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
            for i in 0..eles_start.len() {
                if src_start <= eles_start[i] && src_start + r_len - 1 >= eles_start[i] {
                    if eles_start[i] + eles_range[i] <= src_start + r_len - 1 {
                        new_eles_start[i] = dst_start + eles_start[i] - src_start;
                    }
                    else {
                        new_eles_start[i] = src_start + r_len - 1;
                        new_eles_range[i] = eles_range[i] - (src_start + r_len - eles_start[i]);
                        new_eles_start.push(dst_start + eles_start[i] - src_start);
                        new_eles_range.push(src_start + r_len - eles_start[i]);
                    }
                }
                else if src_start >= eles_start[i] + eles_range[i] && src_start + r_len - 1 >= eles_start[i] + eles_range[i] - 1{
                    new_eles_range[i] = src_start - eles_start[i];
                    new_eles_start.push(dst_start);
                    new_eles_range.push(eles_range[i] - src_start + eles_start[i]);
                }
                else if src_start >= eles_start[i] + eles_range[i] && src_start + r_len - 1 <= eles_start[i] + eles_range[i] - 1{
                    new_eles_range[i] = src_start - eles_start[i];
                    new_eles_start.push(dst_start);
                    new_eles_range.push(r_len);
                    new_eles_start.push(src_start + r_len);
                    new_eles_range.push(eles_range[i] - src_start + eles_start[i] - r_len)
                }
            }
        }
        eles_start = new_eles_start.clone();
        eles_range = new_eles_range.clone();
        if fin {
            break
        }
        
    }
    if let Some(minimum) = eles_start.iter().min() {
        println!("Minimum element: {}", minimum);
    } else {
        println!("Vector is empty");
    }
    println!("Hello, world! {}", seeds[0]);
}
