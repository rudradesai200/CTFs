from math import ceil

flag_enc = bytes.fromhex(
    "2e313f2702184c5a0b1e321205550e03261b094d5c171f56011904")
flag_init = "CHTB{"
keylist = [(t ^ ord(i)) for t, i in zip(flag_enc, flag_init)]

flag = ""
for i in range(ceil(len(flag_enc)/5)):
    for j in range(5):
        if(i*5 + j == len(flag_enc)):
            print(flag)
            exit()
        flag += chr(keylist[j] ^ flag_enc[i*5 + j])
