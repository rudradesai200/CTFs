#### Solution

- I started by simply running the given executable, it printed a few things and I tried to play it like a game, but couldn't find anything.
- So then, I statically analyzed the given executable on ghidra and extracted some imp functions in source.c.
- I started to analyze the flow, I figured that we had only these commands at our disposal,
  - look
  - inventory
  - go <direction>[north, south, east, west, up, down]
  - take <thing>
  - drop <thing>
  - use <thing>
  - jhiezetfmvirlnjfbobk (the secret command)
- The last command was a strange one, and I looked at what it does. It simply sets the JHIEZETFMVIRLNJFBOBK to 1
- Now, the whole game looked like to be an infinite loop.
- But, there were some things after the loop too.
- I noticed that if JHIEZETFMVIRLNJFBOBK was non-zero, it printed xor of 2 other strange variables.
- I thought this can be the flag.
- So, the first thing to figure out now was, how to break the loop.
- Now, I checked other functions like describe_room() and inventory() etc, but nothing useful there.
- Atlast, I checked use_item() function. It simply contained if-else conditions.
- Figuring that out, the only task to complete this game was to solve a case.

- So, I did the following things and it worked.

  - First write this command JHIEZETFMVIRLNJFBOBK
  - Then take the the swissblonkel scenario from the main room
  - Then go west
  - Then go to Chief's Office
  - Then take the solved stamp
  - Done

- This solved the case, activated that strange variable and printed the flag.
