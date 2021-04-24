### Phase stream 2

#### Problem

- Given the encoded text, get the flag

#### Hints

- Also, the flag is encrypted by 'xor'ing with a key of length 5

#### Solution

- We know that the flag starts with "CHTB{" and ends with "}".
- Also, suppose the key = x and the plaintext char =c, then encoded char (e) = c ^ x.
- So, we xor the first 5 chars of the encoded string with "CHTB{", this, will give us the key.
- So, we use the given key and the encoded flag to get the flag.
- You can find the code in decrypt.py
- Flag - `CHTB{u51ng_kn0wn_pl41nt3xt}`
