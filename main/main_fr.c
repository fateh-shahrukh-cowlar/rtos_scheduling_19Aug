#include <stdio.h>
#include"freertos/FreeRTOS.h"   
#include "esp_log.h"
#include"freertos/task.h"
#include "esp_system.h"
//#define TAG "Delay"
#define TAG "DICE"
void func(void) //to run it as main change func to app_main
{
    int i=0;
   
    while (1)
    {
        vTaskDelay(1000/portTICK_PERIOD_MS);
        //ESP_LOGI(TAG,"in loop %d",i++);
        ESP_LOGI(TAG,"random number %d",esp_random());
    }
    
    
}
