#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

CGame::CGame(){
	///ACT2: Mal, Debe ser la variable lo que pongas y no el nombre de tu enumerador. tu variable se llama estado, y debes de asignarle
	//un valor de los que tiene nu enumerador, eso seria tu primer estado.
	estado=Estado::Estado_Iniciando;
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case  Estado::Estado_Iniciando: //INICIALIZAR
			break;
		case  Estado::Estado_Jugando:	//JUGAR	
			break;
		case  Estado::Estado_Terminando: //SALIR
		    salirJuego = true;
		break;
		case  Estado::Estado_Finalizando:
			break;
		};
    }
	return true;
}
