/*
 * facebook  : https://www.facebook.com/bahaa.elden20
 * linkedin  : https://www.linkedin.com/in/bahaaelden96/
 * Email     : bahaa.elden96@gmail.com
 * github    : https://github.com/bahaa-elden
 * CV        : https://www.slideshare.net/slideshow/embed_code/key/cEr8s2qrgH17Ih
 ---------------------------------------Computer Graphics Section 3----------------------------------------
 */
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>     /* srand, rand */
#include<stdio.h>
#include<time.h>
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
struct point{// this point
	float x;// x position
	float y;// y position
};
point p[100];// array of points contains 1000 points
float RandomNumber(float Min, float Max);
GLdouble a[4] = { -1.0, 1.0, -1.0, 1.0 };
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);// set background color 
	glClear(GL_COLOR_BUFFER_BIT);// clear buffer 
	glBegin(GL_POINTS);// we neeed draw point
	for (int i = 0; i < 100; i++){
		if (RandomNumber(0,1))
		glColor3f(RandomNumber(0.4, 1), RandomNumber(0.5, 1), RandomNumber(0.8, 1));// color used in point
		glVertex2f(p[i].x, p[i].y);// draw points 
	}
	glEnd();
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset the projection matrix
	
		// aspect >= 1, set the height from -1 to 1, with larger width
	a[2] += deltax;
	a[0] += deltax;
	gluOrtho2D(a[0] , a[1] , a[2], a[3]);

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
	for (int i = 0; i < 100; i++){
		p[i].x = RandomNumber(-1, 1);
		p[i].y = RandomNumber(-1, 1);
	}
	glPointSize(2);
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
float RandomNumber(float Min, float Max)
{
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}
