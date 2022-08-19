#include <stdio.h>
#include"freertos/FreeRTOS.h"   
#include "esp_log.h"
#include"freertos/task.h"
#define TAG "Delay"
//void app_main(void) //to run it as main change func to app_main
{
    int i=0;
   
    while (1)
    {
        vTaskDelay(1000/portTICK_RATE_MS);
        ESP_LOGI(TAG,"in loop %d",i++);
    }
    
    
}