/*
- Escribe un programa que actúe como un conversor de pulgadas a centímetros y viceversa desde la línea de
comandos. 

- El programa permitirá al usuario ingresar un valor junto con la unidad de origen y la unidad de
destino, y luego realizará la conversión correspondiente.

El programa deberá aceptar tres argumentos de línea de comandos:
- Valor númérico que se quiere convertir en formato coma flotante.
- Una palabra que representa la unidad de origen: puede ser “inch” ó “cm”
- Una palabra que representa la unidad de destino: puede ser “inch” ó “cm”

Se pide implementar una función que convierta los datos de entrada a las unidades pedidas:
- double convertir_longitud(ConversionInfo_t conversion);

La función recibirá una estructura que contenga información de los datos, el tipo de datos de entrada
(cm ó pulgadas) y tipo de datos de salida (cm ó pulgadas) pedidos.

Se valorará la calidad de la implementación en base a las siguientes pautas:

- Se debe guardar en una estructura tanto el tipo de unidad como el valor de origen y destino.
- Se valorará el control de errores. Si el número introducido o si las unidades especificadas no son
válidas o no se reconocen, el programa deberá mostrar un mensaje de error apropiado y terminar la
ejecución.
- Se valorará el uso de funciones para pasar valores “cadena” a valores “enumerado” para realizar las
operaciones pedidas.

IMPORTANTE: Una pulgada equivale a 2.54 centímetros.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
- Se valorará el uso correcto de enumerados para esta implementación.

-Se valorará el control de errores. Si el número introducido o si las unidades especificadas no son
válidas o no se reconocen, el programa deberá mostrar un mensaje de error apropiado y terminar la
ejecución.

-Se valorará el uso de funciones para pasar valores “cadena” a valores “enumerado” para realizar las
operaciones pedidas.

*/

typedef enum {
	UNIT_INCH,
	UNIT_CM,
	UNIT_INVALID	
}ValoresUsuario_e;

typedef struct {
	
	float cantidadUsuario;
	char palabraOrigen [10];
 	char palabraDestino [10];

} ConversionInfo_t;

double convertir_longitud(ConversionInfo_t conversion);
ValoresUsuario_e validarString(char *cadena);

int main(int argc, char *argv []){
	
	ConversionInfo_t datosUsuario;
	ValoresUsuario_e valorUsuario;
	
	if(argc != 4){
		printf("Error, numero de parametros incorrecto \n");
		return 1;
	}
	
	ValoresUsuario_e string2 = validarString(argv[2]);
	ValoresUsuario_e string3 = validarString(argv[3]);
	
	if((string2 == UNIT_INVALID) || (string3 == UNIT_INVALID)){
		printf("Error, unidades invalidas");
		return 1;
	}
	
	datosUsuario.cantidadUsuario = atof(argv[1]);
	strcpy(datosUsuario.palabraOrigen, argv[2]);
	strcpy(datosUsuario.palabraDestino, argv[3]);
	
	double resultadoConversion = convertir_longitud(datosUsuario);

	printf("Los datos introducidos por el usuario son: %.2f %s %s y el resultado final es: %.2f %s", datosUsuario.cantidadUsuario, datosUsuario.palabraOrigen, datosUsuario.palabraDestino, resultadoConversion, datosUsuario.palabraDestino);
	
	return 0;
}

double convertir_longitud(ConversionInfo_t conversion){
	
	float pulgada = 2.54;
	double resultado;
		
	if(strcmp(conversion.palabraOrigen, "inch") == 0){
		resultado = conversion.cantidadUsuario * pulgada;
	}else{
		resultado = conversion.cantidadUsuario / pulgada;
	}
	
	return resultado;
}

ValoresUsuario_e validarString(char *cadena){
	
	if(strcmp(cadena, "inch") == 0) return UNIT_INCH;
	if(strcmp(cadena, "cm") == 0) return UNIT_CM;
	
	return UNIT_INVALID;
	
}