/* 
 * File:   lcd.h
 * Author: Tuan
 *
 * Created on March 14, 2019, 10:40 AM
 */

#include <xc.h>
#include <stdio.h>
#include <string.h>



#define RS RC4
#define EN RC5
#define D0 RD7
#define D1 RD6
#define D2 RD5
#define D3 RD4
#define D4 RD3
#define D5 RD2
#define D6 RD1
#define D7 RD0

void LCD_port(unsigned char a)
{
    if(a & 1)
    
        D0 = 1;
    
    else D0 = 0;
    
    if(a & 2)
    
        D1 = 1;
    
    else D1 = 0;
    
    if(a & 4)
    
        D2 = 1;
    
    else D2 = 0;
    
    if(a & 8)
   
        D3 = 1;
   
    else D3 = 0;
    
    if(a & 16)
    
        D4 = 1;
    
    else D4 = 0;
    
    if(a & 32)
    
        D5 = 1;
    
    else D5 = 0;
    
    if(a & 64)
        D6 = 1;
    else D6 = 0;
    
    if(a & 128)
        D7 = 1;  
    else 
        D7 = 0;
}

void LCD_cmd(unsigned char a)
{

    RS = 0;
    LCD_port(a);
    EN = 1;
    __delay_ms(4);
    EN = 0;
}

void LCD_data_in(unsigned char a)
{
    RS = 1;
    LCD_port(a);
    EN = 1;
    __delay_ms(4);
    EN = 0;
}

void LCD_set_cursor(unsigned char x, unsigned char y)
{
    if (x == 1)
    {
        LCD_cmd(0x80 + y - 1);
    } 
    else if ( x == 2)
    {
        LCD_cmd(0xC0 + y - 1);
    }
}

void LCD_write_char(unsigned char a)
{
    LCD_data_in(a);
}

void LCD_write_string(char *a)
{
    int i ;
    for(i = 0; i < strlen(a); i++ )
    {
        LCD_write_char(a[i]);
    }
}

void LCD_clear(void)
{
    RS = 0;
    LCD_cmd(0x01);
    __delay_ms(10);
}

void LCD_init_LCD(void)
{ 
    RS = 0;
    EN = 0;
    __delay_ms(20);
    LCD_cmd(0x30);      //reset function
    LCD_cmd(0x38);      //8 bit mode
    LCD_cmd(0x08);      //display off
    LCD_clear();        //clear RAM
    LCD_cmd(0x06);      //Entry mode
    LCD_cmd(0x0C);      //display on
    __delay_ms (2);
    
}
