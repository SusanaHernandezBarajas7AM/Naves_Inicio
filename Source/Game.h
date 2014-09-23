
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
	SDL_Surface *nave;
	
	
	  Estado estado;
};
