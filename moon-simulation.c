#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>

int j=0;
float h=0, p=0;

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

void circledotted(float r, float g, float b, int x, int y, int px, int py){
	float i=0;
	float theta;
	glColor3f(r,g,b);
	glPointSize(20);
	glBegin(GL_POINTS);
	for(i=0; i<360; i=i+5){
		theta = i*3.142/180;
		glVertex2f(x+px*cos(theta),y+py*sin(theta));
	}
	glEnd();
}

void pointroad(){
	glColor3f(0.3, 0.3, 0.3);
	glPointSize(30);
	glBegin(GL_POINTS);
	glVertex2f(1350,1);
	glEnd();
}

void circle(float r, float g, float b, int x, int y, int px, int py){
	float i=0;
	float theta;
	glColor3f(r,g,b);
	glPointSize(5);
	glBegin(GL_POINTS);
	for(i=0; i<360; i=i+0.5){
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

void earth(){
	glColor3f(0.0, 0.7, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(389.0,416.0);glVertex2f(390.0,414.0);glVertex2f(391.0,412.0);glVertex2f(391.0,410.0);glVertex2f(390.0,408.0);
	glVertex2f(389.0,406.0);glVertex2f(388.0,404.0);glVertex2f(389.0,402.0);glVertex2f(389.0,398.0);glVertex2f(390.0,397.0);
	glVertex2f(388.0,398.0);glVertex2f(386.0,399.0);glVertex2f(384.0,401.0);glVertex2f(381.0,403.0);glVertex2f(380.0,404.0);
	glVertex2f(378.0,406.0);glVertex2f(376.0,409.0);glVertex2f(373.0,411.0);glVertex2f(372.0,413.0);glVertex2f(370.0,415.0);
	glVertex2f(368.0,417.0);glVertex2f(367.0,419.0);glVertex2f(365.0,421.0);glVertex2f(364.0,424.0);glVertex2f(362.0,426.0);
	glVertex2f(360.0,429.0);glVertex2f(360.0,432.0);glVertex2f(358.0,436.0);glVertex2f(356.0,440.0);glVertex2f(354.0,444.0);
	glVertex2f(353.0,448.0);glVertex2f(353.0,451.0);glVertex2f(352.0,454.0);glVertex2f(352.0,459.0);glVertex2f(351.0,463.0);
	glVertex2f(350.0,466.0);glVertex2f(350.0,470.0);glVertex2f(350.0,474.0);
	glEnd();
	
	rectangle(0.0, 0.7, 0.0, 391, 411, 388, 424, 392, 431, 379, 430);
	rectangle(0.0, 0.7, 0.0, 379, 430, 360, 459, 369, 455, 378, 457);
	rectangle(0.0, 0.7, 0.0, 378, 457, 379, 430, 392, 431, 390, 441);
	rectangle(0.0, 0.7, 0.0, 378, 457, 396, 444, 392, 431, 390, 441);
	rectangle(0.0, 0.7, 0.0, 378, 457, 396, 444, 397, 451, 384, 459);
	rectangle(0.0, 0.7, 0.0, 402, 459, 402, 451, 397, 451, 384, 459);
	rectangle(0.0, 0.7, 0.0, 402, 459, 402, 451, 408, 455, 408, 461);
	rectangle(0.0, 0.7, 0.0, 413, 461, 413, 455, 408, 455, 408, 461);
	rectangle(0.0, 0.7, 0.0, 421, 458, 421, 460, 408, 455, 408, 461);
	rectangle(0.0, 0.7, 0.0, 480, 385, 505, 392, 512, 414, 480, 409);
	
	glColor3f(0.0, 0.7, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(480,385);glVertex2f(473,378);glVertex2f(480,385);glVertex2f(473,378);glVertex2f(475,378);
	glVertex2f(477,378);glVertex2f(479,379);glVertex2f(480,380);glVertex2f(482,380);glVertex2f(483,381);
	glVertex2f(484,381);glVertex2f(486,381);glVertex2f(487,382);glVertex2f(488,383);glVertex2f(489,384);
	glVertex2f(491,384);glVertex2f(493,385);glVertex2f(494,386);glVertex2f(496,386);glVertex2f(498,388);
	glVertex2f(499.0,388.0);glVertex2f(501.0,389.0);glVertex2f(502.0,390.0);glVertex2f(504.0,390.0);glVertex2f(506.0,392.0);
	glVertex2f(507.0,392.0);glVertex2f(508.0,393.0);glVertex2f(510.0,394.0);glVertex2f(511.0,395.0);glVertex2f(512.0,397.0);
	glVertex2f(513.0,398.0);glVertex2f(515.0,399.0);glVertex2f(516.0,400.0);glVertex2f(517.0,402.0);glVertex2f(519.0,404.0);
	glVertex2f(521.0,405.0);glVertex2f(522.0,406.0);glVertex2f(523.0,407.0);glVertex2f(524.0,409.0);glVertex2f(525.0,409.0);
	glVertex2f(526.0,410.0);glVertex2f(526.0,412.0);glVertex2f(512.0,414.0);
	glEnd();
	
	rectangle(0.0, 0.7, 0.0, 512, 414, 523, 412, 522, 415, 518, 417);
	rectangle(0.0, 0.7, 0.0, 480, 409, 480, 415, 509, 415, 512, 414);
	rectangle(0.0, 0.7, 0.0, 487, 417, 480, 415, 509, 415, 503, 417);
	rectangle(0.0, 0.7, 0.0, 480, 409, 480, 415, 477, 414, 477, 410);
	rectangle(0.0, 0.7, 0.0, 480, 403, 477, 399, 478, 395, 481, 395);
	rectangle(0.0, 0.7, 0.0, 480, 385, 475, 389, 477, 382, 481, 395);
	rectangle(0.0, 0.7, 0.0, 446, 452, 441, 485, 478, 488, 479, 457);
	rectangle(0.0, 0.7, 0.0, 446, 452, 449, 444, 470, 446, 479, 457);
	rectangle(0.0, 0.7, 0.0, 446, 452, 449, 444, 445, 448, 448, 444);
	rectangle(0.0, 0.7, 0.0, 446, 452, 441, 485, 433, 481, 434, 468);
	rectangle(0.0, 0.7, 0.0, 453, 486, 455, 498, 466, 496, 478, 488);
	rectangle(0.0, 0.7, 0.0, 479, 457, 483, 476, 482, 482, 478, 488);
	rectangle(0.0, 0.7, 0.0, 434, 468, 429, 459, 433, 456, 440, 460);
	rectangle(0.0, 0.7, 0.0, 446, 485, 454, 491, 462, 493, 457, 479);
	rectangle(0.0, 0.7, 0.0, 465, 535, 454, 550, 453, 559, 471, 534);
	rectangle(0.0, 0.7, 0.0, 469, 562, 462, 566, 453, 559, 471, 534);
	rectangle(0.0, 0.7, 0.0, 469, 562, 478, 561, 481, 540, 471, 534);
	rectangle(0.0, 0.7, 0.0, 485, 562, 478, 561, 481, 540, 488, 535);
	rectangle(0.0, 0.7, 0.0, 485, 562, 496, 555, 494, 527, 488, 535);
	rectangle(0.0, 0.7, 0.0, 505, 539, 496, 555, 494, 527, 500, 521);
	rectangle(0.0, 0.7, 0.0, 505, 539, 509, 529, 507, 523, 500, 521);
	rectangle(0.0, 0.7, 0.0, 505, 539, 496, 555, 485, 562, 506, 550);
}

void pirhouse(){
	rectangle(0.2, 0.0, 1.0, 1325, 470, 1375, 470, 1375, 520, 1325, 520);
	rectangle(0.3, 0.5, 0.8, 1250, 350, 1450, 350, 1450, 470, 1250, 470);
	rectangle(0.3, 0.2, 1.0, 1300, 350, 1400, 350, 1400, 500, 1300, 500);
	rectangle(0.3, 0.6, 1.0, 1375, 350, 1475, 350, 1475, 420, 1375, 420);
	rectangle(0.3, 0.6, 1.0, 1225, 350, 1325, 350, 1325, 420, 1225, 420);
	rectangle(0.3, 0.0, 1.0, 1200, 340, 1500, 340, 1500, 380, 1200, 380);
	
}

void road(){
	rectangle(0.0, 0.5, 0.0, 1315, 350, 1385, 350, 1460, 0, 1240, 0);
	rectangle(0.3, 0.3, 0.3, 1325, 350, 1375, 350, 1450, 0, 1250, 0);
	lineDraw(1.0, 1.0, 1.0, 1350, 0, 1350, 350, 5.0);
	glPushMatrix();
	glTranslatef(0,0,0);
	pointroad();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,60,0);
	pointroad();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,120,0);
	pointroad();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,180,0);
	pointroad();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,240,0);
	pointroad();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,300,0);
	pointroad();
	glPopMatrix();
}

