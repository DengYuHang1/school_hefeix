stack segment stack
    dw 512 dup(?)
stack ends

data segment
    as1 db 'ok$'
    string1 db 'the 0 bit is 0',0dh,0ah,'$'
    string2 db 'the 1 bit is 0',0dh,0ah,'$'
    string3 db 'the 2 bit is 0',0dh,0ah,'$'
    string4 db 'the 3 bit is 0',0dh,0ah,'$'
    string5 db 'the 4 bit is 0',0dh,0ah,'$'
    string6 db 'the 5 bit is 0',0dh,0ah,'$'
    string7 db 'the 6 bit is 0',0dh,0ah,'$'
    string8 db 'the 7 bit is 0',0dh,0ah,'$'

    table dw s1,s2,s3,s4,s5,s6,s7  ;地址表
data ends

code segment
     assume cs:code,ds:data,ss:stack

start: 
    mov ax,data
    mov ds,ax
    mov ax,0
    mov bl,11011111B
   mov cx,8D
again:
    test bl,80h
    jz next

    mov ah,09h
    mov dx,offset as1
    int 21h

    inc al
    rol bl,1
    loop again

next:
    mov ah,0
    rol ax,1
    mov bx,ax
    jmp table[bx]

s1:
    mov dx,offset string1
    jmp done

s2:
    mov dx,offset string2
    jmp done

s3:
    mov dx,offset string3
    jmp done

s4:
    mov dx,offset string4
    jmp done

s5:
    mov dx,offset string5
    jmp done

s6:
    mov dx,offset string6
    jmp done

s7:
    mov dx,offset string7
    jmp done

s8:
    mov dx,offset string8
    jmp done   

done:
    mov ah,09h
    int 21h

    mov ah,4ch
    int 21h


code ends
     end start