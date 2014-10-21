#include "Nave.h"
//#include "Config.h"
Nave::Nave(SDL_Surface *screen, char * rutaImagen, int x, int y)
{
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	//x=(WIDTH_SCREEN/2)-(sprite->WidthModule(0)/2); //ancho
	//y=(HEIGHT_SCREEN-80)-(sprite->HeightModule(0)); //alto
	this->x =x;
	this->y =y;
	autoMovimiento = false;

}

void Nave::SetAutoMovimiento(bool autoMovimiento)
{
	this->autoMovimiento = autoMovimiento;
}
void Nave::Actualizar()
{
	if (autoMovimiento)
	{
		Mover(1);
	}
	
}
void Nave::Pintar()
{
	sprite->PintarModulo(0,x,y);

}

void Nave::Mover(int posicion)
{
	x += posicion;
}