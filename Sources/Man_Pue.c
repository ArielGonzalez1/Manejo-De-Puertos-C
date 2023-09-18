// El proposito de esta practica es que aprendamos a usar el manejo de puertos en C usando el QG8 
// Gonzalez Diaz Ariel 

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

unsigned char tiempo= 0x00;
unsigned char boton= 0x00;

void MCU_init(void);//Inicializacion de Puertos 
void secuencia1(void);
void secuencia2(void);
void retardo(void);
void presionar(void);



void main(void) {
  SOPT1 = 0x12; // quitamos Watch Dog
  MCU_init();
  
 
 
  /* include your code here */

  

  for(;;) {
	  if (boton==0){
	 		  secuencia1();
	  }else if (boton==1){
	 		   secuencia2();
	  }else{
	 	  boton= 0x00;
	  }
   
  } /* loop forever */
  /* please make sure that you never leave main */
}


//Inicializacion de Puertos
void MCU_init(void){
	//Puerto A
	PTADD = 0x00; // Ponemos puertos A como entradas 
	PTAPE = 0x0C; // Ponemos PTA0 y PTA1 con PULLUP ENABLE 
	PTAD  = 0x0F; // Inicializa con valores de 1 
	//Puerto B
	PTBDD = 0xFF; // PUERTO B como Salidas 
	PTBD  = 0x00; // Datos de Puerto B con 0 
}

void secuencia1(void){
	unsigned char array [4] = {0x0F, 0xF0, 0xFF}; // creamos un arreglo que hara 3 formas 
	unsigned char i;
	
	for (i=0; i<=3 ; i++){
		PTBD = array[i];
		retardo();
	}
}

void secuencia2(void){
	unsigned char array [4] = {0x0C, 0x72, 0xBC}; // creamos un arreglo que hara 3 formas 
	unsigned char i;
	
	for (i=0; i<=3 ; i++){
		PTBD = array[i];
		retardo();
	}
}

void retardo(void){
	unsigned char x = tiempo;
	unsigned int time;
	if (x>2){
		tiempo = 0x00;
		x = tiempo;
	}else {}
	if (x==0){
		time = 0xFFFF;
	}else if (x==1){
		time = 0x7FFF;
	}else if (x==2){
		time = 0x0FFF;
	}
	while (time!=0){
		time = time-1;
	}
	presionar();
}

void presionar(void){
	if (PTAD_PTAD2==0){
		tiempo = tiempo+1;
	}
	if (PTAD_PTAD3==0){
		boton = boton+1;
	}
	while(PTAD_PTAD2==0){}
	while(PTAD_PTAD3==0){}	
}
