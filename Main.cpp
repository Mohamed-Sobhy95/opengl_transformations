#include<GL/Glut.h> //includes the opengl, glu, and glut header files
#include<stdlib.h> //includes the standard library header file
#include<iostream>
#include<cmath>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
float vertices[] =
{
	0.5, 0.5,
	0, 0.5,
	0, 0,
	0.5, 0

};
void draw(void)
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);
	//glBegin(GL_POLYGON);
	//glutSwapBuffers();
	glVertex2f(vertices[0], vertices[1]);
	glVertex2f(vertices[2], vertices[3]);
	glVertex2f(vertices[4], vertices[5]);
	glVertex2f(vertices[6], vertices[7]);
	glEnd();
	glFlush();
}
void Display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1,0,0,1);
	draw();
}
void rotate(float th)
{
	vertices[0] = vertices[0] * cos(th*(M_1_PI / 180)) - vertices[1] * sin(th*(M_1_PI / 180));
	vertices[2] = vertices[2] * cos(th*(M_1_PI / 180)) - vertices[3] * sin(th*(M_1_PI / 180));
	vertices[4] = vertices[4] * cos(th*(M_1_PI / 180)) - vertices[5] * sin(th*(M_1_PI / 180));
	vertices[6] = vertices[6] * cos(th*(M_1_PI / 180)) - vertices[7] * sin(th*(M_1_PI / 180));

	vertices[1] = vertices[0] * sin(th*(M_1_PI / 180)) + vertices[1] * cos(th*(M_1_PI / 180));
	vertices[3] = vertices[2] * sin(th*(M_1_PI / 180)) + vertices[3] * cos(th*(M_1_PI / 180));
	vertices[5] = vertices[4] * sin(th*(M_1_PI / 180)) + vertices[5] * cos(th*(M_1_PI / 180));
	vertices[7] = vertices[6] * sin(th*(M_1_PI / 180)) + vertices[7] * cos(th*(M_1_PI / 180));

	draw();

}
void changeY(float x)
{
	vertices[0] += x;
	vertices[2] += x;
	vertices[4] += x;
	vertices[6] += x;
	/*cout << vertices[0] << endl;
	cout << vertices[2] << endl;
	cout << vertices[4] << endl;
	cout << vertices[6] << endl;*/
	draw();
}
void changeX(float x)
{
	vertices[1] += x;
	vertices[3] += x;
	vertices[5] += x;
	vertices[7] += x;
	/*cout << vertices[1] << endl;
	cout << vertices[3] << endl;
	cout << vertices[5] << endl;
	cout << vertices[7] << endl;*/
	draw();
}
void scale(float x)
{
	for (int i = 0; i < 8; i++)
		vertices[i] *= x;

}
void keyPressed(unsigned char key, int x, int y) {

	switch (key)
	{
	case 'L':
	case 'l':
		scale(1.1);
		
		break;
	case 'S':
	case 's':
		scale(0.9);
		
		break;
	case 'R':
	case 'r':
		rotate(10);
		break;
		
	}
}
void keypressSpecial(int key, int x, int y)
{
	//glutSetKeyRepeat(0);

	if (key == GLUT_KEY_UP) {
		changeX(0.1);
	}

	if (key == GLUT_KEY_DOWN) {
		changeX(-0.1);
	}

	if (key == GLUT_KEY_RIGHT) {
		changeY(0.1);
	}

	if (key == GLUT_KEY_LEFT) {
		changeY(-0.1);
	}
}
int main(int argc, char** argv)
{
	cout << "press up,down,right,left to move the shape" << endl
		<< "press (r) to rotate \npress (s) to zoom out and (l)to zoom in\n";
	glutInit(&argc, argv);
	glutInitWindowSize(640, 640);   //sets the width and height of the window in pixels
	glutInitWindowPosition(100, 50);//sets the position of the window in pixels from top left corner 

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//creates a single frame buffer of RGB color capacity.
	glutCreateWindow("transformation");//creates the window as specified by the user as above.
	glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed  
	glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
					  //gluOrtho2D(-100, 100, -100, 100);
	glClearColor(0, 0, 0, 0); // sets the backgraound color to white light
	glClear(GL_COLOR_BUFFER_BIT); // clears the frame buffer and set values defined in glClearColor() function call 

	glutDisplayFunc(Display);//links the display event with the display event handler(display)
	glutIdleFunc(Display);
	glutSpecialFunc(keypressSpecial);
	//glutMouseFunc(mouse);//keyboard event handler

	glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses  
	glutMainLoop();//loops the current event
}

