/* 
 * File:   uart.h
 * Author: Tuan
 *
 * Created on February 28, 2019, 3:31 PM
 */

#define UART_TX RC6
#define UART_RX RC7
#include <string.h>
void UART_init(void)
{

	//TRANSMIT STATUS
    TX9 = 0;   //bit 6
    TXEN = 1;  //bit 5
    SYNC = 0;  //bit 4
    BRGH = 1;  //bit 2
    

	//RECEIVE STATUS 
    SPEN = 1;  //bit 7
    RX9 = 0;   //bit 6
    CREN = 1;  //bit 4
    ADDEN = 0; //bit 3
    
    SPBRG = 129;  // baud rate is 9600
}

void UART_Reg_Put(unsigned char a)
{
    while(!TXIF)
    TXREG = a;
}

void UART_Send_Data(unsigned char *a)
{
    char i ;
    for( i = 0; i < strlen(a); i++)
    {
        UART_Reg_Put(a[i]);
    }
}

unsigned char UART_Receive(void)
{
    while(!RCIF);
    return RCREG;
}

void UART_Write(char data)
{
  while(!TRMT);
  TXREG = data;
}

void UART_Write_Text(char *text)
{
  int i;
  for(i=0;text[i]!='\0';i++)
    UART_Write(text[i]);
}

char UART_Read()
{
  while(!RCIF);
  return RCREG;
}

void UART_Read_Text(char *Output, unsigned int length)
{
  unsigned int i;
  for(int i=0;i<length;i++)
  Output[i] = UART_Read();
}

