stack segment stack
          db 1024 dup(?)
stack ends
data segment
    x    dw 10
    y    dw 20
    z    dw 30
    v    dw 40
    sum1 dw ?
    sum2 dw ?
data ends
code segment 'code'
          assume cs:code,ds:data,ss:stack
    start:mov    ax,data
          mov    ds,ax

          mov    ax,x
          imul   y
          mov    cx,ax
          mov    bx,dx
          mov    ax,z
          cwd
          add    cx,ax
          adc    bx,0
          sub    cx,720
          sbb    bx,0
          mov    ax,v
          cwd
          mov    dx,0
          sub    ax,cx
          sbb    dx,bx
          mov    bx,x
          idiv   bx
          mov    sum1,ax
          mov    sum2,dx

          mov    ah,4ch
          int    21h

code ends
        end start