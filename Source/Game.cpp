#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>


CGame::CGame(){
	tiempoFrameInicial=0;
	estado=Estado::Estado_Iniciando;
    atexit(SDL_Quit);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	delete nave;
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

	nave = new Nave(screen, "../Data/minave.bmp",(WIDTH_SCREEN/2),(HEIGHT_SCREEN-80),MODULO_MINAVE_NAVE);
	menu=new Nave(screen, "../Data/Menu.bmp",0,0,MODULO_MENU_FONDO);
	textos = new Nave(screen, "../Data/Texto.bmp",0,0,-1);
	//enemigo = new Nave(screen,"../Data/enemigo.bmp",0,0);


	for(int i=0;i<10;i++)
	{
		enemigoArreglo[i] = new Nave(screen,"../Data/enemigo.bmp",i*60,0,MODULO_ENEMIGO_NAVE);
		enemigoArreglo[i]->SetAutoMovimiento(false);
		enemigoArreglo[i]->SetPasoLimite(4);

	}
	tick=0;
	opcionSeleccionada=MODULO_TEXTO_MENU_OPCION1;
	

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
			
			Iniciando();
			
			
			estado=Estado::Estado_Menu;
			
			break;
		case Estado::Estado_Menu:
			menu->Pintar();
			textos->Pintar(MODULO_TEXTO_TITULO,169,50);
			textos->Pintar(MODULO_TEXTO_NOMBRE,300,390);
			Menu();
			//textos->Pintar(MODULO_TEXTO_MENU_OPCION1,300,220);
			//textos->Pintar(MODULO_TEXTO_MENU_OPCION2,300,270);

			
			break;
		case  Estado::Estado_Jugando:	//JUGAR	
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
			
			
			break;
		case  Estado::Estado_Terminando: //SALIR
			

		   salirJuego = true;
		break;
		case  Estado::Estado_Finalizando:
			
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
		tiempoFrameFinal=SDL_GetTicks();
		while(tiempoFrameFinal < (tiempoFrameInicial + FPS_DELAY))
		{
			tiempoFrameFinal=SDL_GetTicks();
			SDL_Delay(1);
		}

		
		printf("Frames:%d   Tiempo:%d  Tiempo Promedio:%f  Tiempo por Frame:%d FPS:%f\n",tick,SDL_GetTicks(), (float)SDL_GetTicks()/(float)tick,tiempoFrameFinal-tiempoFrameInicial,1000.0f /(float)(tiempoFrameFinal-tiempoFrameInicial));
		tiempoFrameInicial=tiempoFrameFinal; // marcamos el inicio nuevamente
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
void CGame::Menu()
{
	for(int i= MODULO_TEXTO_MENU_OPCION1, j=0; i <= MODULO_TEXTO_MENU_OPCION2; i++, j++)
	{
		if(i == opcionSeleccionada)
			textos->Pintar(i+2,200,180+(j*180));
		else
		textos->Pintar(i,200,180+(j*80));
	}
}

  
