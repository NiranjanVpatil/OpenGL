#include<math.h>
#include<iostream>
#include<GL/glut.h>
using namespace std;

float inc=1.0;
float angle=135;
GLfloat minAngle=0.0;

float drawCircle(float segments,float radius,float sx,float sy)
{
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<segments;i++)
    {
        float theta=2.0*3.142*float(i)/float(segments); 
        float x=radius*cos(theta);
        float y=radius*sin(theta);
        glVertex2f(x+sx,y+sy);
    }
    glEnd();
}

void draw(float x1,float y1,float angle)
{
    float segments=100;
    float radius=10.0;

glBegin(GL_LINE_STRIP);
	glColor3f(1,0,0);				//house
    glLineWidth(5);
    glVertex2f(15,12);                     
    glVertex2f(12,-10);
    glVertex2f(-12,-10);
    glVertex2f(-15,12);
    glVertex2f(-18,12);
    glVertex2f(0,20);
    glVertex2f(18,12);
    glVertex2f(15,12);
	glEnd();  

    	glLineWidth(5);                                //watch circle
	glColor3f(0,0,1);
	drawCircle(segments,radius,x1,y1);

	glLineWidth(3);                                //watch circle
	glColor3f(1,0,1);
	drawCircle(10,2.0,x1,y1);


    double radians=angle*3.142/180;
    float x2=(radius*3.4)*cos(radians);
    float y2=(radius*3.4)*sin(radians);
    float radius2=radius/3.0;

    glColor3f(0,1,0);                                   //pendulum
    glLineWidth(5);
    drawCircle(segments,radius2,x2,y2);

    glBegin(GL_LINES);
    glVertex2f(x1,-1*(radius)+0.2);
    glVertex2f(x2,y2);
    glEnd();


  glColor3f(0.8,1,0);                                  //hr hand
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(radius/2.0,radius/2.0);
    glEnd();


	minAngle += 0.2;
    glColor3f(1,0,1);					//min hand
    glLineWidth(5);
	glPushMatrix();
 	glTranslatef(x1, y1, 0.0);
	glRotatef(-minAngle, 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x1,((radius/2.0)*2.0));
    glEnd();

}


void display()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-10,10,-30);
    glColor3f(1,1,1);

if(angle>300)
{
angle=300;
inc=-inc;
}
if(angle<240)
{
angle=240;
inc=-inc;
}
    angle += inc;
    draw(0,2,angle);
    glutSwapBuffers();

}
void reshape(int w,int h)
{
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
gluPerspective (100, (GLfloat)w / (GLfloat)h, 0.5, 100.0);
glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Clock");

    glutDisplayFunc(display);
    glutIdleFunc(display);
   glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
