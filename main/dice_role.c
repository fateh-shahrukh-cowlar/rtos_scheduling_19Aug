#include <stdio.h>
#include"freertos/FreeRTOS.h"   
#include "esp_log.h"
#include"freertos/task.h"
#include "esp_system.h"
#include "math.h"
#define TAG "DICE"
int dice_role()
{
    int rand=esp_random();
    int pos=abs(rand);
    int dic_num=(pos%6)+1;
    return dic_num;
}
void func(void) //to run it as main change func to app_main
{
   
    while (1)
    {
        vTaskDelay(1000/portTICK_PERIOD_MS);
        ESP_LOGI(TAG,"Random Number %d",dice_role());
    }
    
    
}
