#include "GL/glut.h"
#include <stdio.h>
#include "../header/cube.h"

int idPied, idPlateau, idTable;
double longueurTable = 160.0, hauteurTable = 3.0, largeurTable = 80.0;
double cotePied = 5.0, hauteurPied = 72.0;
int textures_plateau[6];
int textures_pieds[6];

void creationPied()
{
    idPied = glGenLists(1);
    glNewList(idPied, GL_COMPILE_AND_EXECUTE);
    glScaled(cotePied, hauteurPied, cotePied);
    creerCube(textures_pieds);
    glEndList();
}

void creationPlateau() 
{
    idPlateau = glGenLists(1);
    glNewList(idPlateau, GL_COMPILE_AND_EXECUTE);
    glPushMatrix();
    glScaled(longueurTable, hauteurTable, largeurTable);
    creerCube(textures_plateau);
    glPopMatrix();
    glEndList();
}

void creationTable() 
{
    char *images_plateau[] = {"texture/table/contour.tga", "texture/table/contour.tga",
                            "texture/table/contour.tga", "texture/table/contour.tga",
                            "texture/table/plateau_dessus.tga", "texture/table/plateau_dessus.tga"};
    char *images_pieds[] = {"texture/table/pied.tga", "texture/table/pied.tga","texture/table/pied.tga",
                            "texture/table/pied.tga","texture/table/pied.tga","texture/table/pied.tga"};

    int i;
    for(i = 0; i < 6; i++) charger_image(&textures_pieds[i], images_pieds[i]);  
    creationPied();
    for(i = 0; i < 6; i++) charger_image(&textures_plateau[i], images_plateau[i]);
    creationPlateau();
    idTable = glGenLists(1);
    glNewList(idTable, GL_COMPILE_AND_EXECUTE);

    glPushMatrix();
    glTranslated(0, (hauteurPied)+(hauteurTable / 2.0), 0.0);
    glCallList(idPlateau);
    glPopMatrix();

    // pied fond droit
    glPushMatrix();
    glTranslated(longueurTable / 2.0 - cotePied, hauteurPied / 2., largeurTable / 2.0 - cotePied);
    glCallList(idPied);
    glPopMatrix();

    // pied  devant droit
    glPushMatrix();
    glTranslated(longueurTable / 2.0 - cotePied, hauteurPied / 2., -largeurTable / 2.0 + cotePied);
    glCallList(idPied);
    glPopMatrix();

    // pied gauche fond
    glPushMatrix();
    glTranslated(-longueurTable / 2.0 + cotePied, hauteurPied / 2., largeurTable / 2.0 - cotePied);
    glCallList(idPied);
    glPopMatrix();

    // pied gauche devant
    glPushMatrix();
    glTranslated(-longueurTable / 2.0 + cotePied, hauteurPied / 2., -largeurTable / 2.0 + cotePied);
    glCallList(idPied);
    glPopMatrix();

    glEndList();
}