#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>


CGame::CGame(){
	tiempoFrame=0;
	estado=Estado::Estado_Iniciando;
    atexit(SDL_Quit);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	delete nave;
	//delete []keys;
	//delete enemigo;
	delete *enemigoArreglo;
	SDL_FreeSurface(screen);
	SDL_Quit();
}

void CGame::Iniciando()
{
	if(SDL_Init(SDL_INIT_VIDEO)) 
	{
		printf("Error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	screen= SDL_SetVideoMode(WIDTH_SCREEN,HEIGHT_SCREEN,24,SDL_HWSURFACE);
	if(screen==NULL)
	{
		printf("Error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption("Mi primer juego", NULL);
	atexit(SDL_Quit);

	nave = new Nave(screen, "../Data/minave.bmp",(WIDTH_SCREEN/2)/*-(sprite->WidthModule(0)/2)*/,(HEIGHT_SCREEN-80)/*-(sprite->HeightModule(0))*/);
	//enemigo = new Nave(screen,"../Data/enemigo.bmp",0,0);


	for(int i=0;i<10;i++)
	{
		enemigoArreglo[i] = new Nave(screen,"../Data/enemigo.bmp",i*60,0);
		enemigoArreglo[i]->SetAutoMovimiento(false);
		enemigoArreglo[i]->SetPasoLimite(4);

	}
	tick=0;
	//enemigo->SetAutoMovimiento(false);
	//enemigo->SetPasoLimite(4);

	 //delete nave;

}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
	//int i=0;
          
	while (salirJuego == false){
		
            
		//Maquina de estados
		switch(estado){
		case  Estado::Estado_Iniciando: //INICIALIZAR
			//printf("1.- ESTADO_INICIANDO");
			Iniciando();
			
			//{
			//	/*nave=SDL_LoadBMP("../Data/MiNave.bmp");
			//	nave=IMG_LoadJPG_RW(SDL_SDL_RWFromFile("../Data/umi.jpg","rb"));
			//	nave=IMG_LoadJPG_RW(SDL_RWFromFile("../Data/tools.jpg","rb"));
			//	nave=IMG_LoadPNG_RW(SDL_RWFromFile("../Data/dados.png","rb"));*/
			//	nave=IMG_LoadJPG_RW(SDL_RWFromFile("../Data/cuadro.jpg","rb"));
			//	SDL_Rect fuente;
			//	fuente.x=90;
			//	fuente.y=152;
			//	fuente.w=242;
			//	fuente.h=75;
			//	SDL_Rect destino;
			//	destino.x=100;
			//	destino.y=100;
			//	destino.w=100;
			//	destino.h=fuente.h;
			//	SDL_BlitSurface(nave, &fuente, screen, &destino);
			//	

			//}
			//estado=Estado_Menu;
			estado=Estado::Estado_Menu;
			
			break;
		case Estado::Estado_Menu:
			//estado=Estado_Jugando;
			for(int i=0;i<10;i++)
			{
				enemigoArreglo[i]->Actualizar();
			}
			//enemigo->Actualizar();
			MoverEnemigo();
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,0,0,0));
			Keys = SDL_GetKeyState(NULL);
			if (Keys[SDLK_RIGHT])
			{
				if(!EsLimitePantalla(nave, BORDE_DERECHO))
				nave->Mover(1);
			}
			if (Keys[SDLK_LEFT])
			{
				if(!EsLimitePantalla(nave, BORDE_IZQUIERDO))
				nave->Mover(-1);
			}
			
			nave->Pintar();
			//enemigo->Pintar();
			for(int i=0;i<10;i++)
			{
				enemigoArreglo[i]->Pintar();
			}
			
			/*if(i == 0)
			{
				printf("\n2.- ESTADO_MENU");
				estado = Estado_Jugando;
				i = 1;
			}
			else
			{
				printf("\n2.- ESTADO_MENU");
				estado = Estado_Finalizando;
			}*/
			
			//nave ->PintarModulo(0, 0,0,64, 64); 
			//nave->PintarModulo(0,100,100);
			//enemigo->Actualizar();
			//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,0,0,0));

			//Keys = SDL_GetKeyState(NULL);
			//if(Keys[SDLK_RIGHT])
			//{
			//	if(!EsLimitePantalla(nave))
			//	nave->Mover(1);	
			//}
			//if(Keys[SDLK_LEFT])
			//{
			//	nave->Mover(-1);	
			//}
			//
			//nave->Pintar(); // los 3 casos siguientes son el primero aplicando a las demas direcciones
			//enemigo->Pintar();
			break;
		case  Estado::Estado_Jugando:	//JUGAR	
			//enemigo->Actualizar();
			
		/*	MoverEnemigo();
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,0,0,0));
			Keys = SDL_GetKeyState(NULL);
			if (Keys[SDLK_RIGHT])
			{
				if(!EsLimitePantalla(nave, BORDE_DERECHO))
				nave->Mover(1);
			}
			if (Keys[SDLK_LEFT])
			{
				if(!EsLimitePantalla(nave,BORDE_IZQUIERDO))
				nave->Mover(-1);
			}
			nave->Pintar();
			enemigo->Pintar();*/

			/*if (Keys[SDLK_ESCAPE])
			{
				printf("\n3.- ESTADO_JUGANDO");
				estado = Estado_Terminando;
			}*/
			break;
		case  Estado::Estado_Terminando: //SALIR
			/*printf("\n4.- ESTADO_TERMINANDO");
			estado=Estado_Menu;*/

		   salirJuego = true;
		break;
		case  Estado::Estado_Finalizando:
			/*printf("\n5.- ESTADO_FINALIZANDO");
			getchar();
			salirJuego = true;*/
			break;
			
			
		};
		while (SDL_PollEvent(&event)) // aqui SDL creara una lista de eventos ocurridos
			{
				if (event.type == SDL_QUIT) { salirJuego = true;} // si se detecta una salida de SDL o....
				if (event.type==SDL_KEYDOWN) { }
			}

		// este codigo estara provicionalmente aqui
		SDL_Flip(screen);
		//calculando FPS
		int tiempoFrameFinal=SDL_GetTicks();
		
		printf("%d   %d  %f  %d\n",tick,SDL_GetTicks(), (float)SDL_GetTicks()/(float)tick,tiempoFrameFinal-tiempoFrame);
		tiempoFrame=tiempoFrameFinal; // marcamos el inicio nuevamente
		tick++;








    }
	return true;
}

bool CGame::EsLimitePantalla(Nave * objeto,int bandera)

{
	if(bandera & BORDE_IZQUIERDO)
	if(objeto->ObtenerX() <=0)
		return true;
	if(bandera & BORDE_SUPERIOR )
	if(objeto->ObtenerY() <=0)
		return true;
	if(bandera & BORDE_DERECHO )
	if(objeto->ObtenerX() >= WIDTH_SCREEN-objeto->ObtenerW())

		return true;
	if(bandera & BORDE_INFERIOR )
	if(objeto->ObtenerY() >= HEIGHT_SCREEN-objeto->ObtenerH())
		return true;
	return false;
	
}

void CGame::MoverEnemigo()
{
	//if(enemigo->ObtenerPasoActual()==0)
	//if(!EsLimitePantalla(enemigo,BORDE_DERECHO))
	//enemigo->Mover(1); //DERECHA
	//else
	//{
	//	enemigo->IncrementarPasoActual();
	//	enemigo->IncrementarPasoActual();
	//}
	////if(enemigo->ObtenerPasoActual()==1)
	//	//if(!EsLimitePantalla(enemigo, BORDE_INFERIOR))
	//		//enemigo->Mover(1); ABAJO
	//if(enemigo->ObtenerPasoActual()==2)
	//	if(!EsLimitePantalla(enemigo, BORDE_IZQUIERDO))
	//		enemigo->Mover(-1); //IZQUIERDA
	//else
	//{
	//	enemigo->IncrementarPasoActual();
	//	enemigo->IncrementarPasoActual();
	//}
	//
	////if(enemigo->ObtenerPasoActual()==3)
	//	//if(!EsLimitePantalla(enemigo, BORDE_INFERIOR))
	//		//enemigo->Mover(1); //ABAJO


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		for(int i=0;i<10;i++)
		{
		
        /////// PASO 0 ////////
		if(enemigoArreglo[i]->ObtenerPasoActual()==0)
	if(!EsLimitePantalla(enemigoArreglo[i],BORDE_DERECHO))
	enemigoArreglo[i]->Mover(1); //DERECHA
	else
	{
		enemigoArreglo[i]->IncrementarPasoActual();
		enemigoArreglo[i]->IncrementarPasoActual();
	}
	 ////////////////////PASO 1//////////////////
	//if(enemigoArreglo[i]->ObtenerPasoActual()==1)
		//if(!EsLimitePantalla(enemigo, BORDE_INFERIOR))
			//enemigoArreglo[i]->Mover(1); ABAJO

	    //////////////PASO 2/////////////////////
	if(enemigoArreglo[i]->ObtenerPasoActual()==2)
		if(!EsLimitePantalla(enemigoArreglo[i], BORDE_IZQUIERDO))
			enemigoArreglo[i]->Mover(-1); //IZQUIERDA
	else
	{
		enemigoArreglo[i]->IncrementarPasoActual();
		enemigoArreglo[i]->IncrementarPasoActual();
	}

		//////////////// PASO 3  ///////////////////
	
	//if(enemigoArreglo[i]->ObtenerPasoActual()==3)
		//if(!EsLimitePantalla(enemigo, BORDE_INFERIOR))
			//enemigoArreglo[i]->Mover(1); //ABAJO

		}

				
}

  
