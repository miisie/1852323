#include <stdio.h>
#include <time.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char *pcTextForTask1 = " Task 1";
static const char *pcTextForTask2 = " Task 2";
static const char *pcTextForTask3 = " Task 3";

void task1(void *pvParameter){
    uint16_t start_time = xTaskGetTickCount();
    TickType_t x50ms = pdMS_TO_TICKS( 50 );
    ESP_LOGI(pcTextForTask1,"Start at tick %d",start_time);
    while ( x50ms > 0){
        ESP_LOGI(pcTextForTask1,"Task 1 is running at tick %d",xTaskGetTickCount());
        x50ms --;
        taskYIELD();
    }
    ESP_LOGI(pcTextForTask1,"End at tick %d",xTaskGetTickCount());
    vTaskDelete(NULL);
}

void task2(void *pvParameter){
    uint16_t start_time = xTaskGetTickCount();
    TickType_t x50ms = pdMS_TO_TICKS( 50 );
    ESP_LOGI(pcTextForTask2,"Start at tick %d",start_time);
    while ( x50ms > 0){
        ESP_LOGI(pcTextForTask2,"Task 2 is running at tick %d",xTaskGetTickCount());
        x50ms --;
        taskYIELD();
    }
    ESP_LOGI(pcTextForTask2,"End at tick %d",xTaskGetTickCount());
    vTaskDelete(NULL);
}

void task3(void *pvParameter){
    uint32_t start_time = xTaskGetTickCount();
    TickType_t x50ms = pdMS_TO_TICKS( 50 );
    ESP_LOGI(pcTextForTask3,"Start at tick %d",start_time);
    while ( x50ms > 0){
        ESP_LOGI(pcTextForTask3,"Task 3 is running at tick %d",xTaskGetTickCount());
        x50ms --;
        taskYIELD();
    }
    ESP_LOGI(pcTextForTask3,"End at tick %d",xTaskGetTickCount());
    vTaskDelete(NULL);
}

void app_main(void)
{
    if(xTaskCreatePinnedToCore(&task1, "Task 1", 10000, (void *)pcTextForTask1, 0, NULL, 1) == pdPASS){
        ESP_LOGI(pcTextForTask1,"Task 1 successfully created");
    };
    if(xTaskCreatePinnedToCore(&task2, "Task 2", 10000, (void *)pcTextForTask2, 1, NULL, 1) == pdPASS){
        ESP_LOGI(pcTextForTask2,"Task 2 successfully created");
    };
    if(xTaskCreatePinnedToCore(&task3, "Task 3", 10000, (void *)pcTextForTask3, 1, NULL, 1) == pdPASS){
        ESP_LOGI(pcTextForTask3,"Task 3 successfully created");
    };
}

