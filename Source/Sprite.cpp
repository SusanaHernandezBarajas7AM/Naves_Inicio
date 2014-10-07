#include "Sprite.h"
#include <SDL.h>

#include "Sprite.h"

Sprite::Sprite(SDL_Surface * screen)
{
	screen;
	this ->screen = screen; // es la clase en la que estamos actualmente
}
Sprite::~Sprite()
{
	SDL_FreeSurface(imagen); 
}


void Sprite::CargarImagen(char * nombre)
{
	imagen = SDL_LoadBMP(nombre);
}

void Sprite::PintarModulo(int nombre, int x, int y, int w, int h)
{
	SDL_Rect src;
	src.x=x;
	src.y=y;
	src.w=w;
	src.h=h;
	SDL_BlitSurface(imagen, &src, screen, NULL );
};

void Sprite::PintarModulo(int nombre, int x, int y)
{
	SDL_Rect src;
	src.x=x;
	src.y=y;
	src.w=w;
	src.h=h;
	SDL_BlitSurface(imagen, &src, screen, NULL );
};