// C code to implement basic 
// transformations in OPENGL 
#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include <GL/glut.h> 
#include<iostream>
using namespace std;
// window size 
char title[] = "space table tennis";
/* Initialize OpenGL Graphics */
/*void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}*/
 
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
float z=-15.0f;
float a=-0.1;
float mouse_x=0.0f;
float mouse_y=0.0f;
float ball_x=0.0f;
float ball_y=0.0f;
float speed_x=0.1;
float speed_y=0.1;
int score=-20;
void Timer(int v) 
{ 
        z+=a;
        ball_x+=speed_x;
        ball_y+=speed_y;
        if(ball_x<=-7 || ball_x>=7)
        	speed_x*=-1;
        if(ball_y<=-4 || ball_y>=4)
        	speed_y*=-1;	
        glutTimerFunc(1,Timer,1); 
}
    
void display() {
    	glLineWidth(5);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
        glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
        
        // Render a color-cube consisting of 6 quads with different colors
        glLoadIdentity();                 // Reset the model-view matrix
        glTranslatef(0.0f, 0.0f, -20.0f);  // Move right and into the screen
        glColor4f(1, 1, 0,0.0f);
        
        /*glBegin(GL_LINE_LOOP);
            glVertex3f(-8,-5,0);
            glVertex3f(8,-5,0);
            glVertex3f(8,5,0);
            glVertex3f(-8,5,0);
        glEnd();*/
        glBegin(GL_LINE_LOOP);
            glVertex3f(-8,-5,5);
            glVertex3f(8,-5,5);
            glVertex3f(8,5,5);
            glVertex3f(-8,5,5);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glVertex3f(-8,-5,5);
            glVertex3f(8,-5,5);
            glVertex3f(8,-5,-10);
            glVertex3f(-8,-5,-10);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glVertex3f(-8,5,5);
            glVertex3f(8,5,5);
            glVertex3f(8,5,-10);
            glVertex3f(-8,5,-10);
        glEnd();
        /*glBegin(GL_LINE_LOOP);
            glVertex3f(-8,-5,-5);
            glVertex3f(8,-5,-5);
            glVertex3f(8,5,-5);
            glVertex3f(-8,5,-5);
        glEnd();*/
        glBegin(GL_LINE_LOOP);
            glVertex3f(-8,-5,-10);
            glVertex3f(8,-5,-10);
            glVertex3f(8,5,-10);
            glVertex3f(-8,5,-10);
        glEnd();
        glColor4f(1.0f, 0.0f, 0.0f,0.0f);
        glBegin(GL_LINE_LOOP);
            glVertex3f(-8,-5,20.0f+z);
            glVertex3f(8,-5,20.0f+z);
            glVertex3f(8,5,20.0f+z);
            glVertex3f(-8,5,20.0f+z);
        glEnd();
        /*glColor4f(0.0f, 0.0f, 1.0f,0.0f);
        //left face
        glBegin(GL_QUADS);
            glVertex3f(-8,-5,5);
            glVertex3f(-8,-5,-10);
            glVertex3f(-8,5,-10);
            glVertex3f(-8,5,5);
        glEnd();
        //right face
        glBegin(GL_QUADS);
            glVertex3f(8,-5,5);
            glVertex3f(8,-5,-10);
            glVertex3f(8,5,-10);
            glVertex3f(8,5,5);
        glEnd();
        glColor3f(1.0f, 0.0f, 0.0f);
        //top face
        glBegin(GL_QUADS);
            glVertex3f(-8,5,5);
            glVertex3f(8,5,5);
            glVertex3f(8,5,-10);
            glVertex3f(-8,5,-10);
        glEnd();
        //bottom face
        glBegin(GL_QUADS);
            glVertex3f(-8,-5,5);
            glVertex3f(8,-5,5);
            glVertex3f(8,-5,-10);
            glVertex3f(-8,-5,-10);
        glEnd();*/
        
        glTranslatef(0.0f, 0.0f, 20.0f);
    
    	if(z<-30.0f || z>-15.0f)
    		a*=-1;
    	glPushMatrix();
    	glTranslatef(ball_x, ball_y, z);
    	if(a!=0)
		glColor4f(0.96f,0.3f,0.45f,0.0f);
		else
		glColor4f(1,0,0,0.0f);
		glutSolidSphere(1,100,20);

	    glPopMatrix();
	    glTranslatef(0.0f, 0.0f, -20.0f);
	    glColor4f(0.36f, 0.86f, 0.58f,0.3f);
        glBegin(GL_QUADS);
            glVertex3f(-1.5f+mouse_x,-1.0f-mouse_y,5);
            glVertex3f(1.5f+mouse_x,-1.0f-mouse_y,5);
            glVertex3f(1.5f+mouse_x,1.0f-mouse_y,5);
            glVertex3f(-1.5f+mouse_x,1.0f-mouse_y,5);
        glEnd();
        char *c;
        char string [100];
        sprintf(string,"score : %d ",score);
		glPushMatrix();
		glColor4f(1, 1, 1,0);
		glTranslatef(-50, 35,-80.0f);
		glScalef(0.05,0.05,0.05);

		for (c=string; *c != '\0'; c++)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
		}
		glPopMatrix();
        glFlush();
	    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
	    
	    //cout<<z<<endl;
	    if(z>=-15.0f && a<0){
	    	if(ball_x>2.5f+mouse_x || ball_x<-2.5f+mouse_x || ball_y>2.0f-mouse_y || ball_y <-2.0f-mouse_y){
	    		a=0;
	    		speed_x=0;
	    		speed_y=0;
	    		//cout<<ball_x<<" "<<ball_y<<endl;
	    		//cout<<mouse_x<<" "<<mouse_y<<endl;
	    		
	    	}
	    	else{
	    		a*=1.1f;
	    		//speed_x*=1.05f;
	    		//speed_y*=1.05f;
	    		score+=10;
	    	}
	    }
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void mousepos(int x,int y){
	mouse_x=(((x-10)*16)/620.0f)-8;
	mouse_y=(((y-50)*10)/385.0f)-5;
	if(mouse_x>6.5)
		mouse_x=6.5;
	if(mouse_x<-6.5)
		mouse_x=-6.5;
	if(mouse_y>4)
		mouse_y=4;
	if(mouse_y<-4)
		mouse_y=-4;
	
	//cout<<mouse_x<<" "<<mouse_y<<endl;
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 3.0f, 5.0f, 1.0f, 0.0f }; 
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutIdleFunc(display);
   glutTimerFunc(1,Timer,1);
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutPassiveMotionFunc(mousepos);
   //initGL();                       // Our own OpenGL initialization
   glEnable(GL_CULL_FACE);
   glCullFace(GL_BACK); 
 
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS); 
 	glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);       
 	glBlendFunc  (GL_ONE_MINUS_SRC_ALPHA,GL_SRC_ALPHA);
	glEnable     (GL_BLEND);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
    glutMainLoop();                 // Enter the infinite event-processing loop
   
   return 0;
}
