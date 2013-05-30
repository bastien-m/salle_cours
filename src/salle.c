#include "GL/glut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../header/perimetre_salle.h"
#include "../header/ensemble_bureau.h"
#include "../header/fenetre.h"
#include "../header/cube.h"
#include "../header/tga.h"
#include "../header/gestion_texture.h"

#define GLUT_WHEEL_UP 3
#define GLUT_WHEEL_DOWN 4

struct Point3D 
{
    float x;
    float y;
    float z;
} observateur, pointVise, orientation;

struct Curseur 
{
    int estAppuye;
    int x;
    int y;
} curseur;

double distance_observateur = -100;
double angle_rotation   = 5.0;


void initialiserVariable()
{
    observateur.x = 100.0;
    observateur.y = 150.0;
    observateur.z = 300.0;
    pointVise.x   = observateur.x;
    pointVise.y   = observateur.y;
    pointVise.z   = observateur.z + distance_observateur;
    orientation.x = 0.0;
    orientation.y = 1.0;
    orientation.z = 0.0;
}

double degres_to_radian(double angle_degres)
{
    return angle_degres * M_PI / 180.0;
}

double radian_to_degres(double angle_radian)
{
    return angle_radian * 180.0 / M_PI;
}


void gestion_clavier(unsigned char touche, int x, int y)
{
    double distance_x = pointVise.x - observateur.x;
    double distance_z = pointVise.z - observateur.z;


    if(touche == '4'){
        angle_rotation-=5.0;
    }
    if(touche == '6'){
        angle_rotation+=5.0;
    }
    pointVise.x = cos(degres_to_radian(angle_rotation)) * distance_observateur;
    pointVise.z = sin(degres_to_radian(angle_rotation)) * distance_observateur;
    glutPostRedisplay();
    printf("pointVise.x : %f , pointVise.z: %f\n", pointVise.x, pointVise.z);
    if(touche == 27) exit(0);
}

void touches_speciales(int touche, int x, int y)
{
    // printf("observateur.x-=10 = %f\n", observateur.x-10);
    // printf("(-salle_x / 2.0) = %f\n", (-salle_x / 2.0));
    switch(touche)
    {
        case GLUT_KEY_LEFT:
            if(observateur.x - 10 >  -salle_x / 2.0){
                observateur.x-=10;
                pointVise.x-=10;
                glutPostRedisplay();
            }
            break;
        case GLUT_KEY_RIGHT:
            if(observateur.x + 10 < salle_x / 2.0){  
                observateur.x+=10;
                pointVise.x+=10;
                glutPostRedisplay();
            }
            break;
        case GLUT_KEY_DOWN:
            if(observateur.z + 10 < salle_z / 2.0){
                observateur.z+=10;
                pointVise.z+=10;
                glutPostRedisplay();    
            }
            break;
        case GLUT_KEY_UP:
            if(observateur.z - 10 > -salle_z / 2.0 ){
                observateur.z-=10;
                pointVise.z-=10;
                glutPostRedisplay();
            }
            break;
        case GLUT_KEY_PAGE_UP:
            if(observateur.y + 2 < salle_y){
                observateur.y+=2;
                pointVise.y+=2;
                glutPostRedisplay();
            }
            break;
        case GLUT_KEY_PAGE_DOWN:
            if(observateur.y - 2 >= 0){
                observateur.y-=2;
                pointVise.y-=2;
                glutPostRedisplay();
            }
            break;
        case GLUT_KEY_END:
            exit(0);
            break;
        default:
            break;
    }
}

float mat_ambiante[]    = {0.4, 0.4 ,0.4, 1.};
float mat_diffuse[]     = {0.7,0.7,0.7,1.};
float mat_speculaire[]  = {0.98, 0.98, 0.98, 1.};
float eclat[]           = {50.0};
float position[]        = {-385 , 300, 0, 1.0};/* 1 : lum. positionnelle */

