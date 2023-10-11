section .asm 

extern int_keyboard_handler
extern no_intr_handler

;export the symbols
global int_keyboard
global intr_load 
global no_intr


intr_load:
     push ebp ;push the base pointer
     mov ebp, esp ;move the stack ptr to base ptr

     ;ebp = base ptr ebp+4 = return address, 
     ;ebp + 8 = first argument passed to this function
     mov ebx, [ebp + 8] 
     lidt [ebx]  ;load interrupt descriptor table
     
     pop ebp ;pop the base pointer
     ret ;return


; keyboard interrupt
int_keyboard:

    cli ; stop interrupt
    pushad ;push all general purpose registers - EAX, ECX,EBX,EDX, ESP, EBP, ESI, EDI
    
    call int_keyboard_handler
    
    popad
    sti ;start interrupt
    iret
    
; No interrupt
no_intr:

    cli ; stop interrupt
    pushad ;push all general purpose registers - EAX, ECX,EBX,EDX, ESP, EBP, ESI, EDI
    
    call no_intr_handler
    
    popad
    sti ;start interrupt
    iret
    


