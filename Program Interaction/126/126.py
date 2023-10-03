#!/usr/bin/python3
from pwn import *

p=process("/challenge/embryoio_level125")
for i in range(50):
    #print(p.recvline())
    print(p.recvuntil(b":\n"))
    s=p.recvline()
    print(s)
    tmp=eval(s)
    print(tmp)
    p.sendline(b"%d"%tmp)

print(p.recvall())
