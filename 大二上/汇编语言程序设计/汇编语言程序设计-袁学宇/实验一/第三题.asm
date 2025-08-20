stack   segment stack
        db      1024 dup(?)
stack   ends
data    segment
        addrtable dw l0,l1,l2,l3,l4,l5,l6,l7;
        s0 db 'The 0 bit is 0$'
        s1 db 'The 1 bit is 0$'
        s2 db 'The 2 bit is 0$'
        s3 db 'The 3 bit is 0$'
        s4 db 'The 4 bit is 0$'
        s5 db 'The 5 bit is 0$'
        s6 db 'The 6 bit is 0$'
        s7 db 'The 7 bit is 0$'

data    ends
code    segment 'code'
        assume cs:code,ds:data,ss:stack
start:  mov ax,data
        mov ds,ax

        ;为bl设置一个初值
        mov bl,11101111B
        ;对bl按位取反
        not bl
        mov al,bl
        mov cx,8
        ;对bl循环向左移一位
    circle:
        shl al,1
        jc exit
    loop circle
    exit:
        ;取第几位为0
        mov bx,8
        sub bx,cx
        shl bx,1
        jmp addrtable[bx]
    done:
        ;显示
        mov ah,9
        int 21h
        mov ax,4c00h
        int 21h
    l0:
        mov dx,offset s0
        jmp done
    l1:
        mov dx,offset s1
        jmp done
    l2:
        mov dx,offset s2
        jmp done
    l3:
        mov dx,offset s3
        jmp done
    l4:
        mov dx,offset s4
        jmp done
    l5:
        mov dx,offset s5
        jmp done
    l6:
        mov dx,offset s6
        jmp done
    l7:
        mov dx,offset s7
        jmp done

code    ends
        end start

