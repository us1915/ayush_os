[BITS 32]
global _start ;global export
global intr_divide_by_zero_test

extern kernel_main

CODE_SEG equ 0x08
DATA_SEG equ 0x10

; Load next sector

_start:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov ebp, 0x00200000
    mov esp, ebp

    ; Enable the A20 line
    in al, 0x92
    or al, 2
    out 0x92, al

    ;Remap the master PIC (programmable Interrupt Controller)
    mov al, 00010001b ;initialization mode
    out 0x20, al ;Tell master PIC

    mov al, 0x20 ;Interrupt 0x20 is where master ISR should start
    out 0x21, al

    mov al, 00000001b
    out 0x21, al
    ; End remap of the master PIC

    ; Enable interrupts
    sti

    call kernel_main

    jmp $

intr_divide_by_zero_test:
    ;mov eax, 0
    ;div eax

    ;alternatively call interrupt number 32 we defined in intr.c
    int 32


; assembly dont do alignment like C so add padding to 512 to make a nice alignment     
times 512-($ - $$) db 0
