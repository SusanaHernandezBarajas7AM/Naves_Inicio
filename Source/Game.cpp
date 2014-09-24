#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "SDL.h"
#include "SDL_image.h"

CGame::CGame(){
	estado=Estado::Estado_Iniciando;

	atexit(SDL_Quit);
	if(SDL_Init(SDL_INIT_VIDEO))
	{
		printf("Error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	screen= SDL_SetVideoMode(640,480,24,SDL_SWSURFACE);
	if(screen==NULL)
	{
		printf("Error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption("Mi Primer Juego", NULL);
	
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
	
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case  Estado::Estado_Iniciando: //INICIALIZAR
			Iniciando();
			{
				//nave=SDL_LoadBMP("../Data/MiNave.bmp");
				//nave=IMG_LoadJPG_RW(SDL_SDL_RWFromFile("../Data/umi.jpg","rb"));
				//nave=IMG_LoadJPG_RW(SDL_RWFromFile("../Data/tools.jpg","rb"));
				//nave=IMG_LoadPNG_RW(SDL_RWFromFile("../Data/dados.png","rb"));
				nave=IMG_LoadJPG_RW(SDL_RWFromFile("../Data/cuadro.jpg","rb"));
				SDL_Rect fuente;
				fuente.x=90;
				fuente.y=152;
				fuente.w=242;
				fuente.h=75;
				SDL_Rect destino;
				destino.x=100;
				destino.y=100;
				destino.w=100;
				destino.h=fuente.h;
				SDL_BlitSurface(nave, &fuente, screen, &destino);
			}
			estado=Estado::Estado_Menu;
			
			break;
		case Estado::Estado_Menu:
			break;
		case  Estado::Estado_Jugando:	//JUGAR	
			break;
		case  Estado::Estado_Terminando: //SALIR
		    salirJuego = true;
		break;
		case  Estado::Estado_Finalizando:
			break;
			
		};
		SDL_Flip(screen);
    }
	return true;
}
