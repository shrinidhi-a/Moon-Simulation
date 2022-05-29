#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>


void circleDraw(float r, float g, float b, int x, int y, int px, int py){
	int i=0;
	float theta;
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);
	for(i=0; i<360; i++){
		theta = i*3.142/180;
		glVertex2f(x+px*cos(theta),y+py*sin(theta));
	}
	glEnd();
}

void lineDraw(float r, float g, float b, int p, int q, int r1, int s, float w){
	glColor3f(r,g,b);
	glLineWidth(w);
	glBegin(GL_LINES);
	glVertex2i(p,q);
	glVertex2i(r1,s);
	glEnd();
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void rotateMoon(){
	while(1){
		int j=0, k=0, a, b;
		float thetatheta, theta2;
		for(j=0; j<360; j++){
			thetatheta = j*3.142/180;
			a = 450+250*cos(thetatheta);
			b = 475+250*sin(thetatheta);
			circleDraw(1.0, 1.0, 1.0, a, b, 30, 30);
			glFlush();
			delay(15);
			circleDraw(0.0, 0.0, 0.0, a, b, 30, 30);
			glFlush();
		}
	}
}



void display() {
	//middleline
	lineDraw(1.0, 1.0, 1.0, 900, 950, 900, 0, 3.0);
	//sun
	circleDraw(1.0, 1.0, 0.0, 1, 475, 50, 480);
	//earth
	circleDraw(0.0, 0.0, 1.0, 450, 475, 100, 100);
	//earth 2
	//circleDraw(0.0, 0.0, 1.0, 1350, 0, 600, 350);
	//moon
	rotateMoon();
	//circleDraw(1.0, 1.0, 1.0, 300, 625, 30, 30);
	glFlush();
}



void myInit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1800.0, 0.0, 950.0);
}

void main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1800, 950);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("lunar phase simulation");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}
