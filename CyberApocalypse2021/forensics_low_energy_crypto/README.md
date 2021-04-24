### Low energy crypto

#### Problem

- Given the packet capture for bluetooth low energy device. Get the flag.

#### Solution

- NOTE : I couldn't solve it during the contest.

- First using wireshark, analyze all the packets
- After connect packet, it started sending some file
- The file was the public RSA key.
- After sending the RSA key, it sent some more data, which possibly was the encrypted text.
- So, we use the basics of RSA to get this data back.
- I followed this solution to get the flag. :https://ctftime.org/writeup/27642
