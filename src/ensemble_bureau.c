#include "GL/glut.h"
#include <stdio.h>
#include <stdlib.h>
#include "../header/table.h"
#include "../header/chaise.h"
#include "../header/ecran.h"
#include "../header/clavier.h"
#include "../header/souris.h"
#include "../header/tour.h"

int id_ensemble_bureau;
double couloir;
double bloc_x, bloc_z;

void init_var()
{
	couloir = 80.0;
	bloc_x = longueurTable, bloc_z = largeurTable + couloir;
}

void creation_ensemble_bureau()
{
	init_var();

	creationTable();
    creation_chaise();
    creation_ecran();
    creation_clavier();
    creation_souris();
    creation_tour();

    id_ensemble_bureau = glGenLists(1);
    glNewList(id_ensemble_bureau, GL_COMPILE_AND_EXECUTE);

    glCallList(idTable);

    glPushMatrix();
    glTranslated(largeur_assise, 0.0, largeurTable / 2.0);
    glCallList(id_chaise);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-largeur_assise, 0.0, largeurTable / 2.0);
    glCallList(id_chaise);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, hauteurTable + hauteurPied, 0);
    glCallList(id_ecran);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, hauteurTable + hauteurPied, 20.0);
    glCallList(id_clavier);
    glPopMatrix();

    glPushMatrix();
    glTranslated(clavier_x / 2.0 + 10.0, hauteurTable + hauteurPied, 20.0);
    glCallList(id_souris);
    glPopMatrix();

    glPushMatrix();
    glTranslated(longueurTable / 2.0 - tour_x / 2.0, hauteurTable + hauteurPied, 0);
    glCallList(id_tour);
    glPopMatrix();

    glEndList();
}