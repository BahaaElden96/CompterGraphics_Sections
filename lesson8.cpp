/*
 * facebook  : https://www.facebook.com/bahaa.elden20
 * linkedin  : https://www.linkedin.com/in/bahaaelden96/
 * Email     : bahaa.elden96@gmail.com
 * github    : https://github.com/bahaa-elden
 * CV        : https://www.slideshare.net/slideshow/embed_code/key/cEr8s2qrgH17Ih
 ---------------------------------------Computer Graphics Section 8----------------------------------------
 */
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>     /* srand, rand */
#include<stdio.h>
#include<time.h>
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

struct square{
	GLfloat x;
	GLfloat y;
	GLfloat size;
};
struct Point{
	GLfloat x;
	GLfloat y;
};
void delay(float secs);
void Dsquare(square s);
float RandomNumber(float Min, float Max);
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	// Draw a Red 1x1 Square centered at origin
	
	glBegin(GL_POINTS);              // Each set of 4 vertices form a quad
	glColor3f(RandomNumber(0, 1), RandomNumber(0, 1), RandomNumber(0, 1)); // Red
	Point points[10000];
	for (int i = 0; i < 10000; i++){
		
		points[i].x = RandomNumber(-1,1);
		points[i].y = RandomNumber(-1, 1);
		glVertex2f(points[i].x,points[i].y);    // x, y
	}
	glEnd();	
	glFlush();  // Render now
	glutPostRedisplay();
	delay(0.1);
	/*for (int i = 0; i < 10000; i++){
		printf("%f\t%f\n", points[i].x, points[i].y);
	}*/
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(100, 500);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
void Dsquare(square s){
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(s.x-s.size, s.y-s.size);    // x, y
	glVertex2f(s.x+s.size, s.y-s.size);
	glVertex2f(s.x+s.size,s.y+ s.size);
	glVertex2f(s.x-s.size,s.y+ s.size);
	//glVertex2f(0.0f, 0.0f);
	glEnd();
}
void delay(float secs)
{
	float endtime = clock() / CLOCKS_PER_SEC + secs;
	while ((clock() / CLOCKS_PER_SEC) < endtime);
}
float RandomNumber(float Min, float Max)
{
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}
