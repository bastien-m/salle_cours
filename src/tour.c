#include "GL/glut.h"
#include <stdio.h>
#include "../header/cube.h"

int id_tour;
double tour_x = 20.0, tour_y = 50.0, tour_z = 60.0;

void creation_tour()
{
	int textures[6];
	char * images[] = {"texture/tour/tour_face.tga", "texture/tour/tour_arriere.tga",
						"texture/tour/tour.tga","texture/tour/tour.tga",
						"texture/tour/tour.tga","texture/tour/tour.tga"};

	int i;
	for(i = 0; i < 6; i++) charger_image(&textures[i], images[i]);

	id_tour = glGenLists(1);
	glNewList(id_tour, GL_COMPILE_AND_EXECUTE);
	
	glPushMatrix();
	glTranslated(0, tour_y / 2.0, 0);
	glScaled(tour_x, tour_y, tour_z);
	creerCube(textures);
	glPopMatrix();
	
	glEndList();
}