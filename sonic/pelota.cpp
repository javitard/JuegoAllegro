#include <stdlib.h>
#include "pelota.h"

Pelota::Pelota ()
{
    static int i = 0;		// Pdte. variables de clase
    this->x = 0 + 5 * i++;
    this->y = 10;
    this->vx = rand () % 3 - 1;
    this->vy = rand () % 3 - 1;
    this->dibujo = '*';
}

Pelota::Pelota (double x, double y)
{
    this->x = x;
    this->y = y;
    this->vx = rand () % 3 - 1;
    this->vy = rand () % 3 - 1;
    this->dibujo = '*';
}

/* Accedentes */
    double
Pelota::get_x ()
{

    return this->x;
}

    double
Pelota::get_y ()
{
    return this->y;
}

    char
Pelota::get_dibujo ()
{
    return this->dibujo;
}

/* Mutadora */
    void
Pelota::actualizate ()
{
    this->x += this->vx;
		if(this->x < 0 || this->x  > 1024)
		this->x = 0;
           
	this->y += this->vy;
    if(this->y < 500)
	this->y = 500;
}

    void
Pelota::change_vx (float delta)
{
    this->vx += delta;
}

    void
Pelota::change_vy (float delta)
{
    this->vy += delta;
}
