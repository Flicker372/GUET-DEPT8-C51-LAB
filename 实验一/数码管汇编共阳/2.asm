ORG 0000H
MOV DPTR, #TAB          ; 初始化段码表的地址
MOV R0, #0
MOV R1, #04H            ; 使用P3.2作为初始位选

MAIN:
    MOV P0, #0FFH       ; 清屏，关闭所有段
    MOV P3, #0FFH       ; 清除位选，关闭所有数码管
    ACALL DELAY         ; 短延时以确保清屏有效

    MOV A, R0
    MOVC A, @A+DPTR
    MOV P0, A

    MOV A, R1
    MOV P3, A
    ACALL DELAY
    INC R0
    RL A
    ANL A, #03CH         ; 只保留P3.2到P3.5的有效位
    MOV R1, A

    CJNE R0, #04H, MAIN
    MOV R0, #00H        ; 重置R0和R1
    MOV R1, #04H
    SJMP MAIN

TAB: DB 0xF9, 0xC0, 0xF9, 0x92  ; 数码管段码表，显示 1015

DELAY:
    MOV R7, #255        ; 延时
DELAY_LOOP:
    DJNZ R7, DELAY_LOOP
    RET

END
