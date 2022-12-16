#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include <stm32f303xe.h>
#include <stm32f3xx_it.h>

//UART status struct typedef
typedef enum
{
    UART_OK = 0x00U,
    UART_ERROR = 0x01U
}
UART_Status;

//UART init struct typedef
typedef struct
{
    uint32_t BaudRate;
    uint32_t WordLength;
    uint32_t StopBits;
    uint32_t Parity;
    uint32_t Mode;
    uint32_t HardwareFLowControl;
    uint32_t OverSampling;
    uint32_t OneBitSampling;
}
UART_InitTypeDef;

//UART handle struct typedef
typedef struct 
{
    USART_TypeDef *USARTx_p;
    UART_InitTypeDef USARTx_Init;

    uint8_t *TxBuffer_p;
    uint16_t TxBufferSize;
    __IO uint16_t TxCounter;

    uint8_t *RxBuffer_p;
    uint16_t RxBufferSize;
    __IO uint16_t RxCounter;

    void (*RxISR_p)(struct UART_Handle_t *USARTx_p); 
    void (*TxISR_p)(struct UART_Handle_t *USARTx_p); 
}
UART_Handle_t;

//Initialization/deinitialization functions
UART_Status UART_Init(UART_Handle_t *UARTx_p);
UART_Status UART_Deinit(UART_Handle_t *UARTx_p);

//Transfer functions
//Polling
UART_Status UART_Transmit(UART_Handle_t *UARTx_p, uint8_t *Data, uint16_t Size);
UART_Status UART_Receive(UART_Handle_t *UARTx_p, uint8_t *Data, uint16_t Size);
//Interrupt
UART_Status UART_Transmit_IT(UART_Handle_t *UARTx_p, uint8_t *Data, uint16_t Size);
UART_Status UART_Receive_IT(UART_Handle_t *UARTx_p, uint8_t *Data, uint16_t Size);
//DMA
UART_Status UART_Transmit_DMA(UART_Handle_t *UARTx_p, uint8_t *Data, uint16_t Size);
UART_Status UART_Receive_DMA(UART_Handle_t *UARTx_p, uint8_t *Data, uint16_t Size);
UART_Status UART_DMA_Pause(UART_Handle_t *UARTx_p);
UART_Status UART_DMA_Resume(UART_Handle_t *UARTx_p);
UART_Status UART_DMA_Stop(UART_Handle_t *UARTx_p);

#endif




