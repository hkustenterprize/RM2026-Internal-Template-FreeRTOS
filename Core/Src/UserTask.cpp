/**
 * @file UserTask.cpp
 * @author JIANG Yicheng  RM2023 (EthenJ@outlook.sg)
 * @brief Create user tasks with cpp support
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 */
#include "AppConfig.h" // Include our customized configuration
#include "FreeRTOS.h"
#include "gpio.h"
#include "main.h"
#include "task.h"

StackType_t uxTask0Stack[configMINIMAL_STACK_SIZE];
StaticTask_t xTask0TCB;
void task0(void *pvPara) {
  while (true) {
    HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
    vTaskDelay(60);
    HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
    vTaskDelay(940);
  }
}

/**
 * @brief Intialize all the drivers and add task to the scheduler
 * @todo  Add your own task in this file
 */
void startUserTasks() {
  xTaskCreateStatic(task0, "task0", configMINIMAL_STACK_SIZE, NULL, 0,
                    uxTask0Stack, &xTask0TCB);
  /**
   * @todo Add your own task here
   */

}
