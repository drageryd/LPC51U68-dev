//#include "pin_mux.h"
//#include "board.h"
#include "fsl_gpio.h"

//#include <stdbool.h>
#define APP_BOARD_TEST_LED_PORT 1U
#define APP_BOARD_TEST_LED_PIN  0U

//volatile uint32_t g_systickCounter;
//uint8_t swState = APP_SW_STATE_RELEASED;
//int8_t filter   = -1;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*
void SysTick_Handler(void)
{
    if (g_systickCounter != 0U)
    {
        g_systickCounter--;
    }
}

void SysTick_DelayTicks(uint32_t n)
{
    g_systickCounter = n;
    while (g_systickCounter != 0U)
    {
    }
}
*/

volatile unsigned int i;

/*!
 * @brief Main function
 */
int main(void)
{
    /* Define the init structure for the output LED pin*/
    gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput,
        0,
    };

    /* Board pin, clock, debug console init */
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    //CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);
    /* enable clock for GPIO*/
    //CLOCK_EnableClock(kCLOCK_Gpio0);
    //CLOCK_EnableClock(kCLOCK_Gpio1);

    //BOARD_InitBootPins();
    //BOARD_InitBootClocks();

    /* Init output LED GPIO. */
    GPIO_PortInit(GPIO, APP_BOARD_TEST_LED_PORT);
    GPIO_PinInit(GPIO, APP_BOARD_TEST_LED_PORT, APP_BOARD_TEST_LED_PIN, &led_config);
    GPIO_PinWrite(GPIO, APP_BOARD_TEST_LED_PORT, APP_BOARD_TEST_LED_PIN, 1);

    /* Port masking */
    //GPIO_PortMaskedSet(GPIO, APP_BOARD_TEST_LED_PORT, 0x0000FFFF);
    //GPIO_PortMaskedWrite(GPIO, APP_BOARD_TEST_LED_PORT, 0xFFFFFFFF);

    /* Set systick reload value to generate 1ms interrupt */
    /*
    if (SysTick_Config(SystemCoreClock / 1000U))
    {
        while (1)
        {
        }
    }
    */

    //GPIO_PortSet(GPIO, APP_BOARD_TEST_LED_PORT, 1u << APP_BOARD_TEST_LED_PIN);
    //GPIO_PortClear(GPIO, APP_BOARD_TEST_LED_PORT, 1u << APP_BOARD_TEST_LED_PIN);
    while (1)
    {
        GPIO_PortToggle(GPIO, APP_BOARD_TEST_LED_PORT, 1u << APP_BOARD_TEST_LED_PIN);
        for (i = 0; i < 1200000; i++) {
            __NOP();
        }
        //SysTick_DelayTicks(1000U);
    }
}
