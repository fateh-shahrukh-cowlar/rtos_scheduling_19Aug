#include <stdio.h>
#include"esp_log.h" 
//#include"freertos/FreeRTOS.h"   
void funct(void) //to run it as main change func to app_main
{
   //printf("hello\n");
    ESP_LOGE("LOG","This is an error");
    ESP_LOGW("LOG","This is a warning");
    ESP_LOGI("LOG","This is an info");
    ESP_LOGD("LOG","This is an Debug");
    ESP_LOGV("LOG","This is an Verbose");
    
    
}
