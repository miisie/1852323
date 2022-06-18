#include <stdio.h>
#include <time.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include<freertos/timers.h>

void ahihi (xTimerHandle  pxTimer);

int TIME_2s  = 200;
int TIME_3s  = 300;
int times_2s = 10;
int times_3s = 5;
xTimerHandle  timer_2s = NULL;
xTimerHandle  timer_3s = NULL;

void ATimerCallback (xTimerHandle  pxTimer){
   int timer_ID = (int) pvTimerGetTimerID( pxTimer );
   
   if (timer_ID == 0){
      static int count = 1;
      if (count <= times_2s){
         printf("Times %d: Ahihi at %d ms\n",count,(int) clock());
         if(count == times_2s){
            printf("End of Ahihi!!!\n");
         }
         else xTimerReset(timer_2s,0);
         count++;
      }
   }
   else {
      static int count = 1;
      if (count <= times_3s){
         printf("Times %d: Ihaha at %d ms\n",count,(int) clock());
         if(count == times_3s){
            printf("End of Ihaha!!!\n");
         }
         else xTimerReset(timer_3s,0);    
         count++;
      }
   }
}

void app_main(void)
{
   timer_2s = xTimerCreate("ahihi",TIME_2s,pdFALSE,(void*)0,ATimerCallback);
   timer_3s = xTimerCreate("ihaha",TIME_3s,pdFALSE,(void*)1,ATimerCallback);
   xTimerStart(timer_2s,0);
   xTimerStart(timer_3s,0);
}


