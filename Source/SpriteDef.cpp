#include "SpriteDef.h"
#include "Config.h"

SpriteDef::SpriteDef()
{
	modulos[0].id=MODULO_MINAVE_NAVE;
	modulos[0].x=0;
	modulos[0].y=0;
	modulos[0].w=64;
	modulos[0].h=64;
	

	modulos[1].id=MODULO_MENU_FONDO;
	modulos[1].x=0;
	modulos[1].y=0;
	modulos[1].w=WIDTH_SCREEN;
	modulos[1].h=HEIGHT_SCREEN;

	modulos[2].id=MODULO_ENEMIGO_NAVE;
	modulos[2].x=0;
	modulos[2].y=0;
	modulos[2].w=54;
	modulos[2].h=61;

	modulos[3].id=MODULO_TEXTO_TITULO;
	modulos[3].x=105;
	modulos[3].y=2;
	modulos[3].w=226;
	modulos[3].h=80;

	modulos[4].id=MODULO_TEXTO_NOMBRE;
	modulos[4].x=9;
	modulos[4].y=141;
	modulos[4].w=191;
	modulos[4].h=31;

	modulos[5].id=MODULO_TEXTO_MENU_OPCION1;
	modulos[5].x=217;
	modulos[5].y=146;
	modulos[5].w=96;
	modulos[5].h=31;

	modulos[6].id=MODULO_TEXTO_MENU_OPCION2;
	modulos[6].x=214;
	modulos[6].y=211;
	modulos[6].w=78;
	modulos[6].h=37;

	modulos[7].id=MODULO_TEXTO_MENU_OPCION1_SELECCIONADO;
	modulos[7].x=324;
	modulos[7].y=156;
	modulos[7].w=117;
	modulos[7].h=38;

	modulos[8].id=MODULO_TEXTO_MENU_OPCION2_SELECCIONADO;
	modulos[8].x=322;
	modulos[8].y=224;
	modulos[8].w=93;
	modulos[8].h=39;

	
}