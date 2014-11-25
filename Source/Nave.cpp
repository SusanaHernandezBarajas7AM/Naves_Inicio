#include "Nave.h"
//#include "Config.h"
Objeto::Objeto(SDL_Surface *screen, char * rutaImagen, int x, int y, int module)
{
	this->module=module;
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	w = sprite->WidthModule(this->module);
	h = sprite->HeightModule(this->module);
	//x=(WIDTH_SCREEN/2)-(sprite->WidthModule(0)/2); //ancho
	//y=(HEIGHT_SCREEN-80)-(sprite->HeightModule(0)); //alto
	this->x =x;
	this->y =y;
	autoMovimiento = false;
	pasoActual=0;
	pasoLimite=-1;

}

void Objeto::SetAutoMovimiento(bool autoMovimiento)
{
	this->autoMovimiento = autoMovimiento;
}
void Objeto::Actualizar()
{
	if (autoMovimiento)
	{
		Mover(1);
	}
	if(pasoLimite>0)
	{
		//pasoActual++;
		if(pasoActual>=pasoLimite)

			pasoActual=0;
	}
	
}
void Objeto::Pintar()
{
	sprite->PintarModulo(module,x,y);

}
void Objeto::Pintar(int module, int x, int y)
{
	sprite->PintarModulo(module,x,y);

}

void Objeto::Mover(int posicion)
{
	x += posicion;
}


int Objeto::ObtenerX()
{
	return x;
}

int Objeto::ObtenerY()
{
	return y;
}
int Objeto::ObtenerW()
{
	return w;
}
int Objeto::ObtenerH()
{
	return h;
}

void Objeto::SetPasoLimite(int pasos)
{
	this->pasoLimite = pasos;
}
int Objeto::ObtenerPasoActual()
{
	return pasoActual;
}

void Objeto::IncrementarPasoActual()
{
	pasoActual++;
}
bool Objeto::EstaColicionando(Objeto * b)
{
	return false;
}