void afficher() 
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    /* VISUALISATION : mise en place de l'observateur */

    glMatrixMode(GL_MODELVIEW);         /* active la matrice de MODELISATION           */
    glLoadIdentity();                   /* charge la matrice IDENTITE                  */
    gluLookAt(observateur.x, observateur.y, observateur.z, pointVise.x, pointVise.y, pointVise.z, orientation.x, orientation.y, orientation.z);
    
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambiante);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_speculaire);
    glMaterialfv(GL_FRONT, GL_SHININESS, eclat);



    glCallList(id_perimetre_salle);

    glPushMatrix();
    glTranslated(0.0, 0.0, -salle_z / 2.0);
    glCallList(id_fenetre);
    glPopMatrix();

    // ================= creation des elements de la salle ====================== //
    double translation_x = salle_x / 2;
    double translation_z = -salle_z / 2 + 200.0; // 2.0 place entre le tableau et le premier rang

    // glPushMatrix();
    // glTranslated(-385 + 25.0, 300 - 25.0, 0);
    // glScaled(50,50,50);
    // creerCube();
    // glPopMatrix();

    int i = 0;
    int j = 0;
    for(i; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            glPushMatrix();
            glTranslated(translation_x - bloc_x / 2.0 - bloc_x * j, 0, translation_z + bloc_z / 2.0 + bloc_z * i);
            glCallList(id_ensemble_bureau);
            glPopMatrix();
        }
    }

    glutSwapBuffers();
}

void rafraichir(int l, int h) 
{
    /* l et h sont les dimensions récupérées de la fenêtre */
    /* PROJECTION : définition du volume de vue */

    if (l > 3. / 2. * h) 
        l = 3. / 2. * h; /* permet de conserver le ratio largeur hauteur */
    else 
        h = 2. / 3. * l;

    glViewport(0, 0, l, h); /* définition de la zone écran dans la fenêtre */

    glMatrixMode(GL_PROJECTION); /* active la matrice de PROJECTION       */
    glLoadIdentity(); /* charge la matrice IDENTITE            */
    glFrustum(-1.8, 1.8, -1.2, 1.2, 5.0, 10000.0); /* définit le volume de vue :            */
    /* gauche : -1.8,    droit : 1.8         */
    /* bas    : -1.2,    haut  : 1.2         */
    /* avant-plan : 5, arrière-plan : 10     */

}



void mouse(int button, int state, int x, int y) 
{
    if (state == GLUT_UP) 
    {
    } 
    else if (state == GLUT_DOWN)
    if (button == GLUT_WHEEL_UP) 
    {
        if( observateur.z - 10 > -salle_z / 2.0){
            observateur.z-=10;
        }
            
    } 
    else if (button == GLUT_WHEEL_DOWN) 
    {
        if( observateur.z + 10 < salle_z / 2.0)
            observateur.z+=10;
    }
    glutPostRedisplay();
}

void motion(int x, int y)
{
    
}


void initLumieres()
{
    float comp_ambiante[]   = {0.88,0.83,0.74,1.};     /* intensite ambiante de la lumiere                */
    float comp_diffuse[]    = {0.8,0.8,0.8,1.};     /* intensite diffuse de la lumiere                 */
    float comp_speculaire[] = {0.8,0.8,0.8,1.};     /* intensite speculaire de la lumiere              */

    glEnable(GL_LIGHT0);                            /* active la lumiere 0 */
    glLightfv(GL_LIGHT0,GL_AMBIENT,comp_ambiante);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,comp_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,comp_speculaire);
}

main(int argc, char **argv)
{
    initialiserVariable();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_ALPHA | GLUT_MULTISAMPLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("Salle de classe");
    glutMotionFunc(&motion);
    glutMouseFunc(&mouse);

    glClearColor(0.5,0.5,0.5,1);

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE); 
    glShadeModel(GL_SMOOTH); /* définit le modèle de dégradé : GL_SMOOTH ou GL_FLAT */
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
    glEnable(GL_RESCALE_NORMAL);
    glEnable(GL_TEXTURE_2D);

    glEnable(GL_LIGHTING);   /* active l'éclairage */
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    initLumieres();

    creation_perimetre_salle();
    creation_ensemble_bureau();
    creation_fenetre();

    glutKeyboardFunc(&gestion_clavier);
    glutSpecialFunc(&touches_speciales);
    glutDisplayFunc(&afficher);
    glutReshapeFunc(&rafraichir);

    glutMainLoop();
}