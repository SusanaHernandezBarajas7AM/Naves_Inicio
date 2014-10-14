#ifndef __SPRITE_H__
#define __SPRITE_H__
#include <SDL.h>
#include "SpriteDef.h"

class Sprite
{
	SDL_Surface * imagen; // imagen a manipular
	SDL_Surface * screen; //esta es la pantalla
	SpriteDef spriteDef; //definiciones de sprite

public:
	Sprite(SDL_Surface * screen); //constructor, que recibe la pantalla
	~Sprite(); // destructor se llama con delete
	void CargarImagen(char * path);
	void PintarModulo(int nombre, int x, int y, int w, int h);
	void PintarModulo(int nombre, int x, int y);
	int WidthModule(int module);
	int HeightModule(int module);
};

#endif
