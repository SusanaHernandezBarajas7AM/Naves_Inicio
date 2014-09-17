#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

CGame::CGame(){
	estado = 0;
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
		case Estado::Estado_Iniciando: //INICIALIZAR
			break;
		case Estado::Estado_Jugando:	//JUGAR	
			break;
			case Estado::Estado_Terminando: //SALIR
			case Estado::Estado_Finalizando:
				break;
				salirJuego = true;
			break;
		};
    }
	return true;
}
