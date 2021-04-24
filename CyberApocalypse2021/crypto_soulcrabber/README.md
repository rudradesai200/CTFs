### Soulcrabber

#### Problem

- Given the out.txt and main.rs file, get the flag

#### Solution

- As we can see that, a seeded random generator is used to generate random numbers first.
- Then these generated numbers are 'xor'ed with flag bytes to create an hex string which is given to us.
- So, we follow the same steps, use the same seed value to generate the random numbers first.
- Then, use these numbers to 'xor' with the encoded flag and print the result.
- We first run get_rand.rs to generate the random nums, then we use that result in decrypt.py to get the final flag.
- Flag : `CHTB{mem0ry_s4f3_crypt0_f41l}`
