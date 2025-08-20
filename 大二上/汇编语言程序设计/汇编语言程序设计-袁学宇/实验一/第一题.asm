stack   segment stack
        db      1024 dup(?)
stack   ends
data    segment
data    ends
code    segment 'code'
        assume cs:code,ds:data,ss:stack
start:  mov ax,data
        mov ds,ax

        mov cx, ds:[0200h] 
        add cx, ds:[0204h]
        mov bx, ds:[0202h]
        adc bx, ds:[0206h]
        mov ds:[0208h],cx
        mov ds:[020ah],bx

code    ends
        end start

code    ends
        end start