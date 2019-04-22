/* 
 * File:   dht11.h
 * Author: Tuan
 *
 * Created on February 28, 2019, 6:27 PM
 */

/* 
 * File:   dht11.h
 * Author: Tuan
 *
 * Created on October 20, 2018, 9:02 PM
 */

#include <stdlib.h>
#include <stdint.h>
#define DHT11_DATA RB2
#define DHT11_TRIS TRISB2
unsigned char H_humid;
unsigned char H_temp;

unsigned char check_humid(void)
{
    return H_humid;
}

unsigned char check_temp(void)
{
    return H_temp;
}
int dht11_data[40];
uint8_t DHT11_init(void)
{
    
    DHT11_TRIS = 0;     //Set output
    DHT11_DATA = 0;     //send from MCU 0
    __delay_ms(20);
    DHT11_DATA = 1;     //signal from MCU goes to 1
    __delay_us(30);
    DHT11_TRIS = 1;     //Set input
   
    __delay_us(60);  
    if(DHT11_DATA) return 0;   // Test if signal is low, if high->error
    else while(!DHT11_DATA);   // Wait for the signal to be high
    __delay_us(60);
    if(!DHT11_DATA) return 0;  // Test if signal is high, if low->error
    else while(DHT11_DATA);   // Wait for the signal to be low
        
    unsigned char a[5];                         // receive data
    char j = 0;
    char k = 0;
    
   while(j < 5)
    {
        a[j] = 0;
        j++;
    }
    j = 0;
    for(j = 0; j < 5; j++)
    {
        for(k = 0; k < 8; k++)
        {
            while(!DHT11_DATA);  //wait data to go high
            __delay_us(50);
            if(DHT11_DATA)
            {
            a[j] |= (1<<(7 - k));
            while(DHT11_DATA);   //wait data to go low
            }
        }
    }
    
    int L_humid,L_temp;
    int sum;
    sum     =  a[0] + a[1] + a[2] + a[3];
    if(sum != a[4]) return 0;   //Error
    H_humid = a[0];
    L_humid = a[1];
    H_temp  = a[2];
    L_temp  = a[3];
    return 1;  
}



