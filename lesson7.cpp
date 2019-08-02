/*
 * facebook  : https://www.facebook.com/bahaa.elden20
 * linkedin  : https://www.linkedin.com/in/bahaaelden96/
 * Email     : bahaa.elden96@gmail.com
 * github    : https://github.com/bahaa-elden
 * CV        : https://www.slideshare.net/slideshow/embed_code/key/cEr8s2qrgH17Ih
 ---------------------------------------Computer Graphics Section 7----------------------------------------
 */

#include <windows.h>
#include <GL/glut.h>
#include<math.h>

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
bool fullScreenMode = true; // Full-screen or windowed mode?

int xmove=1;
int arx[] = { 10, 10, 50, 50 };
int ary[] = { 10, 50, 50, 10 };
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	// Draw a Red 1x1 Square centered at origin
	
	glBegin(GL_POINTS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	for (int i = 0; i < 4; i++){
		arx[i] += xmove;
		ary[i] += xmove;
	glVertex2i(arx[i], ary[i]);    // x, y
	
	arx[i] = arx[i] % 1100;
	ary[i] = ary[i] % 1100;
	}
	glEnd();
	glFlush();  // Render now or Draw Now
	glutSwapBuffers();
	glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	gluOrtho2D(0,1000,0,1000);
	glPointSize(5);
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
