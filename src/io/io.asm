section .asm

global insb
global insw
global outb
global outw

insb:
    push ebp ;push base register
    mov ebp, esp ;mov stack pointer to ebp

    ;x86 instruction set reference
    ;IN AL, DX Input byte from IO port in DX into AL
    ;IN AX, DX Input word from IO port in DX into AL
    xor eax, eax 
    mov edx, [ebp + 8]
    in al, dx

    pop ebp ;pop base register
    ret

insw:
    push ebp ;push base register
    mov ebp, esp ;mov stack pointer to ebp

    ;x86 instruction set reference
    ;IN AL, DX Input byte from IO port in DX into AL
    ;IN AX, DX Input word from IO port in DX into AL
    xor eax, eax 
    mov edx, [ebp + 8]
    in ax, dx

    pop ebp ;pop base register
    ret

outb:
    push ebp ;push base register
    mov ebp, esp ;mov stack pointer to ebp

    mov eax, [ebp + 12]
    mov edx, [ebp + 8]
    out dx, al

    pop ebp ;pop base register
    ret

outw:
    push ebp ;push base register
    mov ebp, esp ;mov stack pointer to ebp

    mov eax, [ebp + 12]
    mov edx, [ebp + 8]
    out dx, ax

    pop ebp ;pop base register
    ret