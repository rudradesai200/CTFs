### WRITE UP

#### PROBLEM

- Given the login.html file, where you can input username and password, find out the flag.
- Hint : Reverse engineering

#### APPROACH

- First, try to get sense of the login.html file.
- While going through the functions you will notice that you must pass username="superuser"
- Also, the functions takes your password, gets a sha256 hash and do some stuff.
- I tried to lot to reverse engineer it, but failed.
- So, finally, I used wordlist generator to generate a [a-zA-z0-9] 5 length wordlist and also the rockyou wordlist and tried a bruteforce attack.
- It worked.

#### Commands

- Copy all the 4 given js files into a single file and modify the functions given in login.html to get a function for bruteforce. (file decode.js)
- `python3 wgen.py --chars abcdefghijklmnopqrstuvwxyz0123456789 --min_length 1 --max_length 5` : To generate the wordlist
- `node decode.js` : Bruteforce using the wordlist and voild
- flag : `CTF2021{n00b}`
