section .asm 


global intr_load ;export the symbot
intr_load:
     push ebp ;push the base pointer
     mov ebp, esp ;move the stack ptr to base ptr

     ;ebp = base ptr ebp+4 = return address, 
     ;ebp + 8 = first argument passed to this function
     mov ebx, [ebp + 8] 
     lidt [ebx]  ;load interrupt descriptor table
     
     pop ebp ;pop the base pointer
     ret ;return



