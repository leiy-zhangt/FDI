#include "taskinit.h"

void TaskInit(void)
{
	//Create LEDTwinkTask
	LEDTwinkTask_Ret = xTaskCreate((TaskFunction_t)LEDTwinkTask,"LEDTwinkTask",32,(void *)1,LEDTwinkTask_Prio,(TaskHandle_t *)(&LEDTwinkTask_TCB));
	if(LEDTwinkTask_Ret == pdPASS) ;
	else
	{
		while(1) ;
	}
	//Create NavigationTask
	NavigationTask_Ret = xTaskCreate((TaskFunction_t)NavigationTask,"NavigationTask",256,(void *)1,NavigationTask_Prio,(TaskHandle_t *)(&NavigationTask_TCB));
	if(NavigationTask_Ret == pdPASS) ;
	else
	{
		while(1) ;
	}
	//Create ControlTask
	ControlTask_Ret = xTaskCreate((TaskFunction_t)ControlTask,"ControlTask",32,(void *)1,ControlTask_Prio,(TaskHandle_t *)(&ControlTask_TCB));
	if(ControlTask_Ret == pdPASS) ;
	else
	{
		while(1) ;
	}
	//Create TFStorageTask
	TFStorageTask_Ret = xTaskCreate((TaskFunction_t)TFStorageTask,"TFStorageTask",256,(void *)1,TFStorageTask_Prio,(TaskHandle_t *)(&TFStorageTask_TCB));
	if(TFStorageTask_Ret == pdPASS) ;
	else
	{
		while(1) ;
	}
	
	
	
	vTaskStartScheduler();
}

//LEDTwinkTask函数声明
BaseType_t LEDTwinkTask_Ret;
UBaseType_t LEDTwinkTask_Prio=2;
TaskHandle_t LEDTwinkTask_TCB;

void LEDTwinkTask(void *pvParameters)
{
	while(1)
	{
		HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
		vTaskDelay(100);
	}
}

//NavigationTask函数声明
BaseType_t NavigationTask_Ret;
UBaseType_t NavigationTask_Prio=25;
TaskHandle_t NavigationTask_TCB;

void NavigationTask(void *pvParameters)
{
	while(1)
	{
		NavigationReceive();
	}
}

//ControlTask函数声明
BaseType_t ControlTask_Ret;
UBaseType_t ControlTask_Prio;
TaskHandle_t ControlTask_TCB;

void ControlTask(void *pvParameters)
{
	while(1)
	{
		vTaskDelay(200);
	}
}
	

//TFStorageTask函数声明
BaseType_t TFStorageTask_Ret;
UBaseType_t TFStorageTask_Prio=12;
TaskHandle_t TFStorageTask_TCB;

void TFStorageTask(void *pvParameters)
{
	TFInit();
	vTaskSuspend(NULL);
	while(1)
	{
		
	}
}
