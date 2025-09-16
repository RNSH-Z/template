#include "stm32f10x.h"

int main(void)
{
	// 使能串口1
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 115200;// 波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// 字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;// 一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;// 无奇偶校验位
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;// 收发模式
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;// 无硬件数据流控制
	USART_Init(USART1, &USART_InitStructure);
	USART_Cmd(USART1, ENABLE); 

	// 初始化GPIOA的9引脚	TX
	GPIO_InitTypeDef GPIO_InitStructure;// GPIO初始化结构体
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);// 使能GPIOA时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; // PA9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;// 50MHz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; // 复用推挽输出
	GPIO_Init(GPIOA, &GPIO_InitStructure);// 初始化PA9

	// 初始化GPIOA的10引脚   RX
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);// 使能GPIOA时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; // PA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // 上拉输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);// 初始化PA10

	//串口重映射
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);// 使能AFIO时钟
	GPIO_PinRemapConfig(GPIO_Remap_USART1, ENABLE);// 串口1
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);// 使能GPIOB时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; // PB6
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;// 50MHz	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; // 复用推挽输出
	GPIO_Init(GPIOB, &GPIO_InitStructure);// 初始化PB6
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; // PB7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // 上拉输入
	GPIO_Init(GPIOB, &GPIO_InitStructure);// 初始化PB7
	while(1)
	{

	}
}
