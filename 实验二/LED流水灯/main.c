#define MAIN_Fosc 24000000L // 24MHz

#include <STC15Fxxxx.h>

#define uchar unsigned char
#define uint unsigned int

#define SEG P0 // P0口

// 控制LED的数组，4种方式
code uchar ledtab1[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
code uchar ledtab2[] = {0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x0C, 0x81};
code uchar ledtab3[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
code uchar ledtab4[] = {0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55};

// 按键P3口
sbit K1 = P3^2;
sbit K2 = P3^3;
sbit K3 = P3^4;
sbit K4 = P3^5;

uchar i; // 计数
uchar mode; // 模式

// LED函数
void SEGLED(void)
{
    SEG = 0x00; // 清空LED显示

    switch (mode)
    {
        case 0:
            SEG = ledtab1[i];
            break;
        case 1:
            SEG = ledtab2[i];
            break;
        case 2:
            SEG = ledtab3[i];
            break;
        case 3:
            SEG = ledtab4[i];
            break;
    }

    i = (i + 1) % 8;
    delay_ms(200);
}

void GPIO_config(void)
{
    P0n_push_pull(0XFF);
    P3n_pure_input(0X3C);
}

// 按键处理函数
void KeyScan(void)
{
    if (K3 == 0 && K4 == 0)
    {
        mode = 0;
    }
    else if (K3 == 0 && K4 == 1)
    {
        mode = 1;
    }
    else if (K3 == 1 && K4 == 0)
    {
        mode = 2;
    }
    else if (K3 == 1 && K4 == 1)
    {
        mode = 3;
    }
}

// 主函数
void main(void)
{
    GPIO_config();
    mode = 0; // 初始化模式
    while (1)
    {
        KeyScan();
        SEGLED();
    }
}
