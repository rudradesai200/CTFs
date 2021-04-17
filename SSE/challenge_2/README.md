### Write Up

#### Problem

- Given the executable, find the flag.

#### Exploit

- First, we use Ghidra to decompile the executable.
- When we analyse the source code, we can see that there are multiple place where buffer can be overflowed.
- So, we try to fuzz the executable with `pwn cyclic` and voila, it gives a segfault.
- We find the offset using `pwn cyclic -l` command and store it.
- Also, we notice that there is a hidden function - `winner`, which is used for seeing the flag.
- So, using pwnt

#### Solution

- `file pwn1` : To get information about the file
- `checksec pwn1` : To get defenses information about the file.
- `gdb pwn1 ` : To gather all the required addresses
- `pwn cylic 50` : To create a cyclic pattern for fuzzing
- `/opt/ghidra/ghidraRun` : To start and decompile the executable to C source.
- Use pwntools to create an exploit and run
