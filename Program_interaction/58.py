from pwn import *
io1 = subprocess.Popen('cat',stdout=PIPE)
io2 = subprocess.Popen('/challenge/embryoio_level58', stdin=io1.stdout, stdout=PIPE)
output = io2.communicate()[0]
print(output)
