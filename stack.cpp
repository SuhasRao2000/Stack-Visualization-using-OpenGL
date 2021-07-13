#include<iostream>
#include<cstring>
#include<string>
#include<Windows.h>
#include<GL/glut.h>
#include <cstdlib>
#define MAX 8
using namespace std;

void st_show();
void display();
class elements
{
public:
	char value[30];
};

int top = -1;
elements arr_ele[30];
void init()
{
	
	glViewport(0, 0, 1500, 1500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(-1250, 1250, -1250, 1250);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


}

void txt_draw(char *stri, int x, int y)
{

	glRasterPos2f(x, y);

	for (int i = 0; i < strlen(stri); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, stri[i]);
	}
}

void push()
{
	if (top >= MAX)
	{
		char msg[20] = "Stack Full";
		txt_draw(msg, -100, 200);
		glutSwapBuffers();
		Sleep(100);
	}
	else
	{
		top++;
		printf( "Enter the element to be pushed\n");
		cin >> arr_ele[top].value;
		printf("\n");
		st_show();


	}
}

void pop()
{
	if (top < 0)
	{
		char msg[20] = "Stack Empty";
		txt_draw(msg, -100, 200);
		
		glutSwapBuffers();

		Sleep(1000);
	}
	else
	{
		cout << "\nElement " << arr_ele[top].value << " is popped from stack\n";
		top--;
		st_show();
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'p' | 'P': push();
		break;

	case 'o' | 'O': pop();
		display();
		break;
	case 'q' | 'Q': exit(0);
	}
}


void st_show()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	

	int pos = -400;

	for (int i = 0; i <= top; i++)
	{

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_POLYGON);
		glVertex2f(-900, pos);
		glVertex2f(-700, pos);
		glVertex2f(-700, pos+150);
		glVertex2f(-900, pos+150);
		glEnd();

		glColor3f(1, 1, 1);
		glRasterPos2f(-810, (pos + 20));

		for (int j = 0; j < strlen(arr_ele[i].value); j++)
		{
			
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, arr_ele[i].value[j]);
		}
		pos += 150;

	}

	glutSwapBuffers();
	glPopMatrix();

}

void display()
{
	glClearColor(0,0.3,0.4, 0.6);
	
    glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0.6, 0.2);
	glRectf(-130, 850,400,1000);
	
	glColor3f(1, 0, 0);
	


	//Title
	char message4[] = "STACK VISUALIZATION";
	glRasterPos2i(-100, 900);
	for (int i = 0; i < strlen(message4); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message4[i]);
	}



	glColor3f(0,1, 0.8);
	if (top == -1)
	{
		char message[] = "Operation 1. Press P to Push an element into the Stack";
		glRasterPos2i(-300, 500);
		for (int i = 0; i < strlen(message); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
		}
		char message1[] = "Operation 2. Press O to Pop an element out pf the Stack";
		glRasterPos2i(-300, 300);
		for (int i = 0; i < strlen(message1); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message1[i]);
		}
		char message2[] = "Operation 3. Press Q to Exit";
		glRasterPos2i(-300, 100);
		for (int i = 0; i < strlen(message2); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message2[i]);
		}
		glFlush();
		glutSwapBuffers();
	}
	else {
		glFlush();
		
	}
}

void reshape(int w, int h) 
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glViewport(0, 0, w, h); 
	gluOrtho2D(-1250, 1250, -1250, 1250); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}

int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	init();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1400, 1400);
	glutCreateWindow("Visualiztion Of Stack Operations");
	

	glutKeyboardFunc(keyboard);
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop(); //loop the main section


}

