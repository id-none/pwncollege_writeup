from pwn import *

# echo nstxjhmi > exp | python 105.py < exp > exp1 | cat exp1
subprocess.run('/challenge/embryoio_level105')
