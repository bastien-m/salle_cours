#include "GL/glut.h"
#include <stdio.h>
#include "../header/vecteur.h"


void creerCube(int textures[])
{
    double decalage = 0.5;
    // FACE AVANT
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glBegin(GL_QUADS);
        glNormal3f( 0, 0,1);
        glTexCoord2f(0, 0);
        glVertex3f( -decalage, -decalage, decalage);
        glTexCoord2f(1, 0);
        glVertex3f(  decalage, -decalage, decalage);
        glTexCoord2f(1, 1);
        glVertex3f(  decalage,  decalage, decalage);
        glTexCoord2f(0, 1);
        glVertex3f( -decalage,  decalage, decalage);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    // FACE ARRIERE
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glBegin(GL_QUADS);
        glNormal3f( 0, 0, -1);
        glTexCoord2f(0, 0);
        glVertex3f( -decalage, -decalage, -decalage);
        glTexCoord2f(1, 0);
        glVertex3f(  decalage, -decalage, -decalage);
        glTexCoord2f(1, 1);
        glVertex3f(  decalage,  decalage, -decalage);
        glTexCoord2f(0, 1);
        glVertex3f( -decalage,  decalage, -decalage);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    // FACE GAUCHE
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glBegin(GL_QUADS);
        glNormal3f(-1,0,0);
        glTexCoord2f(0, 0);
        glVertex3f(-decalage, -decalage, decalage);
        glTexCoord2f(1, 0);
        glVertex3f(-decalage,  decalage, decalage);
        glTexCoord2f(1, 1);
        glVertex3f(-decalage,  decalage, -decalage);
        glTexCoord2f(0, 1);
        glVertex3f(-decalage, -decalage, -decalage);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    // FACE DROITE
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glBegin(GL_QUADS);
        glNormal3f(1,0,0);
        glTexCoord2f(0, 0);
        glVertex3f(decalage, -decalage, decalage);
        glTexCoord2f(1, 0);
        glVertex3f(decalage,  decalage, decalage);
        glTexCoord2f(1, 1);
        glVertex3f(decalage,  decalage, -decalage);
        glTexCoord2f(0, 1);
        glVertex3f(decalage, -decalage, -decalage);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    // FACE DU DESSUS
    glBindTexture(GL_TEXTURE_2D, textures[4]);
    glBegin(GL_QUADS);
        glNormal3f(0, 1,0);
        glTexCoord2f(0, 0);
        glVertex3f(-decalage,  decalage, decalage);
        glTexCoord2f(1, 0);
        glVertex3f( decalage,  decalage, decalage);
        glTexCoord2f(1, 1);
        glVertex3f( decalage,  decalage, -decalage);
        glTexCoord2f(0, 1);
        glVertex3f(-decalage,  decalage, -decalage);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    // FACE DU DESSOUS
    glBindTexture(GL_TEXTURE_2D, textures[5]);
    glBegin(GL_QUADS);
        glNormal3f(0, -1,0);
        glTexCoord2f(0, 0);
        glVertex3f(-decalage, -decalage, decalage);
        glTexCoord2f(1, 0);
        glVertex3f( decalage, -decalage, decalage);
        glTexCoord2f(1, 1);
        glVertex3f( decalage, -decalage, -decalage);
        glTexCoord2f(0, 1);
        glVertex3f(-decalage, -decalage, -decalage);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

}

vecteur vectoriel(vecteur X, vecteur Y)
{
    vecteur W;

    W.x = (X.y*Y.z)-(X.z*Y.y);
    W.y = (X.z*Y.x)-(X.x*Y.z);
    W.z = (X.x*Y.y)-(X.y*Y.x);

    return W;
}
