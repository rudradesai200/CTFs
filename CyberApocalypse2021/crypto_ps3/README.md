### Phase stream 3

#### Problem

- Given the output.txt file, get the flag
- The source file for encoding is given.

#### Solution

- If we read about AES-CTR , we can find out that AES-CTR uses the AES block
  cipher to create a stream cipher.
- Also, the key along with IV(Initialization vector) is used to generate the encoding blocks first.
- Then these blocks are 'xor'ed with plain text to output the encoded text.
- Now, if we use the same key, then the generated encoding blocks will be same, so basically, only the plain text is varying.
- So, enc(test) = test ^ block and enc(flag) = flag ^ block.
- This means, block = enc(flag) ^ flag = enc(test) ^ test.
- => flag = enc(test) ^ test ^ enc(flag) (as ^ is a commutative operation)
- As, we know all the 3 things, we can decrypt the flag with decrypt.py.
- Flag : `CHTB{r3u53d_k3Y_4TT4cK}`
