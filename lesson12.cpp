/*
 * facebook  : https://www.facebook.com/bahaa.elden20
 * linkedin  : https://www.linkedin.com/in/bahaaelden96/
 * Email     : bahaa.elden96@gmail.com
 * github    : https://github.com/bahaa-elden
 * CV        : https://www.slideshare.net/slideshow/embed_code/key/cEr8s2qrgH17Ih
 -------------------------------------Computer Graphics Section 12----------------------------------------
 */

#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>     /* srand, rand */
#include<stdio.h>
#include<time.h>
#include<math.h>

struct point
{
	int x;
	int y;
};
point p1 = { 100, 100 }, p2 = { 5000, 100 };
void specialKeys(int key, int x, int y);
void display() {
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	glVertex2i(p1.x, p1.y);
	glColor3f(0, 1, 0);
	glVertex2i(p2.x, p2.y);
	glEnd();
	p2.y += 1;
	p2.y %= 10000;
	if (p1.x <= p2.x + 1000 && p1.y <= p2.y + 1000 && p1.x >= p2.x - 1000 && p1.y >= p2.y - 1000){
		p2.y -= 1;
	}
	glFlush();
	glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(50, 150);   // Set the window's initial width & height
	glutInitWindowPosition(50, 10); // Position the window's initial top-left corner
	glPointSize(5);

	gluOrtho2D(1, 10000, 1, 10000);
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutSpecialFunc(specialKeys); // Register callback handler for special-key event
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}

float RandomNumber(float Min, float Max)
{
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}
void specialKeys(int key, int x, int y) {
	if (key == GLUT_KEY_RIGHT){
		p1.x += 100;
	}
	if (key == GLUT_KEY_LEFT){
		p1.x -= 100;
	}
	if (key == GLUT_KEY_UP){
		p1.y += 100;
	}
	if (key == GLUT_KEY_DOWN){
		p1.y -= 100;
	}
}
