#include "GL/glut.h"
#include <stdio.h>
#include "../header/cube.h"

double fenetre_x = 500.0, fenetre_y = 200.0, fenetre_z = 2.0;
int id_fenetre;

void creation_fenetre()
{
	int textures[6];
	char *images[] = {"texture/fenetre/vue_fenetre.tga", "texture/fenetre/vue_fenetre.tga",
					"texture/fenetre/bord.tga", "texture/fenetre/bord.tga",
					"texture/fenetre/bord.tga", "texture/fenetre/bord.tga"};
	int i;
	for(i = 0; i < 6; i++) charger_image(&textures[i], images[i]);

	id_fenetre = glGenLists(1);
	glNewList(id_fenetre, GL_COMPILE_AND_EXECUTE);
		glPushMatrix();
			glTranslated(0.0, fenetre_y / 2.0 + 75.0, 0.0);
			glScaled(fenetre_x, fenetre_y, fenetre_z);
			creerCube(textures);
		glPopMatrix();
	glEndList();
}
