#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "esp_log.h"
#include "freertos/task.h"
#include "freertos/queue.h"
int i = 0;
int rx = 0;
xQueueHandle Global_Queue_Handle = 0;
void send_task(void *arg)
{

    while (1)
    {
        ESP_LOGI("freertos", "This is i value %d", i);
        // printf("send %i to reciever task\n",i);
        if (xQueueSend(Global_Queue_Handle, &i, 1000 / portTICK_RATE_MS))
        {
            puts("send success");
        } // item we want to send is always by pointer 'i' and 1000 is ticks
        else
        {
            puts("send failed");
        }
        ++i;
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}
void reciever_task(void *arg)
{

    while (1)
    {
        if (xQueueReceive(Global_Queue_Handle, &rx, 1000 / portTICK_RATE_MS))
        {
            puts("recieved");
        }
        else
        {
            puts("recieved Failed");
        }
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}

void app_main(void) // to run it as main change func to app_main
{
    vTaskDelay(pdMS_TO_TICKS(100));
    Global_Queue_Handle = xQueueCreate(100, sizeof(int));
    xTaskCreate(send_task, (char *)"tx", 1024, NULL, 5, NULL);
    xTaskCreate(reciever_task, (char *)"rx", 1024, NULL, 5, NULL);
    // vTaskStartScheduler();
}
