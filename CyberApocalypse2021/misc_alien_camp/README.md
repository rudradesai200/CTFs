### Alien camp

#### Problem

- Connect to the server 188.166.172.13:30496, you have to answer 500 questions to get the flag.

#### Solution

- Hit the server, it will respond with some options.
- If we select options accordingly, it will first give us a map for emojis mapped to some numbers
- Next, we will be asked some basic math questions using the emojis.
- So, we use pwntools, to automate the process for 500 questions.
- You can find the file in my github repo : exploit.py
