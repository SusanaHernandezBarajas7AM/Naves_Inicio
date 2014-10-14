#include "Nave.h"
#include "Config.h"
Nave::Nave(SDL_Surface *screen, char * rutaImagen)
{
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	x=(WIDTH_SCREEN/2)-(sprite->WidthModule(0)/2); //ancho
	y=(HEIGHT_SCREEN-80)-(sprite->HeightModule(0)); //alto

}
void Nave::Pintar()
{
	sprite->PintarModulo(0,x,y);

}

void Nave::Mover(int posicion)
{
	x += posicion;
}