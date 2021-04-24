def check_key(line):
    # Xor first 5 chars of line with flag_init
    bytestr = bytes.fromhex(line)[:5]
    flag_init = "CHTB{"
    keylist = [(t ^ ord(i)) for t, i in zip(bytestr, flag_init)]
    keyset = list(set(keylist))

    if(len(keyset) == 1):
        return keylist[0]

    return None


def decrypt(line, k):
    bytestr = bytes.fromhex(line)
    decoded = "".join([chr(i ^ k) for i in bytestr])
    print(decoded)


f = open("output.txt")

lines = f.readlines()

for l in lines:
    k = check_key(l[:-1])  # Fix for "\n"
    if(k):
        decrypt(l, k)
        break

f.close()
