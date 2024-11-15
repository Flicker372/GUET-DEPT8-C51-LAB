#define MAIN_Fosc 24000000L // 24MHz

#include <STC15Fxxxx.h>

#define uchar unsigned char
#define uint unsigned int

// 按键P3口
sbit K1=P3^2;
sbit Buzzer = P1^0;

// 定义需要用到的自定义函数，把main函数放在开头
void OPENBU(void);
void GPIO_config(void);

// 主函数
void main(void)
{
	GPIO_config();
	OPENBU();
}

// LED函数
void OPENBU()
{
	if (K1 == 1)
		while (K1 == 1)
		{
			// i从0开始，最大为8
			Buzzer = 1;
			delay_ms(100);
			Buzzer = 0;
			delay_ms(100);
		}
}

void GPIO_config(void)
{
	P1n_push_pull(0XFF);
	P3n_pure_input(0X3C);
}
