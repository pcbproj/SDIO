/*******************************************************************/
#include "stm32f407xx.h"
#include "sdcard.h"



/*******************************************************************/
uint32_t writeBuffer[4]; 
uint32_t readBuffer[4];
SD_CardInfo SDCardInfo;



/*******************************************************************/
int main()
{
	// Тестовые данные для записи
    for (uint16_t i = 0; i < 512; i++)
    {
        writeBuffer[i] = i % 256;
        readBuffer[i] = 0;
    }
    // Иницилизация карты
	SD_Init();
	
    
    // Получаем информацию о карте
    SD_GetCardInfo(&SDCardInfo);
    
    // Выбор карты и настройка режима работы
    SD_SelectDeselect((uint32_t) (SDCardInfo.RCA << 16));
    SD_SetDeviceMode(SD_POLLING_MODE);
    
    // И вот наконец-то запись и чтение
    SD_WriteBlock(0x00, writeBuffer, 512);
    SD_ReadBlock(0x00, readBuffer, 512);
	
	
	while(1)
	{
	}
}



/*******************************************************************/

	 
















/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************


-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/

/*#include <stdio.h>
#include <stdlib.h>
*/
/*********************************************************************
*
*       main()
*
*  Function description
*   Application entry point.
*/
/*int main(void) {
  int i;

  for (i = 0; i < 100; i++) {
    printf("Hello World %d!\n", i);
  }
  do {
    i++;
  } while (1);
}
*/
/*************************** End of file ****************************/
