


        
        mov cx,10000
        div cx
        add ax,30h
        ;保存余数
        mov bx,dx
        ;显示
        mov ah,02h
        mov dl,al
        int 21h
        ;将余数挪到ax，再除以1000，显示千位数
        mov cx,1000
        mov ax,bx
        div cx
        add ax,30h
        ;保存余数
        mov bx,dx
        ;显示
        mov ah,02h
        mov dl,al
        int 21h
        ;将余数挪到ax，再除以100，显示百位数
        mov cl,100
        mov ax,bx
        div cl
        add ax,30h
        ;保存余数
        mov bl,ah
        ;显示
        mov ah,02h
        mov dl,al
        int 21h
        ;将余数挪到ax，再除以10，显示十位数
        mov cl,10
        mov al,bl
        mov ah,0
        div cl
        add al,30h
        ;保存余数
        mov bh,ah
        ;显示
        mov ah,02h
        mov dl,al
        int 21h
        ;显示个位数
        mov ah,02h
        mov dl,bh
        int 21h