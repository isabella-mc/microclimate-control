/*
 * File:   ProgramaPrincipal.c
 * Author: mapca
 *
 * Created on 9 de marzo de 2022, 10:38 PM
 */


#include <xc.h>
#include "Configuracion.h"
#include "LCD_libreria.h"

void LCD_Init(void){
    OpenXLCD(FOUR_BIT & LINES_5X7 );
    while(BusyXLCD()); // LCD esta ocupado
    WriteCmdXLCD(0x06); //Mover el cursor a la derecha
    WriteCmdXLCD(0x0C); //Desactivar el cursor
}

void InitPort(void){
    ADCON1bits.PCFG = 0xFF; //Digitales
    TRISB = 1; //Entrada
    TRISA = 0; //Salida
    LATB = 1;
    LATA = 1;
    
}

void Timer0_Init(void){
    T0CONbits.T0CS = 0; //Temporizador
    T0CONbits.PSA = 0; //Habilita el pre escaler
    T0CONbits.T0PS = 0b111; // 256 pre escaler
    T0CONbits.T08BIT = 0; //16 bits de cuenta/2 bytes (alto y bajo)
    T0CONbits.TMR0ON = 1; //Timer0 empieza
    INTCONbits.TMR0IF = 0; //Flag del Timer0 apagado
    INTCONbits.TMR0IE = 1; //Permitir desbordamiento
    INTCONbits.PEIE = 1; // Interrupciones de perifericos
    INTCONbits.GIE = 1;
    TMR0L = 6942;
    TMR0H = (6942) >>8;
    
}

void main(){
    int i;
    const char* buffer1[20];
    LCD_Init();
    InitPort();
    Timer0_Init();
    while(1){
        LCD_gotoXY(0,0);
        putrsXLCD("TIEMPO: ");
        if(PORTBbits.RB0 == 0){
            __delay_ms(50);
            LCD_gotoXY(1,5);              
            putrsXLCD("30 segundos");
        }
    }
}

void __interrupt () ISR_timer0(void){
    if(INTCONbits.TMR0IF){
        while(BusyXLCD());              
        WriteCmdXLCD(0x01); //Limpia la LCD
        LCD_gotoXY(0,0);
        putrsXLCD("La cosecha esta");
        LCD_gotoXY(1,5);
        putrsXLCD("lista");
        __delay_ms(100);
        LATAbits.LA4 = 1;
    }
}

//Temporizador = (4/Fosc)*Pre-escaler*(x+1)
//        3s = (4/20MHz)*256*(x+1)
//        x   = 58592.75 = 58593
//        65535 - 58593 = 6942 