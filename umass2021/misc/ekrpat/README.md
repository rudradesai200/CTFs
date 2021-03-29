#### Solution

- The problem description was "I made so few errors when creating this jail. nc `34.72.64.224 8083` `nc 35.231.20.75 8083`"
- And the hint was "Look down at where you're typing."
- So the natural thing was to hit the server.
- The server prompted with this, "Frg-k. xprt.b mf jre.! >ojal. ,cydrgy yd. d.nl ru .kanw .q.jw cmlrpyw rl.bw row p.aew ofoy.mw abe ,pcy.v Ucpoyw .by.p -ekrpat-v Frg ,cnn yd.b i.y abryd.p cblgy ,dcjd frg jab go. ypf yr xp.at rgy ru yd. hacnv"
- This looked like a subsitution cipher. So, I started breaking it using the tricks present on web.
- After a whole of 2 hrs, I was able to decode a msg by crafting a dictionary of substitutions.
- This was the dict, (which is a keyboard layout called 'dvorak')

```{' ': ' ',
 ',': 'w',
 '-': "'",
 '.': 'e',
 '>': 'e',
 'a': 'a',
 'b': 'n',
 'c': 'i',
 'd': 'h',
 'e': 'd',
 'f': 'y',
 'g': 'u',
 'h': 'j',
 'i': 'g',
 'j': 'c',
 'k': 'v',
 'l': 'p',
 'm': 'm',
 'n': 'l',
 'o': 's',
 'p': 'r',
 'q': 'x',
 'r': 'o',
 't': 'k',
 'u': 'f',
 'v': '.',
 'w': ',',
 'x': 'b',
 'y': 't'}
```

- The decoded cipher read, "you've broken my code. escape without the help of eval, exec, import, open, os, read, system, and write. first, enter 'dvorak'. you will then get another input which you can use try to break out of the jail."
- Then as the cipher said, I wrote dvorak and I got a second chance. Any other word and the executable broke out.
- Also, the cipher and the executable prompt hinted towards python.
- So, I tried help() and the python3.8 help window prompted out.
- Any of the thing which the cipher mentioned not to write broke the executable.
- I tried searching on web on how to read file without using normal import. I got a solution.
- The obvious thing to search was to "how to break out of python jail", which stuck me afterwards.
- I used the following command `__import__('os').system("cat flag")`" and got the flag- UMASS{dvorak_rules}.
- I searched for the key 'dvorak' and found out that it one of the standard keyboard layout.
- If I knew that, I could have saved my 2 hrs :face_palm.
