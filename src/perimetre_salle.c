#include "GL/glut.h"
#include <stdio.h>
#include "../header/cube.h"

int id_perimetre_salle;
double salle_x = 770.0, salle_y = 300.0, salle_z = 1040.0;

void creation_cube(int *);

void creation_perimetre_salle()
{
	int textures[6];
	char *images[] = {"texture/salle/revetement_mural.tga", "texture/salle/revetement_mural.tga", 
					"texture/salle/revetement_mural.tga", "texture/salle/revetement_mural.tga",
					"texture/salle/plafond.tga", "texture/salle/parquet.tga"};
	int i;
	for(i = 0; i < 6; i++) charger_image(&textures[i], images[i]);

	id_perimetre_salle = glGenLists(1);
	glNewList(id_perimetre_salle, GL_COMPILE_AND_EXECUTE);
		glPushMatrix();
			glTranslated(0, salle_y / 2.0, 0);
			glScaled(salle_x, salle_y, salle_z);
			creation_cube(textures);
		glPopMatrix();
	glEndList();

	

}

void creation_cube(int *textures)
{
	double decalage = 0.5;
    // FACE AVANT
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glBegin(GL_QUADS);
        glNormal3f( 0, 0,1);
        glTexCoord2f(0, 0);
        glVertex3f( -decalage, -decalage, decalage);
        glTexCoord2f(7, 0);
        glVertex3f(  decalage, -decalage, decalage);
        glTexCoord2f(7, 7);
        glVertex3f(  decalage,  decalage, decalage);
        glTexCoord2f(0, 7);
        glVertex3f( -decalage,  decalage, decalage);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    // FACE ARRIERE
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glBegin(GL_QUADS);
        glNormal3f( 0, 0, -1);
        glTexCoord2f(0, 0);
        glVertex3f( -decalage, -decalage, -decalage);
        glTexCoord2f(7, 0);
        glVertex3f(  decalage, -decalage, -decalage);
        glTexCoord2f(7, 7);
        glVertex3f(  decalage,  decalage, -decalage);
        glTexCoord2f(0, 7);
        glVertex3f( -decalage,  decalage, -decalage);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    // FACE GAUCHE
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glBegin(GL_QUADS);
        glNormal3f(-1,0,0);
        glTexCoord2f(0, 0);
        glVertex3f(-decalage, -decalage, decalage);
        glTexCoord2f(7, 0);
        glVertex3f(-decalage,  decalage, decalage);
        glTexCoord2f(7, 7);
        glVertex3f(-decalage,  decalage, -decalage);
        glTexCoord2f(0, 7);
        glVertex3f(-decalage, -decalage, -decalage);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    // FACE DROITE
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glBegin(GL_QUADS);
        glNormal3f(1,0,0);
        glTexCoord2f(0, 0);
        glVertex3f(decalage, -decalage, decalage);
        glTexCoord2f(7, 0);
        glVertex3f(decalage,  decalage, decalage);
        glTexCoord2f(7, 7);
        glVertex3f(decalage,  decalage, -decalage);
        glTexCoord2f(0, 7);
        glVertex3f(decalage, -decalage, -decalage);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    // FACE DU DESSUS
    glBindTexture(GL_TEXTURE_2D, textures[4]);
    glBegin(GL_QUADS);
        glNormal3f(0, 1,0);
        glTexCoord2f(0, 0);
        glVertex3f(-decalage,  decalage, decalage);
        glTexCoord2f(7, 0);
        glVertex3f( decalage,  decalage, decalage);
        glTexCoord2f(7, 7);
        glVertex3f( decalage,  decalage, -decalage);
        glTexCoord2f(0, 7);
        glVertex3f(-decalage,  decalage, -decalage);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    // FACE DU DESSOUS
    glBindTexture(GL_TEXTURE_2D, textures[5]);
    glBegin(GL_QUADS);
        glNormal3f(0, -1,0);
        glTexCoord2f(0, 0);
        glVertex3f(-decalage, -decalage, decalage);
        glTexCoord2f(7, 0);
        glVertex3f( decalage, -decalage, decalage);
        glTexCoord2f(7, 7);
        glVertex3f( decalage, -decalage, -decalage);
        glTexCoord2f(0, 7);
        glVertex3f(-decalage, -decalage, -decalage);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}