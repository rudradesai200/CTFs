use rand::{Rng,SeedableRng};
use rand::rngs::StdRng;


fn get_rng() -> StdRng {
    let seed = 13371337;
    return StdRng::seed_from_u64(seed);
}

fn get_rand_nums(input : String) -> String {
    let mut rng = get_rng();
    return input
        .chars()
        .into_iter()
        .map(|c| format!("{:02x}", (rng.gen::<u8>())))
        .collect::<Vec<String>>()
        .join("");
}

fn main(){
    let flag = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; // Dummy chars for length check
    let rand_nums = get_rand_nums(flag.to_string());
    println!("{}", rand_nums); // 581140c6a0fb4a1ab2a33855897e5ebc26537402be82ef0b0c63e8940e
}
