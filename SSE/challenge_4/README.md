### Write Up

#### Problem

- Given the executable, find the flag.

#### Exploit

- First, we use Ghidra to decompile the executable.
- When we analyse the source code, we can see that we can make use of heap exploit.
- Here, donkeyBrays function is not called anywhere but is made to read the flag.txt file.
- Next, we can see that the sleep(2) is an unrequired operation here.
- So, we can replace it's GOT table entry with donkeyBrays using heap overflow.
- We use gdb to find the required offsets.
- Then craft the whole exploit together.

#### Solution

- `file pwn1` : To get information about the file
- `checksec pwn1` : To get defenses information about the file.
- `gdb pwn1 ` : To gather all the required addresses
- `/opt/ghidra/ghidraRun` : To start and decompile the executable to C source.
- Use pwntools to create an exploit and run
