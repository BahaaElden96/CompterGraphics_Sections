/*
 * facebook  : https://www.facebook.com/bahaa.elden20
 * linkedin  : https://www.linkedin.com/in/bahaaelden96/
 * Email     : bahaa.elden96@gmail.com
 * github    : https://github.com/bahaa-elden
 * CV        : https://www.slideshare.net/slideshow/embed_code/key/cEr8s2qrgH17Ih
 --------------------------------------Computer Graphics Section 11----------------------------------------
 */
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>     /* srand, rand */
#include<stdio.h>
#include<time.h>
#include<math.h>
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void drawcircle(float r,float posx,float posy);
GLfloat x[4] = { -0.3, 0.3, 0.3, -0.3 };
GLfloat y[4] = { -0.3, -0.3, 0.3, 0.3 };
float deltay = 0.001;
float deltax = 0.001;
float angle = 0;
float xmove = -1.5;
void display() {

	glMatrixMode(GL_PROJECTION);     // To operate on Model-View matrix
	glLoadIdentity();               // Reset the model-view ma
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
	glPushMatrix();
	//glTranslatef(xmove, 0.0, 0.0);
	glTranslatef(0.5+xmove, 0.5, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	drawcircle(0.5f, 0.0f, 0.3f);
	
	
	glPopMatrix();
	xmove += 0.0008;
	if (xmove >1.5)
		xmove = -1.5;
	angle -= 0.2;
	
	//glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(50, 150);   // Set the window's initial width & height
	glutInitDisplayMode(GLUT_DOUBLE);  // Enable double buffered mode
	glutInitWindowPosition(50, 10); // Position the window's initial top-left corner
	// initialize 100 points with random positions
	glPointSize(2);
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
float RandomNumber(int Min, float Max)
{
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}

void drawcircle(float r,float posx,float posy){
	//glColor3f(RandomNumber(0, 1), RandomNumber(0, 1), RandomNumber(0, 1));
	glBegin(GL_POINTS);
	for (int i = 0; i < 360; i += 10)
	{
		float deginrad = i*3.14 / 180;

		//glVertex2f(posx+r*sin(deginrad),posy+ r*cos(deginrad));
		glVertex2f(r*sin(deginrad),  r*cos(deginrad));
	}
	glEnd();
	

}