void tree(){
	rectangle(0.3, 0.1, 0.0, 1413, 530, 1427, 530, 1427, 410, 1413, 410);
	circleDraw(0.0, 0.5, 0.0, 1400, 500, 40, 20);
	circleDraw(0.0, 0.5, 0.0, 1440, 500, 40, 20);
	circleDraw(0.0, 0.5, 0.0, 1420, 530, 40, 20);
	circleDraw(0.0, 0.5, 0.0, 1420, 530, 20, 40);
	
}

void tree1(){
	rectangle(0.3, 0.1, 0.0, 1413, 530, 1427, 530, 1427, 410, 1413, 410);
	circleDraw(0.0, 0.3, 0.0, 1400, 500, 40, 20);
	circleDraw(0.0, 0.3, 0.0, 1440, 500, 40, 20);
	circleDraw(0.0, 0.3, 0.0, 1420, 530, 40, 20);
	circleDraw(0.0, 0.3, 0.0, 1420, 530, 20, 40);
	
	
}

void car(){
	rectangle(1.0, 0.0, 0.0, 1310, 265, 1390, 265, 1390, 280, 1310, 280);
	rectangle(1.0, 0.0, 0.0, 1320, 295, 1380, 295, 1390, 280, 1310, 280);
	rectangle(0.0, 0.0, 0.0, 1322, 293, 1335, 293, 1335, 278, 1312, 278);
	rectangle(0.0, 0.0, 0.0, 1337, 293, 1337, 278, 1360, 278, 1360, 293);
	rectangle(0.0, 0.0, 0.0, 1362, 293, 1362, 278, 1388, 278, 1378, 293);
	circleDraw(0.0, 0.0, 0.0, 1325, 265, 9, 9);
	circleDraw(0.5, 0.5, 0.5, 1325, 265, 5, 5);
	circleDraw(0.0, 0.0, 0.0, 1374, 265, 9, 9);
	circleDraw(0.5, 0.5, 0.5, 1374, 265, 5, 5);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void rotateMoon(){
		int k=0, a, b, c, d;
		float thetatheta;
		h+=0.3;
		if(h>360)
			h=0;
		p+=0.3;
		if(p>30)
			p=-30;
		j+=1;
		if(j>360)
			j=0;
		circleDraw(0.0, 0.0, 0.0, 700, 475, 30, 30);
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
		if(j>20&&j<125){
			lineDraw(1.0, 1.0, 1.0, 900, 950, 900, 0, 3.0);
		}
	glutPostRedisplay();
}


void display() {
	//base
	rectangle(0.0, 0.0, 0.0, 0, 950, 0, 0, 1800, 0, 1800, 950);
	//sun
	//stars
	points(1.0, 1.0, 1.0, 400, 900);points(1.0, 1.0, 1.0, 200, 900);points(1.0, 1.0, 1.0, 510, 800);points(1.0, 1.0, 1.0, 600, 837);
	points(1.0, 1.0, 1.0, 320, 800);points(1.0, 1.0, 1.0, 730, 859);points(1.0, 1.0, 1.0, 650, 839);points(1.0, 1.0, 1.0, 780, 816);
	points(1.0, 1.0, 1.0, 536, 850);points(1.0, 1.0, 1.0, 311, 901);points(1.0, 1.0, 1.0, 100, 888);points(1.0, 1.0, 1.0, 550, 899);
	points(1.0, 1.0, 1.0, 158, 600);points(1.0, 1.0, 1.0, 385, 695);points(1.0, 1.0, 1.0, 245, 527);points(1.0, 1.0, 1.0, 247, 514);
	points(1.0, 1.0, 1.0, 284, 700);points(1.0, 1.0, 1.0, 657, 489);points(1.0, 1.0, 1.0, 925, 63 );points(1.0, 1.0, 1.0, 324, 87 );
	points(1.0, 1.0, 1.0, 354, 150);points(1.0, 1.0, 1.0, 527, 126);points(1.0, 1.0, 1.0, 745, 147);points(1.0, 1.0, 1.0, 762, 125);
	points(1.0, 1.0, 1.0, 639, 100);points(1.0, 1.0, 1.0, 987, 89 );points(1.0, 1.0, 1.0, 325, 110);points(1.0, 1.0, 1.0, 458, 25 );
	points(1.0, 1.0, 1.0, 745, 30 );points(1.0, 1.0, 1.0, 127, 50 );
	
	points(1.0, 1.0, 1.0, 1300, 900);points(1.0, 1.0, 1.0, 1100, 900);points(1.0, 1.0, 1.0, 1410, 800);points(1.0, 1.0, 1.0, 1500, 837);
	points(1.0, 1.0, 1.0, 1220, 780);points(1.0, 1.0, 1.0, 1630, 870);points(1.0, 1.0, 1.0, 1550, 850);points(1.0, 1.0, 1.0, 1680, 840);
	points(1.0, 1.0, 1.0, 1436, 860);points(1.0, 1.0, 1.0, 1211, 920);points(1.0, 1.0, 1.0, 1000, 850);points(1.0, 1.0, 1.0, 1450, 840);
	points(1.0, 1.0, 1.0, 1058, 550);points(1.0, 1.0, 1.0, 1285, 700);points(1.0, 1.0, 1.0, 1145, 580);points(1.0, 1.0, 1.0, 1147, 600);
	points(1.0, 1.0, 1.0, 745, 30 );points(1.0, 1.0, 1.0, 127, 50 );
	//earth
	circleDraw(0.0, 0.0, 1.0, 450, 475, 101, 101);
	
	glPushMatrix();
	glTranslatef(450,475,0);
	glRotatef(h, 0.0, 0.0, 1.0);
	glTranslatef(-450,-475,0);
	earth();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,-15,0);
	pirhouse();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(90,-80,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-230,-80,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-300,-120,0);
	tree1();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-380,-140,0);
	tree();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(160,-120,0);
	tree1();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(240,-140,0);
	tree();
	glPopMatrix();
	
	circleDraw(0.5, 0.3, 0.0, 1350, 0, 600, 350);
	//BigEarth
	circleDraw(0.0, 0.5, 0.0, 1350, 0, 560, 310);
	circleDraw(0.3, 0.3, 0.3, 1350, 0, 550, 300);
	circleDraw(0.0, 0.5, 0.0, 1350, 0, 500, 250);
	circleDraw(0.0, 0.7, 0.0, 1350, 0, 490, 240);
	road();
	
	circle(1.0, 1.0, 1.0, 1350, 0, 525, 275);
	circledotted(0.3, 0.3, 0.3, 1350, 0, 525, 275);
	rectangle(0.3, 0.3, 0.3, 1280, 250, 1420, 250, 1400, 300, 1300, 300);
	//car();
	glPushMatrix();
	glTranslatef(1350,-700,0);
	glRotatef(p, 0.0, 0.0, 1.0);
	glTranslatef(-1350,700,0);
	car();
	glPopMatrix();
	rectangle(0.0, 0.0, 0.0, 675, 240, 675, 0, 900, 0, 900, 240);
	//middleline
	lineDraw(1.0, 1.0, 1.0, 900, 950, 900, 0, 3.0);
	circleDraw(1.0, 1.0, 1.0, 700, 475, 30, 30);
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
		}
		if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
			glutDisplayFunc(display);
			glutIdleFunc(rotateMoon);
		}
}

void main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1800, 950);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Moon simulation");
	glutDisplayFunc(intro);
	glutMouseFunc(mouse);
	myInit();
	glutMainLoop();
}
