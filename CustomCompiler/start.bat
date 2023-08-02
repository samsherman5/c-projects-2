nasm -f win32 -o run.o run.asm
gcc -Wall -o a.exe getMem.c run.o
a.exe
pause