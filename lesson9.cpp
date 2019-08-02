/*
 * facebook  : https://www.facebook.com/bahaa.elden20
 * linkedin  : https://www.linkedin.com/in/bahaaelden96/
 * Email     : bahaa.elden96@gmail.com
 * github    : https://github.com/bahaa-elden
 * CV        : https://www.slideshare.net/slideshow/embed_code/key/cEr8s2qrgH17Ih
 ---------------------------------------Computer Graphics Section 9----------------------------------------
 */
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>     /* srand, rand */
#include<stdio.h>
#include<time.h>
#include<math.h>
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
struct point{// this point
	float x;// x position
	float y;// y position
};
double xold[4] = { -0.3, 0.3, 0.3, -0.3 };
GLfloat angle = 0.0f;  // rotational angle of the shapes
GLfloat deltax = 0.001;
GLfloat x = 0.0;
void display() {
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
	
glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
	glLoadIdentity();               // Reset the model-view matrix
	glPushMatrix();                     // Save model-view matrix setting
	glTranslatef(x, 0.0f, 0.0f);    // Translate
	glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
	
	
	glBegin(GL_QUADS);                  // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex2f(xold[0], -0.3f);
	glVertex2f(xold[1], -0.3f);
	glVertex2f(xold[2], 0.3f);
	glVertex2f(xold[3], 0.3f);
	glEnd();
	glPopMatrix();                      // Restore the model-view matrix
	glutSwapBuffers();   // Double buffered - swap the front and back buffers
	if (x >= 1)
		x = -1;
	// Change the rotational angle after each display()
	x += deltax;
	angle += 0.5f;
	

	/*glBegin(GL_TRIANGLES);
	glVertex2f(xold[0], yold[0]);
	glVertex2f(xold[1], yold[1]);
	glVertex2f(xold[2], yold[2]);
	glEnd();
	glColor3f(1, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex2f(xnew[0], ynew[0]);
	glVertex2f(xnew[1], ynew[1]);
	glVertex2f(xnew[2], ynew[2]);
	glEnd();*/
	glFlush();
	glutPostRedisplay();

}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(50, 150);   // Set the window's initial width & height
	glutInitWindowPosition(50, 10); // Position the window's initial top-left corner
	// initialize 100 points with random positions
	/*xnew[0] = xold[0] * cos(90.0) - yold[0] * sin(90.0);
	ynew[0] = xold[0] * sin(90.0)+yold[0] * cos(90.0);
	xnew[1] = xold[1] * cos(90.0) - yold[1] * sin(90.0);
	ynew[1] = xold[1] * sin(90.0) + yold[1] * cos(90.0);
	xnew[2] = xold[2] * cos(90.0) - yold[2] * sin(90.0);
	ynew[2] = xold[2] * sin(90.0) + yold[2] * cos(90.0);*/
	glPointSize(2);
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
float RandomNumber(float Min, float Max)
{
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}
