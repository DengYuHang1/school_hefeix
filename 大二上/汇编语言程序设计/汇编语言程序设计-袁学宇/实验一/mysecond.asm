stack segment stack
      dw 512 dup(?)
stack ends

data segment
    X DW 10
    Y DW 20
    Z DW 30
    V DW 40
    sum1 DW ?
    sum2 DW ?
data ends

code segment
     assume cs:code,ds:data,ss:stack
start:
      mov ax,data
      mov ds,ax

      mov ax,X
      imul Y
      mov bx,ax
      mov cx,dx
      mov ax,Z
      cwd
      add bx,ax
      adc cx,dx
      mov ax,720
      cwd
      sub bx,ax
      sbb cx,dx
      mov ax,V
      cwd
      sub ax,bx
      sbb dx,cx
      idiv X
      mov sum1,ax
      mov sum2,dx

      mov ah,4ch
      int 21h

code ends
     end start