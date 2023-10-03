from pwn import *

# echo ugbzzwxt > exp | python 107.py
f=open("./exp")
f2=os.dup2(f.fileno(),242)
argv=["/challenge/embryoio_level107"]
p=subprocess.Popen(argv,pass_fds=[242])
p.wait()
