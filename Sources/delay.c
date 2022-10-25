/*
 * Ʒ�ǿƼ�S32K144������
 * ��лԭ�Ӹ����ʱ����
*/

#include"cpu.h"
#include"delay.h"
#include"uart.h"

static uint32_t fac_us;

/*�ӳٺ����¾�ԭ�Ӹ�*/
void SysTick_Init(void)  //systick �� core_clk 48mhz  ��װ�ؼĴ��� FFFFFF Ϊ16 777 215hz 16.77mhz/48mhz Լ����333����
{
	S32_SysTick->RVR = 0xFFFFFFul; //��װ�ؼĴ���
	S32_SysTick->CVR = 0ul; //��ǰ����
	S32_SysTick->CSR = 0u; //���ƼĴ���
}

/* Enable SysTick counter and interrupt */
void SysTick_Enable(void)
{
	S32_SysTick->CSR = S32_SysTick_CSR_TICKINT(1u) | S32_SysTick_CSR_ENABLE(1);
}

/* Disable SysTick */
void SysTick_Disable(void)
{
	S32_SysTick->CSR = 0ul;
}


static uint32_t fac_us;

void delay_us(uint32_t nus)
{
	uint32_t ticks;
	uint32_t told,tnow,tcnt=0;
	uint32_t reload=S32_SysTick->RVR;				//LOAD��ֵ
	ticks=nus*fac_us; 						//��Ҫ�Ľ�����
	told= S32_SysTick->CVR ;      				//�ս���ʱ�ļ�����ֵ
	while(1)
	{
		tnow= S32_SysTick->CVR ;
		if(tnow!=told)
		{
			if(tnow<told)tcnt+=told-tnow;	//����ע��һ��SYSTICK��һ���ݼ��ļ������Ϳ�����.
			else tcnt+=reload-tnow+told;
			told=tnow;
			if(tcnt>=ticks)break;			//ʱ�䳬��/����Ҫ�ӳٵ�ʱ��,���˳�.
		}
	};
}

void delay_ms(uint32_t nms)
{
	uint32_t i;
	for(i=0;i<nms;i++) delay_us(1000);
}

int delay_init(void)
{
	uint32_t frequency;
	CLOCK_SYS_GetFreq(CORE_CLOCK, &frequency);
	fac_us = frequency / 1000000;// �õ���Ƶ����mhz �����֪��1us���ٸ�����,��Ҫ�� 1 000 000
	SysTick_Init(); //systick �� core_clk 48mhz  ��װ�ؼĴ��� FFFFFF Ϊ16 777 215hz 16.77mhz/48mhz 0.333��  Լ����333����
	SysTick_Enable();
	return fac_us;
}


