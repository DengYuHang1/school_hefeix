stack segment stack
      dw 512 dup(?)
stack ends

data segment
    score db 100 DUP(?)
    myscore db ?  ;用户输入的成绩
data ends

code segment
     assume cs:code,ds:data,ss:stack
start:
    mov ax,data
    mov ds,ax
    lea di,score
    mov cx,100
create:         ;生成成绩
    mov byte ptr[di],cl
    inc di
    loop create

    mov ah,1    ;用户输入
    int 21h

    lea di,score
    mov cx,100
 CM:   
    cmp al,[di]
    je output   ;匹配成功输出
    inc di
    loop CM

    mov ah,02h  ;失败输出N
    mov dl,'N'
    int 21h
    jmp done

output:
    mov ah,02h  ;成功输出Y
    mov dl,'Y'
    int 21h
done:
    mov ah,4ch
    int 21h


code ends
     end start