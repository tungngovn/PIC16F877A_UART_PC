/* 
 * File:   newmain.c
 * Author: Tuan
 *
 * Created on February 28, 2019, 3:31 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "main1.h"
#include "uart1.h"
#include "dht11.h"
#include "lcd1.h"

#define UART_TX RC6
#define UART_RX RC7
#define Select RB1
int uart1[32];
int str[20];
unsigned char humid,temp;

void main(){
    
    unsigned char str[20];
    int dust;
    char i;
    
    TRISD = 0x00;
    TRISC5 = 0;
    TRISC4 = 0;
    TRISB1 = 0;
    TRISC6 = 0;
    TRISC7 = 1;
    
    GIE = 1;
    PEIE = 1;
    RCIE = 1;
    INTE = 0;
    INTEDG = 1;
    
    TX9 = 0;
    TXEN = 1;
    SYNC = 0;
    BRGH = 1;
    
    SPEN = 1;
    RX9 = 0;
    CREN = 1;
    ADDEN = 0;
    
    SPBRG = 129;
    
    
    UART_init();
//    LCD_init_LCD();
//    LCD_clear();
//    LCD_set_cursor(1,1);
//    LCD_write_string("Microprocessor");
//    LCD_set_cursor(2,1);
//    LCD_write_string("Group 9");
//    __delay_ms(1000);
//    LCD_clear();
    
    while(1)
    {
        if(DHT11_init())
        {
        humid = check_humid();
        temp = check_temp();
        sprintf(str,"Temperature : %u\r\n", temp);
        UART_Write_Text(str);
        sprintf(str,"Humidity    : %u\r\n", humid);
        UART_Write_Text(str);
        sprintf(str,"__________\r\n");
        UART_Write_Text(str);
        //UART_Write("A");
        __delay_ms(500);
        
//        LCD_set_cursor(1,1);
//        sprintf(str,"Humidity   : %u", humid);
//        LCD_write_string(str);
//        LCD_set_cursor(2,1);
//        sprintf(str,"Temperature: %u", temp);
//        LCD_write_string(str);
//        __delay_ms(1000);
        }
        
    }
    
}

