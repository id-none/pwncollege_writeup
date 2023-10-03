from pwn import *
import os
import signal
sh=process("/challenge/embryoio_level128")
sh.recvuntil(b"(PID ")
pid=int(sh.recvuntil(b")")[:-1])
sh.recvuntil(b": ")
s=sh.recvline()[:-1]
print(s)
a=eval(s)
for i in range(len(a)):
	print(pid,eval("signal."+a[i]))
	os.kill(pid,eval("signal."+a[i]))
	sh.recvline()
	sh.recvline()
print(sh.recvall())
