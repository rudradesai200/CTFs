rand_hexs = bytes.fromhex(
    "581140c6a0fb4a1ab2a33855897e5ebc26537402be82ef0b0c63e8940e")
enc_flag = bytes.fromhex(
    "1b591484db962f7782d1410afa4a388f7930067bcef6df546a57d9f873")

flag = ""
for a, b in zip(rand_hexs, enc_flag):
    flag += chr(a ^ b)

print(flag)  # CHTB{mem0ry_s4f3_crypt0_f41l}
