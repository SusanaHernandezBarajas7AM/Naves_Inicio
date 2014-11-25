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
	void Menu();
	void MoverEnemigo();

	bool EsLimitePantalla(Objeto * objeto,int bandera);

	int opcionSeleccionada;
	Uint8 *Keys; //esta variable nos servira para ver si determinadas teclas estan o no pulsadas
	SDL_Event event; // la variable vent de tipo evento de SDL nos servira para monitorizar el teclado.



	SDL_Surface *screen;
     Objeto * nave;
	 //Nave * enemigo;
	 Objeto *enemigoArreglo [10];

	 Objeto *menu; //Fondo del menu
	 Objeto *textos; //Textos del juego
	 Objeto *fondo; // Fondo del juego

	 int tick;
	 int tiempoFrameInicial;
	 int tiempoFrameFinal;
	
	
	
	  Estado estado;
};
