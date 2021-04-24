### Invitation

#### Problem

- Given the invite.docx file, get the flag

#### Solution

- As the docx contained only 1 page and there was nothing of interest there, I looked up in macros.
- I found a big macro, which looked like an encoded file.
- It looked like a function is used repeatedly and it decodes the string to BASE64.
- So, I combined the string, used BASE64 decoder on it and got the whole macro for analyzing.
- In the macro, there were some parts which were reversed and also many other transformations like regex and string concat were done.
- After carefully reading the file and applying the inverse transformations, we can find out the flag.
- Flag : `CHTB{maldocs_are_the_new_meta}`

- You can find the extracted macro in my git repo.
