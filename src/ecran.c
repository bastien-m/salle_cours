#include "GL/glut.h"
#include <stdio.h>
#include "../header/cube.h"

int texture_socle[6];
int texture_dalle[6];
int texture_tube[6];
int id_socle, id_arriere, id_dalle, id_ecran;
double dalle_x = 50.0, dalle_y = 30.0, dalle_z = 2.0;
double socle_x = 26.0, socle_y = 1.0, socle_z = 15.0;
double tube_x = 7.0, tube_y = 22.0, tube_z = 2.0;


void creation_socle()
{
	id_socle = glGenLists(1);
	glNewList(id_socle, GL_COMPILE_AND_EXECUTE);
	glScaled(socle_x, socle_y, socle_z);
	creerCube(texture_socle);
	glEndList();
}

void creation_dalle()
{
	id_dalle = glGenLists(1);
	glNewList(id_dalle, GL_COMPILE_AND_EXECUTE);
	glScaled(dalle_x, dalle_y, dalle_z);
	creerCube(texture_dalle);
	glEndList();
}

void creation_arriere()
{
	id_arriere = glGenLists(1);
	glNewList(id_arriere, GL_COMPILE_AND_EXECUTE);
	glScaled(tube_x, tube_y, tube_z);
	creerCube(texture_tube);
	glEndList();
}

void creation_ecran()
{
	

	char *image_socle[] = {"texture/ecran/pied.tga","texture/ecran/pied.tga","texture/ecran/pied.tga","texture/ecran/pied.tga","texture/ecran/pied.tga","texture/ecran/pied.tga"};
	char *image_dalle[] = {"texture/ecran/dalle.tga", "texture/ecran/ecran_arriere.tga", "texture/ecran/ecran_cote.tga", "texture/ecran/ecran_cote.tga",
							"texture/ecran/ecran_dessus.tga", "texture/ecran/ecran_dessus.tga"};
	char *image_tube[] = {"texture/ecran/pied.tga", "texture/ecran/tube_arriere.tga", "texture/ecran/pied.tga", "texture/ecran/pied.tga", 
							"texture/ecran/pied.tga", "texture/ecran/pied.tga"};

	int i;
	for(i = 0; i < 6; i++) charger_image(&texture_socle[i], image_socle[i]);
	creation_socle();
	for(i = 0; i < 6; i++) charger_image(&texture_tube[i], image_tube[i]);
	creation_arriere();
	for(i = 0; i < 6; i++) charger_image(&texture_dalle[i], image_dalle[i]);
	creation_dalle();

	id_ecran = glGenLists(1);
	glNewList(id_ecran, GL_COMPILE_AND_EXECUTE);

	// ======creation socle=======
	glPushMatrix();
	glTranslated(0, socle_y / 2.0 ,0);
	glCallList(id_socle);
	glPopMatrix();
	// ======creation dalle=======
	glPushMatrix();
	glTranslated(0, socle_y / 2.0 + dalle_y / 2.0 + tube_y / 2.0, 0);
	glCallList(id_dalle);
	glPopMatrix();

	// ======creation arriere=====
	glPushMatrix();
	glTranslated(0, socle_y / 2.0 + tube_y / 2.0, -tube_z);
	glCallList(id_arriere);
	glPopMatrix();

	glEndList();

}