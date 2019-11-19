#include"stm32f10x.h"
#include"key.h"
#include"exti.h"
#include"led.h"
#include"delay.h"
#include"usart.h"
#include"sd.h"

int main(){
	int i;
	//Doubt is the key to konwledge. 
	unsigned char send[512] = "The greatest test of courage on earth is to bear defeat without losing heart.";
	unsigned char recv[512] = "";
	key_init();
	led_init();
//	led_on(1);
	key_on();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	exti0_init();
	delay_init();
	uart3_init(115200);
	while(sd_init()){
		printf("SD init fail!");
		delay_ms(1000);
	}
	sd_write(send,0,1);
	sd_read(recv,0,1);
		for(i=0;i<512;i++){
			printf("%c ",recv[i]);
		}
	while(1){
//		printf("Hello World!");
		delay_ms(1000);
	}
}
