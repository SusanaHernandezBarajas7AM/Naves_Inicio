#include <SDL_image.h>
#include "Nave.h"



class CGame
{
public:
	enum Estado
	{
		Estado_Iniciando,
		Estado_Menu,
		Estado_Jugando,
		Estado_Terminando,
		Estado_Finalizando
	};
	bool Start();
	static CGame instanceGame;
	

	CGame();
	
	void Finalize();

private:
	void Iniciando();
	void MoverEnemigo();

	bool EsLimitePantalla(Nave * objeto,int bandera);

	Uint8 *Keys; //esta variable nos servira para ver si determinadas teclas estan o no pulsadas
	SDL_Event event; // la variable vent de tipo evento de SDL nos servira para monitorizar el teclado.



	SDL_Surface *screen;
     Nave * nave;
	 //Nave * enemigo;
	 Nave *enemigoArreglo [10];

	 Nave *menu; //Fondo del menu
	 Nave *textos; //Textos del juego
	 Nave *fondo; // Fondo del juego

	 int tick;
	 int tiempoFrameInicial;
	 int tiempoFrameFinal;
	
	
	  Estado estado;
};
