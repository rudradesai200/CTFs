### Phase stream 2

#### Problem

- Given the output.txt file, get the flag

#### Hints

- The encrypted flag is hidden among 9999 other lines in output.txt.
- Also, the flag is encrypted by 'xor'ing with a key of length 1

#### Solution

- We know that the flag starts with "CHTB{" and ends with "}".
- Also, suppose the key = x and the plaintext char =c, then encoded char (e) = c ^ x.
- So, for each line, we xor the first 5 chars of the encoded string with "CHTB{".
- This, will give us 5 possible keys. If all the 5 keys are same, then we can be sure that this line contains the flag.
- Also, the 'xor'ed value will give us the key.
- So, we use the given key and the line to get the flag.
- You can find the code in decrypt.py
- Flag - `CHTB{n33dl3_1n_4_h4yst4ck}`
