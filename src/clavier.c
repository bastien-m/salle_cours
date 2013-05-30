#include "GL/glut.h"
#include <stdio.h>
#include "../header/cube.h"

int id_clavier;
double clavier_x = 40.0, clavier_y = 0.5, clavier_z = 15.0;

void creation_clavier()
{
	int textures[6];
	char *images[] = {"texture/clavier/clavier_devant.tga","texture/clavier/clavier_derriere.tga",
						"texture/clavier/clavier_cote_gauche.tga","texture/clavier/clavier_cote_droit.tga",
						"texture/clavier/clavier_dessus.tga","texture/clavier/clavier_devant.tga"};

	int i;
	for(i = 0; i < 6; i++) charger_image(&textures[i], images[i]);	
	id_clavier = glGenLists(1);
	glNewList(id_clavier, GL_COMPILE_AND_EXECUTE);
	glPushMatrix();
	glTranslated(0.0, clavier_y / 2.0, 0.0);
	glScaled(clavier_x, clavier_y, clavier_z);
	creerCube(textures);
	glPopMatrix();
	glEndList();
}
