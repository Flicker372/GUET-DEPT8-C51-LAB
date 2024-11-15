#define MAIN_Fosc		24000000L	//??????

#include <STC15Fxxxx.H>

#define uchar unsigned char 
#define uint unsigned int 

code uchar disptab[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
sbit S1=P3^2;
sbit S2=P3^3;
sbit S3=P3^4;
sbit S4=P3^5;
#define SEG P0
uchar DIS[4],ptr;
void SEGDIS()
{ 
	 SEG=0X00;  //????
	 S1=1; S2=1; S3=1; S4=1; //???
	 switch(ptr)  //????
	 {
		 case 0: S1=0; break;
		 case 1: S2=0; break;
		 case 2: S3=0; break;
		 case 3: S4=0; break;
	 }
   SEG=DIS[ptr]; //????
	 ptr=(ptr+1)&3; //?????
}	

void	GPIO_config(void)
{
  P0n_push_pull(0XFF);//??IO?
  P3n_push_pull(0X3C);//??IO?
}

void main(void)
{
	GPIO_config();
	DIS[0]=disptab[1]; 
	DIS[1]=disptab[0]; 
	DIS[2]=disptab[1]; 
	DIS[3]=disptab[5]; 
	while(1)
	{
			SEGDIS();
			delay_ms(5);
	}
}
