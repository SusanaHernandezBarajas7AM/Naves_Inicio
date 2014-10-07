#include <SDL_image.h>
#include "Sprite.h"

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
	SDL_Surface *screen;
	Sprite * nave;
	
	
	  Estado estado;
};
