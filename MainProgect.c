#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>

int j=0;

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

void rectangle(float r, float g, float b, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	glEnd();
}

void points(float r, float g, float b, int x, int y){
	glColor3f(r,g,b);
	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void rotateMoon(){
		int k=0, a, b, c, d;
		float thetatheta;
		j+=1;
		if(j>360)
			j=0;
		thetatheta = j*3.142/180;
		a = 450+250*cos(thetatheta);
		b = 475+250*sin(thetatheta);
		c = 1350+850*cos(thetatheta);
		d = 0+600*sin(thetatheta);
		circleDraw(1.0, 1.0, 1.0, a, b, 30, 30);
		if(j>20&&j<125){
			circleDraw(1.0, 1.0, 1.0, c, d, 40, 40);
			glFlush();
			rectangle(0.0, 0.0, 0.0, 775, 600, 775, 0, 900, 0, 900, 600);
			lineDraw(1.0, 1.0, 1.0, 900, 950, 900, 0, 3.0);
		}
		glFlush();
		delay(30);
		circleDraw(0.0, 0.0, 0.0, a, b, 30, 30);
		if(j>20&&j<125){
			circleDraw(0.0, 0.0, 0.0, c, d, 40, 40);
			lineDraw(1.0, 1.0, 1.0, 900, 950, 900, 0, 3.0);
		}
	glutPostRedisplay();
}

void display() {
	//base
	rectangle(0.0, 0.0, 0.0, 0, 950, 0, 0, 1800, 0, 1800, 950);
	//sun
	//circleDraw(1.0, 1.0, 0.0, 1, 475, 50, 480);
	//stars
	points(1.0, 1.0, 1.0, 400, 900);points(1.0, 1.0, 1.0, 200, 900);points(1.0, 1.0, 1.0, 510, 800);points(1.0, 1.0, 1.0, 600, 837);
	points(1.0, 1.0, 1.0, 320, 800);points(1.0, 1.0, 1.0, 730, 859);points(1.0, 1.0, 1.0, 650, 839);points(1.0, 1.0, 1.0, 780, 816);
	points(1.0, 1.0, 1.0, 536, 850);points(1.0, 1.0, 1.0, 311, 901);points(1.0, 1.0, 1.0, 100, 888);points(1.0, 1.0, 1.0, 550, 899);
	points(1.0, 1.0, 1.0, 158, 600);points(1.0, 1.0, 1.0, 385, 695);points(1.0, 1.0, 1.0, 245, 527);points(1.0, 1.0, 1.0, 247, 514);
	points(1.0, 1.0, 1.0, 284, 700);points(1.0, 1.0, 1.0, 854, 546);points(1.0, 1.0, 1.0, 875, 324);points(1.0, 1.0, 1.0, 657, 489);
	points(1.0, 1.0, 1.0, 354, 150);points(1.0, 1.0, 1.0, 527, 126);points(1.0, 1.0, 1.0, 745, 147);points(1.0, 1.0, 1.0, 762, 125);
	points(1.0, 1.0, 1.0, 639, 100);points(1.0, 1.0, 1.0, 987, 89 );points(1.0, 1.0, 1.0, 325, 110);points(1.0, 1.0, 1.0, 458, 25 );
	points(1.0, 1.0, 1.0, 745, 30 );points(1.0, 1.0, 1.0, 127, 50 );points(1.0, 1.0, 1.0, 925, 63 );points(1.0, 1.0, 1.0, 324, 87 );
	//earth
	circleDraw(0.0, 0.0, 1.0, 450, 475, 100, 100);
	//earth 2
	circleDraw(0.1, 0.7, 0.2, 1350, 0, 600, 350);
	//BigEarth
	rectangle(0.0, 0.0, 0.0, 675, 240, 675, 0, 900, 0, 900, 240);
	//middleline
	lineDraw(1.0, 1.0, 1.0, 900, 950, 900, 0, 3.0);
	glFlush();
}

void output(char *s){
	int k;
	for(k=0;k<strlen(s);k++){
		glutStrokeCharacter(GLUT_STROKE_ROMAN,s[k]);
	}
}

void intro(){
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0,1.0,1.0);
	
	glPushMatrix();
	glTranslatef(280.0,800.0,0.0);
	glScalef(0.38,0.38,0.0);
	glLineWidth(3);
	output("Mangalore Institute of Technology and Engineering");
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(430.0,700.0,0.0);
	glScalef(0.28,0.28,0.0);
	glLineWidth(2);
	output("Department of Computer Science and Engineering");
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(740.0,600.0,0.0);
	glScalef(0.28,0.28,0.0);
	glLineWidth(2);
	output("Moon Simulation");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200.0,200.0,0.0);
	glScalef(0.28,0.28,0.0);
	glLineWidth(2);
	output("Shrinidhi A");
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(200.0,150.0,0.0);
	glScalef(0.28,0.28,0.0);
	glLineWidth(2);
	output("4MT19CS154");
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(1300.0,200.0,0.0);
	glScalef(0.28,0.28,0.0);
	glLineWidth(2);
	output("Sahana Kumari");
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(1300.0,150.0,0.0);
	glScalef(0.28,0.28,0.0);
	glLineWidth(2);
	output("4MT19CS129");
	glPopMatrix();
	
	circleDraw(0.5, 0.5, 0.5, 900, 450, 100, 100);
	glFlush();
	circleDraw(0.0, 0.0, 0.0, 870, 470, 100, 100);
	glFlush();
	
}



void myInit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1800.0, 0.0, 950.0);
}

void mouse(int btn, int state, int x, int y){
		if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
			glutDisplayFunc(display);
			glutIdleFunc(rotateMoon);
		}
}

void main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1800, 950);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("lunar phase simulation");
	glutDisplayFunc(intro);
	glutMouseFunc(mouse);
	myInit();
	glutMainLoop();
}
