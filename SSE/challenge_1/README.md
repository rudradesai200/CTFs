### Write up

#### Problem

- Given a password protected pdf, unlock it to get the flag

#### Solution

- First, using pdf2john.py get the password hash from the pdf
- Next, get the rockyou.txt wordlist
- Now, using john the ripper with the rockyou.txt wordlist, obtain the password
- Open the file and you will get the flag there.

#### Commands

- `python3 pdf2john.py problem1.py > hash`
- Edit the hash to remove unwanted material
- `john hash --wordlist=rockyou.txt`
- You will obtain the password - `gears2halo3`
- Use this password to find the flag - `ctf2021{gh64ngv6}`
