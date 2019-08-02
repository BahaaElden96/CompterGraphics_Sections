/*
 * facebook  : https://www.facebook.com/bahaa.elden20
 * linkedin  : https://www.linkedin.com/in/bahaaelden96/
 * Email     : bahaa.elden96@gmail.com
 * github    : https://github.com/bahaa-elden
 * CV        : https://www.slideshare.net/slideshow/embed_code/key/cEr8s2qrgH17Ih
 --------------------------------------Computer Graphics Section 10----------------------------------------
 */
#include <windows.h>
#include <GL/glut.h>
#include<math.h>
#include<stdio.h>
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
int xmove = 10;
int xmove2 = 1;
int arx[] = { 10, 10, 50, 50 };
int ary[] = { 10, 50, 50, 10 };
int p1x = 10, p1y = 500;
int p2x = 900, p2y = 500;
void myKey(unsigned char key, int x, int y);
void specialKeys(int key, int x, int y);
void mouse(int button, int state, int x, int y);
boolean f=false;
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_POINTS);              // Each set of 4 vertices form a quad
	
		
		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex2i(p1x, p1y);    // x, y
		glColor3f(1.0f, 0.0f, 0.0f); // Red
		glVertex2i(p2x, p2y);    // x, y
	glEnd();
	p1x = p1x % 1100;
	//p1x += xmove;
	p2x -= xmove2;
	glFlush();  // Render now or Draw Now
	glutSwapBuffers();
	glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	gluOrtho2D(0, 1000, 0, 1000);
	glPointSize(5);
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutKeyboardFunc(myKey); // register the key handler.
	glutSpecialFunc(specialKeys); // Register callback handler for special-key event
	glutMouseFunc(mouse);   // Register callback handler for mouse event
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
void myKey(unsigned char key, int x, int y)
{
	if (key == 97 )//a
	{
		
		p1x += xmove;
		
	}
	
}
void specialKeys(int key, int x, int y) {
	if (key == GLUT_KEY_DOWN){
		p1x += xmove;
	}
}
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON ) { // Pause/resume
		xmove2 *= 0;
	}
	if (button == GLUT_RIGHT_BUTTON) { // Pause/resume
		xmove2 = 1;
	}
	printf("%d\t%d\n", x, y);
}
