/*
 * D.c
 *
 * Created: 2/15/2024 10:07:01 PM
 * Author : Apple
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h> 









int main(void)
{
    DDRA = 0xF0;;
	DDRB = 0xFF;
	DDRD = 0xFF;
	DDRC = 0xFF;

	DDRD = 0xFF;
	int counter=0;
	
	lcd_init();
	int mode=0;
	char val[100] = {0};
	int dt=100;
	
	int num1,num2=0;//num1 indecates array that first number ends;num2 indecates array that second number ends;
	
	char number1_c[16];
	char number2_c[16];
		
	int number1_i;
	int number2_i;
		
	char result_c[16];
	int result_i;
	float result_f;
	float number2_f;
	
    while (1) 
    {
		
		
		
		if(PINB==1){
			
			//uint8_t byteRead = eeprom_read_byte((uint8_t*)23); // read the byte in location 23
			result_f = eeprom_read_float((uint8_t*)64); // read the byte in location 23
			dtostrf(result_f, 3, 3, result_c);
			lcd_clear();
		
			
			lcd_setcursor(0,2);
			lcd_string(result_c);
			_delay_ms(10);
			
		}
		
		
		// detection 
		PORTA = 0b10000000;
		_delay_ms(dt);
		if (PINA&0b00001111){
			if ((PINA&0b00001111)==0b00000001) {val[counter] =  'c';val[counter+1] =  'o';val[counter+2] =  's';counter=+2;mode = 1;num2=counter;}
			if ((PINA&0b00001111)==0b00000010) val[counter] =  '3';
			if ((PINA&0b00001111)==0b00000100) val[counter] =  '2';
			if ((PINA&0b00001111)==0b00001000) val[counter] =  '1';
			counter++;
			
		
		
		}
		
		PORTA = 0b01000000;
		_delay_ms(dt);
		if (PINA&0b00001111){
			if ((PINA&0b00001111)==0b00000001) {val[counter] =  's';val[counter+1] =  'i';val[counter+2] =  'n';counter=+2;mode = 2;num2=counter;}
			if ((PINA&0b00001111)==0b00000010) val[counter] =  '6';
			if ((PINA&0b00001111)==0b00000100) val[counter] =  '5';
			if ((PINA&0b00001111)==0b00001000) val[counter] =  '4';
			counter++;
			
			
			
		}
		
		PORTA = 0b00100000;
		_delay_ms(dt);
		if (PINA&0b00001111){
			if ((PINA&0b00001111)==0b00000001) {val[counter] =  '-';mode = 3;num1=counter;}
			if ((PINA&0b00001111)==0b00000010) val[counter] =  '9';
			if ((PINA&0b00001111)==0b00000100) val[counter] =  '8';
			if ((PINA&0b00001111)==0b00001000) val[counter] =  '7';
			counter++;
			
			
			
		}
		
		PORTA = 0b00010000;
		_delay_ms(dt);
		if (PINA&0b00001111){
			if ((PINA&0b00001111)==0b00000001) {val[counter] =  '+';mode = 4;num1=counter;}
			if ((PINA&0b00001111)==0b00000010) {//=
				
				
				num2=counter;
				
				
				if (mode==1||mode==2)
				{
					
					
					
					for(int i=0; i<num2-3;i++){
						number2_c[i] = val[i+3];
						
					}
					
					
					
				}else if (mode!=0)
				{
					for(int i=0;i<num1;i++){
						number1_c[i]=val[i];
						
						
					}
					
					for(int i=0; i<num2-num1-1;i++){
						number2_c[i] = val[i+num1+1];
						
					}
				}
				
				
				//int nb = atoi(&number1);
				//result = itoa(atoi(&number2));
				
				number1_i = atoi(number1_c);
				number2_i = atoi(number2_c);
				
				
				
				
				if (mode==1)
				{
					float number2_f = (float)number2_i;
					result_f = cos(number2_f*3.14/180);
					dtostrf(result_f, 3, 3, result_c);
					lcd_clear();
					lcd_setcursor(0,1);
					lcd_string("             ");
					_delay_ms(10);
					
					lcd_setcursor(5,1);
					lcd_string("             ");
					_delay_ms(10);
					
					lcd_setcursor(0,2);
					lcd_string(result_c);
					_delay_ms(10);
				}
				else if (mode==2)
				{
					float number2_f = (float)number2_i;
					result_f = sin(number2_f*3.14/180);
					dtostrf(result_f, 3, 3, result_c);
					lcd_clear();
					lcd_setcursor(0,1);
					lcd_string("             ");
					_delay_ms(10);
					
					lcd_setcursor(5,1);
					lcd_string("             ");
					_delay_ms(10);
					
					lcd_setcursor(0,2);
					lcd_string(result_c);
					_delay_ms(10);
				}
				else if (mode==3)
				{
					result_i = number1_i-number2_i;
					result_f = (float)result_i;
					itoa(result_i,result_c,10);
					lcd_clear();
					lcd_setcursor(0,1);
					lcd_string(number1_c);
					_delay_ms(10);
					
					lcd_setcursor(5,1);
					lcd_string(number2_c);
					_delay_ms(10);
					
					lcd_setcursor(0,2);
					lcd_string(result_c);
					_delay_ms(10);
				}
				else if (mode==4)
				{
					result_i = number1_i+number2_i;
					result_f = (float)result_i;
					itoa(result_i,result_c,10);
					lcd_clear();
					lcd_setcursor(0,1);
					lcd_string(number1_c);
					_delay_ms(10);
					
					lcd_setcursor(5,1);
					lcd_string(number2_c);
					_delay_ms(10);
					
					lcd_setcursor(0,2);
					lcd_string(result_c);
					_delay_ms(10);
					
				}
				else
				{
					
					
				}
				
				counter=-1;
				
				
				
				
				
				//////////////////////// saving result
				//eeprom_write_byte ((uint8_t*) 23, 64); //  write the byte 64 to location 23 of the EEPROM
				eeprom_write_float((uint8_t*) 64, result_f); //  write the byte 64 to location 23 of the EEPROM
				
				val[0]='\0';
				val[1]='\0';
				val[2]='\0';
				val[3]='\0';
				val[4]='\0';
				val[5]='\0';
				val[6]='\0';
				val[7]='\0';
				val[8]='\0';
				val[9]='\0';
				val[10]='\0';
				val[11]='\0';
				val[12]='\0';
				val[13]='\0';
				val[14]='\0';
				val[15]='\0';
				
				
				
				
				number1_c[0]='\0';
				number1_c[1]='\0';
				number1_c[2]='\0';
				number1_c[3]='\0';
				number1_c[4]='\0';
				number1_c[5]='\0';
				number1_c[6]='\0';
				number1_c[7]='\0';
				
				
				
				number2_c[0]='\0';
				number2_c[1]='\0';
				number2_c[2]='\0';
				number2_c[3]='\0';
				number2_c[4]='\0';
				number2_c[5]='\0';
				number2_c[6]='\0';
				number2_c[7]='\0';
				
				
				
				
				result_c[0]='\0';
				result_c[1]='\0';
				result_c[2]='\0';
				result_c[3]='\0';
				result_c[4]='\0';
				result_c[5]='\0';
				result_c[6]='\0';
				result_c[7]='\0';
				result_c[8]='\0';
				result_c[9]='\0';
				result_c[10]='\0';
				result_c[11]='\0';
				result_c[12]='\0';
				result_c[13]='\0';
				result_c[14]='\0';
				result_c[15]='\0';
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
			}
			if ((PINA&0b00001111)==0b00000100) val[counter] =  '0';
			if ((PINA&0b00001111)==0b00001000) {//clc
				lcd_clear();
				counter=-1;
				val[0]='\0';
				val[1]='\0';
				val[2]='\0';
				val[3]='\0';
				val[4]='\0';
				val[5]='\0';
				val[6]='\0';
				val[7]='\0';
				val[8]='\0';
				val[9]='\0';
				val[10]='\0';
				val[11]='\0';
				val[12]='\0';
				val[13]='\0';
				val[14]='\0';
				val[15]='\0';
				
			}
			counter++;
			val[counter]='\0';
			
			
			
		}
		
		
		lcd_setcursor(0,1);
		lcd_string(val);
		_delay_ms(10);

		
		
	}
}

