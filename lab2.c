#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

void cyclic_task(void *pvParameter){
	while(1){
	   printf("Bui Quang Duc_1852323\n");
	   vTaskDelay(1000 / portTICK_RATE_MS);
	}
}
 
void acyclic_task(void *pvParameter){
   gpio_pad_select_gpio(GPIO_NUM_0);
   gpio_set_direction(GPIO_NUM_0, GPIO_MODE_INPUT);
   while(1) {        
      if (!gpio_get_level(GPIO_NUM_0)){
         printf("ESP32\n");
      }
      vTaskDelay(100 / portTICK_RATE_MS);
   }
}
 
void app_main(){
   xTaskCreate(&cyclic_task, "Cyclic task", 2048, NULL, 1, NULL);
   xTaskCreate(&acyclic_task, "Acyclic task", 2048,NULL,1,NULL );
   printf("Restarting now.\n");
}