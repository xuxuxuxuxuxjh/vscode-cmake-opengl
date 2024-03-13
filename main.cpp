//simple.c

#define _WCHAR_T_DEFINED
#include <glut.h>

void mydisplay(){
	 glClear(GL_COLOR_BUFFER_BIT); 
 

	 glBegin(GL_POLYGON);        
		glVertex2f(-0.5, -0.5);        
		glVertex2f(-0.5, 0.5);        
		glVertex2f(0.5, 0.5);        
		glVertex2f(0.5, -0.5);    
	glEnd();


	glFlush(); 
}


int main(int argc, char** argv){
	
	glutCreateWindow("simple");     
	
	glutDisplayFunc(mydisplay); 

	glutMainLoop();
}
