#include "GL/glut.h"
#include <stdio.h>
#include "../header/cube.h"

int id_chaise, id_pied, id_assise, id_dossier;
double hauteur_pied = 45.0, cote_pied = 5.0;
double hauteur_assise = 5.0, profondeur_assise = 40.0, largeur_assise = 40.0;
double hauteur_dossier = 40.0, profondeur_dossier = 5.0, largeur_dossier = 40.0;
double decalage_pied = 2.0;
int textures[6];
char * images[] = {"texture/chaise/chaise.tga","texture/chaise/chaise.tga",
					"texture/chaise/chaise.tga","texture/chaise/chaise.tga",
					"texture/chaise/chaise.tga","texture/chaise/chaise.tga"};
void creation_pied()
{
	id_pied = glGenLists(1);
	glNewList(id_pied, GL_COMPILE_AND_EXECUTE);
	glScaled(cote_pied, hauteur_pied, cote_pied);
	creerCube(textures);
	glEndList();
}

void creation_assise()
{
	id_assise = glGenLists(1);
	glNewList(id_assise, GL_COMPILE_AND_EXECUTE);
	glScaled(largeur_assise, hauteur_assise, profondeur_assise);
	creerCube(textures);
	glEndList();
}

void creation_dossier()
{
	id_dossier = glGenLists(1);
	glNewList(id_dossier, GL_COMPILE_AND_EXECUTE);
	glScaled(largeur_dossier, hauteur_dossier, profondeur_dossier);
	creerCube(textures);
	glEndList();
}


void creation_chaise()
{
	int i;

	for(i = 0; i < 6; i++) charger_image(&textures[i], images[i]);

	creation_pied();
	creation_assise();
	creation_dossier();

	id_chaise = glGenLists(1);
	glNewList(id_chaise, GL_COMPILE_AND_EXECUTE);

	// ========creation des quatres pieds=====
	// pied avant gauche
	glPushMatrix();
	glTranslated(-largeur_assise / 2.0 + cote_pied / 2.0 , hauteur_pied / 2.0, -profondeur_assise / 2.0 + cote_pied / 2.0);
	glCallList(id_pied);
	glPopMatrix();

	// pied avant droit
	glPushMatrix();
	glTranslated(largeur_assise / 2.0 - cote_pied / 2.0 , hauteur_pied / 2.0, -profondeur_assise / 2.0 + cote_pied / 2.0);
	glCallList(id_pied);
	glPopMatrix();

	// pied arriere gauche
	glPushMatrix();
	glTranslated(-largeur_assise / 2.0 + cote_pied / 2.0  , hauteur_pied / 2.0, profondeur_assise / 2.0 - cote_pied / 2.0 );
	glCallList(id_pied);
	glPopMatrix();

	// pied arriere droit
	glPushMatrix();
	glTranslated(largeur_assise / 2.0 - cote_pied / 2.0 , hauteur_pied / 2.0, profondeur_assise / 2.0 - cote_pied / 2.0);
	glCallList(id_pied);
	glPopMatrix();

	// ======creation de l assise=======
	glPushMatrix();
	glTranslated(0.0, hauteur_assise / 2.0 + hauteur_pied, 0.0);
	glCallList(id_assise);
	glPopMatrix();

	// =======creation du dossier========
	glPushMatrix();
	glTranslated(0.0, hauteur_pied + hauteur_dossier / 2.0 + hauteur_assise / 2.0, profondeur_assise / 2.0 - profondeur_dossier / 2.0);
	glCallList(id_dossier);
	glPopMatrix();

	glEndList();
}



