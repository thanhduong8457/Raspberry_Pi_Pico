import os
import struct
import binascii

#input_data = "03020100070605040B0A09080F0E0D0C03020100070605040B0A09080F0E0D0C6BAE8F504F6F2E5A824C38F07C6E8F3E248D15C2476DBBFD524F3921F75DB0620B3FB25AAFE0B5312CED22A85BB1E6803EFB428669FD83BB4CBDDD431A8DA525_OINMACC3735AD6322CF0B7E80F2FEBEED4044563DC8128985EFCD9F7C72C448CA44C4017971659C40701AC062187E5058C3A6958BB81E10A7EBAF235E736C28B8302931A18ECDE1FFE7A161FF1FB157E258EC6D100B7DB8F62CDB54A0477C5877A689183457F9333E9A953EBA46959C9E820AAF8D876783B442D8548A54AC010C0D0E0F08090A0B04050607000102030C0D0E0F08090A0B0405060700010203"

input_data = "A"

input_data = binascii.unhexlify(input_data)

print(input_data)