from pwn import *
io1 = subprocess.Popen('/challenge/embryoio_level54', stdout=PIPE)
io2 = subprocess.Popen('cat', stdin=io1.stdout, stdout=PIPE)
output = io2.communicate()[0]
print(output)