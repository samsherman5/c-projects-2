extern _getMem
extern _freeMem
extern _printInt
global run
section .text

run:
push ebp
mov ebp, esp
sub esp, 0x8

call _getMem
mov DWORD [ebp-0x4], eax
mov DWORD [eax], 8
add eax, 0x4
mov DWORD [eax], 7
add eax, 0x4
mov DWORD [eax], 5
add eax, 0x4
mov DWORD [eax], 4
add eax, 0x4
mov DWORD [eax], 24
add eax, 0x4
mov DWORD [eax], 28
add eax, 0x4
mov DWORD [eax], 39
add eax, 0x4
mov DWORD [eax], 47
add eax, 0x4
mov DWORD [eax], 4
add eax, 0x4
mov DWORD [eax], 8
add eax, 0x4
mov DWORD [eax], 5
add eax, 0x4
mov DWORD [eax], 3
add eax, 0x4
mov DWORD [eax], 12
add eax, 0x4
mov DWORD [eax], 4
add eax, 0x4
mov DWORD [eax], 6
add eax, 0x4
mov DWORD [eax], 87
add eax, 0x4
mov DWORD [eax], 5
add eax, 0x4
mov DWORD [eax], 3
add eax, 0x4
mov DWORD [eax], 2356
add eax, 0x4
mov DWORD [eax], 354
add eax, 0x4
mov DWORD [eax], 73
add eax, 0x4
mov DWORD [eax], 3456
add eax, 0x4
mov DWORD [eax], 5
add eax, 0x4
mov DWORD [eax], 34
add eax, 0x4
mov DWORD [eax], 7
add eax, 0x4
mov DWORD [eax], 45
add eax, 0x4
mov DWORD [eax], 3
add eax, 0x4
mov eax, DWORD[ebp-0x4]
add eax, 4
push DWORD [eax]
call _printInt
mov eax, DWORD[ebp-0x4]
add eax, 4
add DWORD [eax], 1
mov eax, DWORD[ebp-0x4]
add eax, 4
push DWORD [eax]
call _printInt

push DWORD [ebp-0x4]
call _freeMem

leave
ret
