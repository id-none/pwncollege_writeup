from pwn import *

p = process(["/challenge/embryoio_level100"])
for i in range (5):
	output = p.recvuntil(b"CHALLENGE! Please send the solution for: ", timeout=1)

	if b"CHALLENGE" not in output:
		print(output.decode("utf-8"))

	#[:-1] = everything except last character
	equation = p.recvuntil(b"\n")[:-1]

	answer = eval(equation)	
	print(f"SOLVED #{i}: {equation.decode('utf-8')[:50]}... = {answer}")
	print(f"ANSWER: {answer}")
	p.sendline(bytes(str(answer), 'utf-8'))
	p.recvuntil(b"CORRECT!")

print(p.recvall(timeout=2).decode('utf-8'))
