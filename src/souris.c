#include "GL/glut.h"
#include <stdio.h>
#include "../header/cube.h"

int id_souris;
double souris_x = 5.0, souris_y = 1.5, souris_z = 8.0;

void creation_souris()
{
	id_souris = glGenLists(1);
	int textures[6];
	char *images[] = {"texture/souris/souris_dessous.tga", "texture/souris/souris_dessous.tga",
					"texture/souris/cote_gauche.tga", "texture/souris/cote_droit.tga",
					"texture/souris/souris_dessus.tga", "texture/souris/souris_dessous.tga"};
	int i;

	for(i = 0; i < 6; i++) charger_image(&textures[i], images[i]);
	glNewList(id_souris, GL_COMPILE_AND_EXECUTE);
	glPushMatrix();
	glTranslated(0, souris_y / 2.0, 0);
	glScaled(souris_x, souris_y, souris_z);
	creerCube(textures);
	glPopMatrix();
	glEndList();
}