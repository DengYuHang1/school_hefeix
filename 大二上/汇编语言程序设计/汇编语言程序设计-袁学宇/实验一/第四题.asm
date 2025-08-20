stack   segment stack
        db      1024 dup(?)
stack   ends
data    segment
        score db 100 dup(?) ; 存放100个学生的成绩
        input1 db ? ; 用户输入的成绩
        input2 db ?
        input db ?
        found db 'N$' ; 默认为没找到
data    ends
code    segment 'code'
        assume cs:code,ds:data,ss:stack
start:  mov ax,data
        mov ds,ax

        ; 生成100个学生的成绩
        lea di, score
        mov cx, 100
GENERATE_SCORES:
        mov ax,cx
        sub ax, 1
        mov [di], ax
        inc di
        loop GENERATE_SCORES

    ; 获取用户输入的成绩
        mov ah, 01h
        int 21h
        sub al, '0'
        mov ah, 0
        mov input1, al
        mov ah, 01h
        int 21h
        sub al, '0'
        mov ah, 0
        mov input2, al

    ; 将读到的两个数组合为一个数字
        mov bl,input1
        mov dl,input1
        mov bh,0
        mov dh,0
        mov cl,3
        shl bl,cl
        shl dl,1
        add bl,dl
        add bl,input2
        mov input,bl
    ; 在数组中查找成绩
        lea si, score
        mov cx, 100
FIND_SCORE:
        mov al,[si]
        cmp al, bl
        jne NEXT
        mov al,'Y'
        mov found, al
        jmp done
NEXT:
        inc si
        loop FIND_SCORE

done:
    ; 输出结果
        mov ah, 09h
        lea dx, found
        int 21h
        mov ax,4c00h
        int 21h

code    ends
        end start
