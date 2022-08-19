#include <stdio.h>
#include"freertos/FreeRTOS.h"   
#include "esp_log.h"
#include"freertos/task.h"
#include"freertos/queue.h"
int i=0;
void my_task(void *p)
{
   while(1)
   {
    puts("here");
    vTaskDelay(500);
   printf("%d",i);
    i++;
   }
}
void func(void) //to run it as main change func to app_main
{
   
    xTaskCreate(my_task,(char*) "my_task",1024,NULL,1,NULL);
    vTaskStartScheduler();
    
}
