stack   segment stack
        db      1024 dup(?)
stack   ends
data    segment
        x dw 2000
        y dw 250
data    ends
code    segment 
        assume cs:code,ds:data,ss:stack
start:
        mov ax,data
        mov ds,ax

        push y
        push x
        call func
        add sp,4

        test ax,8000h
        jns l0
        neg ax
        mov bx,ax
        mov ah,02h
        mov dl,'-'
        int 21h
        mov ax,bx
l0:
        mov cl,10
        div cl
        mov bh,ah
        mov ah,02h
        add al,30h
        mov dl,al
        int 21h
        add bh,30h
        mov dl,bh
        int 21h

        mov ax,4c00h
        int 21h

func    proc 
        push bp
        mov bp,sp
        push bx
        push cx
        push dx

        mov bx,[bp+4]
        mov cx,[bp+6]
        mov ax,bx
        ;div cl
        mov dx,0
        div cx
        ;mov ah,0
        sub ax,bx
        add ax,2023
        

        pop dx
        pop cx
        pop bx
        pop bp
        ret

func    endp
code    ends
        end start