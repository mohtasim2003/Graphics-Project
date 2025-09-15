#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <math.h>
#define PI        3.14159265358979323846


/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
        {
            glutBitmapCharacter(font, *c);
        }
}

///Day
GLfloat truck_Position = 0.0f;
GLfloat car_Position = 0.0f;
GLfloat cloud_Position = 0.0f;
GLfloat crane_Position = 0.0f;
GLfloat ship_Position = 0.0f;

///night
GLfloat night_cloudPosition = 0.0f;
GLfloat night_truckPosition = 0.0f;
GLfloat night_truck2Position = 0.0f;

///rain
GLfloat rain_cloud1Position = 0.0f;
GLfloat rain_cloud2Position = 0.0f;
GLfloat rain_cloud3Position = 0.0f;
GLfloat rain_cloud4Position = 0.0f;
GLfloat rain_Position = 0.0f;
GLfloat rain_ShipPosition = 0.0f;
GLfloat rain_wavePosition = 0.0f;
GLfloat rain2_Position = 0.0f;


void truckMove(int value)
{
    GLfloat truck_speed = 0.02f;

    if(truck_Position <-1.5)
        truck_Position = 0.03f;
    truck_Position -= truck_speed;

    glutPostRedisplay();
	glutTimerFunc(100, truckMove, 0);
}

void carMove(int value1)
{
    GLfloat car_speed = 0.03f;

    if(car_Position >0.95)
        car_Position = -1.5f;
    car_Position += car_speed;

    glutPostRedisplay();
	glutTimerFunc(100, carMove, 0);
}

void cloudMove(int value2)
{
    GLfloat cloud_speed = 0.002f;

    if(cloud_Position >1.9)
        cloud_Position = -1.0f;
    cloud_Position += cloud_speed;

    glutPostRedisplay();
	glutTimerFunc(100, cloudMove, 0);
}

void craneMove(int value3)
{
    GLfloat crane_speed = 0.001f;

    if(crane_Position >0.16)
        crane_Position = 0.02f;
    crane_Position += crane_speed;

    glutPostRedisplay();
	glutTimerFunc(100, craneMove, 0);
}

void shipMove(int value4)
{
    GLfloat ship_speed = 0.003f;

    if(ship_Position >1.16)
        ship_Position = 0.09f;
    ship_Position += ship_speed;

    glutPostRedisplay();
	glutTimerFunc(100, shipMove, 0);
}

void sun()
{
    int i;

	GLfloat x=0.85f; GLfloat y=0.85f; GLfloat radius =0.1f;
	int triangleAmount = 10000; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3ub(204, 134, 12);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++)
            {
                glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount)) );
            }
	glEnd();

	//glFlush();  // Render now
}

void cloud1()
{
            /// Smooth Cloud
    glColor3ub(255, 255, 255); // Set cloud color to white

    // Circle 1
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.8f, 0.8f); // Center of the circle
    for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.1416f * i / 100; // Angle in radians
            float x = cos(angle) * 0.1f; // Radius 0.1
            float y = sin(angle) * 0.1f;
            glVertex2f(-0.8f + x, 0.8f + y);
        }
    glEnd();

    // Circle 2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.75f, 0.85f); // Center of the circle
    for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.1416f * i / 100;
            float x = cos(angle) * 0.08f; // Radius 0.08
            float y = sin(angle) * 0.08f;
            glVertex2f(-0.75f + x, 0.85f + y);
        }
    glEnd();

    // Circle 3
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.85f, 0.85f); // Center of the circle
    for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.1416f * i / 100;
            float x = cos(angle) * 0.08f; // Radius 0.08
            float y = sin(angle) * 0.08f;
            glVertex2f(-0.85f + x, 0.85f + y);
        }
    glEnd();

    // Circle 4
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.8f, 0.87f); // Center of the circle
    for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.1416f * i / 100;
            float x = cos(angle) * 0.09f; // Radius 0.09
            float y = sin(angle) * 0.09f;
            glVertex2f(-0.8f + x, 0.87f + y);
        }
    glEnd();

}

void cloud2()
{
        /// Another Smooth Cloud in the Upper Left Corner
    glColor3ub(228, 235, 234); // Set cloud color to white

    // Circle 1 (Main body)
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.6f, 0.8f); // Center of the circle
    for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.1416f * i / 100; // Angle in radians
            float x = cos(angle) * 0.12f; // Radius 0.12
            float y = sin(angle) * 0.12f;
            glVertex2f(-0.6f + x, 0.8f + y);
        }
    glEnd();

    // Circle 2
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.65f, 0.85f); // Center of the circle
    for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.1416f * i / 100;
            float x = cos(angle) * 0.1f; // Radius 0.1
            float y = sin(angle) * 0.1f;
            glVertex2f(-0.65f + x, 0.85f + y);
        }
    glEnd();

    // Circle 3
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.55f, 0.85f); // Center of the circle
    for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.1416f * i / 100;
            float x = cos(angle) * 0.1f; // Radius 0.1
            float y = sin(angle) * 0.1f;
            glVertex2f(-0.55f + x, 0.85f + y);
        }
    glEnd();

    // Circle 4
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.7f, 0.8f); // Center of the circle
    for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.1416f * i / 100;
            float x = cos(angle) * 0.09f; // Radius 0.09
            float y = sin(angle) * 0.09f;
            glVertex2f(-0.7f + x, 0.8f + y);
        }
    glEnd();

    // Circle 5
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.5f, 0.8f); // Center of the circle
    for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.1416f * i / 100;
            float x = cos(angle) * 0.09f; // Radius 0.09
            float y = sin(angle) * 0.09f;
            glVertex2f(-0.5f + x, 0.8f + y);
        }
    glEnd();

}

 // Utility function to draw a circle
void drawCircle(float x, float y, float radius)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of the circle
    for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * M_PI * i / 100;
            float dx = radius * cosf(angle);
            float dy = radius * sinf(angle);
            glVertex2f(x + dx, y + dy);
        }
    glEnd();
}

void ship()
{
    //Body
    glBegin(GL_POLYGON);
    glColor3ub(156, 139, 106);
    glVertex2f(0.34f, -0.08f);
    glVertex2f(0.82f, -0.08f);
    glVertex2f(0.88f, -0.02f);
    glVertex2f(0.98f, -0.02f);
    glVertex2f(0.86f, -0.22f);
    glVertex2f(0.44f, -0.22f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.855f, -0.04f);
    glVertex2f(0.842f, -0.06f);
    glVertex2f(0.957f, -0.06f);
    glVertex2f(0.967f, -0.04f);
    glEnd();

    //2nd
    glBegin(GL_POLYGON);
    glColor3ub(247, 233, 205);
    glVertex2f(0.38f, -0.08f);
    glVertex2f(0.44f, 0.06f);
    glVertex2f(0.9f, 0.06f);
    glVertex2f(0.94f, -0.02f);
    glVertex2f(0.88f, -0.02f);
    glVertex2f(0.82f, -0.08f);
    glEnd();

    //3rd
    glBegin(GL_POLYGON);
    glColor3ub(214, 193, 152);
    glVertex2f(0.48f, 0.06f);
    glVertex2f(0.54f, 0.14f);
    glVertex2f(0.8f, 0.14f);
    glVertex2f(0.86f, 0.06f);
    glEnd();

    //4th
    glBegin(GL_POLYGON);
    glColor3ub(133, 117, 88);
    glVertex2f(0.58f, 0.14f);
    glVertex2f(0.56f, 0.26f);
    glVertex2f(0.64f, 0.26f);
    glVertex2f(0.7f, 0.14f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.57f, 0.2f);
    glVertex2f(0.565f, 0.22f);
    glVertex2f(0.66f, 0.22f);
    glVertex2f(0.669f, 0.2f);
    glEnd();


    ///O O O O
    glColor3ub(181, 226, 245);
    drawCircle(0.48f, -0.145f, 0.025f);
    drawCircle(0.58f, -0.145f, 0.025f);
    drawCircle(0.68f, -0.145f, 0.025f);
    drawCircle(0.78f, -0.145f, 0.025f);


    //Window
    glBegin(GL_QUADS);
    glVertex2f(0.46f, 0.02f);
    glVertex2f(0.46f, -0.04f);
    glVertex2f(0.78f, -0.04f);
    glVertex2f(0.78f, 0.02f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.46f, 0.02f);
    glVertex2f(0.46f, -0.04f);
    glVertex2f(0.46f, -0.04f);
    glVertex2f(0.78f, -0.04f);
    glVertex2f(0.78f, 0.02f);
    glVertex2f(0.46f, 0.02f);
    glVertex2f(0.78f, -0.04f);
    glVertex2f(0.78f, 0.02f);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.54f, 0.02f);
    glVertex2f(0.54f, -0.04f);

    glVertex2f(0.62f, 0.02f);
    glVertex2f(0.62f, -0.04f);

    glVertex2f(0.70f, 0.02f);
    glVertex2f(0.70f, -0.04f);
    glEnd();

    //boder
    glBegin(GL_LINE_STRIP);
    glColor3ub(0, 0, 0);
    glVertex2f(0.34f, -0.08f);
    glVertex2f(0.82f, -0.08f);
    glVertex2f(0.88f, -0.02f);
    glVertex2f(0.98f, -0.02f);
    glVertex2f(0.86f, -0.22f);
    glVertex2f(0.44f, -0.22f);
    glVertex2f(0.34f, -0.08f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(0, 0, 0);
    glVertex2f(0.38f, -0.08f);
    glVertex2f(0.44f, 0.06f);
    glVertex2f(0.9f, 0.06f);
    glVertex2f(0.94f, -0.02f);
    glVertex2f(0.88f, -0.02f);
    glVertex2f(0.82f, -0.08f);
    glVertex2f(0.38f, -0.08f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(0, 0, 0);
    glVertex2f(0.48f, 0.06f);
    glVertex2f(0.54f, 0.14f);
    glVertex2f(0.8f, 0.14f);
    glVertex2f(0.86f, 0.06f);
    glVertex2f(0.48f, 0.06f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(0, 0, 0);
    glVertex2f(0.58f, 0.14f);
    glVertex2f(0.56f, 0.26f);
    glVertex2f(0.64f, 0.26f);
    glVertex2f(0.7f, 0.14f);
    glVertex2f(0.58f, 0.14f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(0, 0, 0);
    glVertex2f(0.57f, 0.2f);
    glVertex2f(0.565f, 0.22f);
    glVertex2f(0.66f, 0.22f);
    glVertex2f(0.669f, 0.2f);
    glVertex2f(0.57f, 0.2f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(0, 0, 0);
    glVertex2f(0.855f, -0.04f);
    glVertex2f(0.842f, -0.06f);
    glVertex2f(0.957f, -0.06f);
    glVertex2f(0.967f, -0.04f);
    glVertex2f(0.855f, -0.04f);
    glEnd();


}

void smallContainer()
{
    //left
    glBegin(GL_QUADS);
    glColor3ub(89, 25, 5);
    glVertex2f(-0.995f, 0.1f);
    glVertex2f(-0.995f, 0.2f);
    glVertex2f(-0.8f, 0.2f);
    glVertex2f(-0.8f, 0.1f);
    glEnd();

    glColor3ub(245, 233, 10);
    renderBitmapString(-0.92f, 0.15f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "MAERSK");

    glBegin(GL_QUADS);
    glColor3ub(33, 17, 64);
    glVertex2f(-0.995f, 0.2f);
    glVertex2f(-0.995f, 0.3f);
    glVertex2f(-0.8f, 0.3f);
    glVertex2f(-0.8f, 0.2f);
    glEnd();

    glColor3ub(249, 250, 245);
    renderBitmapString(-0.94f, 0.24f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "EVERGREEN");

    //middle
    glBegin(GL_QUADS);
    glColor3ub(27, 24, 33);
    glVertex2f(-0.79f, 0.1f);
    glVertex2f(-0.79f, 0.2f);
    glVertex2f(-0.60f, 0.2f);
    glVertex2f(-0.60f, 0.1f);
    glEnd();

    glColor3ub(249, 250, 245);
    renderBitmapString(-0.73f, 0.14f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "HIGH CUBES");

    glBegin(GL_QUADS);
    glColor3ub(8, 118, 128);
    glVertex2f(-0.79f, 0.2f);
    glVertex2f(-0.79f, 0.3f);
    glVertex2f(-0.60f, 0.3f);
    glVertex2f(-0.60f, 0.2f);
    glEnd();

    glColor3ub(0, 0, 0);
    renderBitmapString(-0.75f, 0.24f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "DESH  TRAVELS");


    //right
    glBegin(GL_QUADS);
    glColor3ub(105, 17, 24);
    glVertex2f(-0.59f, 0.1f);
    glVertex2f(-0.59f, 0.2f);
    glVertex2f(-0.40f, 0.2f);
    glVertex2f(-0.40f, 0.1f);
    glEnd();

    glColor3ub(5, 120, 118);
    renderBitmapString(-0.53f, 0.14f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "GREEN  LINE");

    glBegin(GL_QUADS);
    glColor3ub(85, 89, 4);
    glVertex2f(-0.59f, 0.2f);
    glVertex2f(-0.59f, 0.3f);
    glVertex2f(-0.40f, 0.3f);
    glVertex2f(-0.40f, 0.2f);
    glEnd();

    glColor3ub(105, 6, 95);
    renderBitmapString(-0.55f, 0.24f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "SHOHAG SCANIA");

    ///Y-axis
    glBegin(GL_QUADS);
    glColor3ub(8, 71, 6);
    glVertex2f(-0.995f, 0.33f);
    glVertex2f(-0.995f, 0.5f);
    glVertex2f(-0.95f, 0.5f);
    glVertex2f(-0.95f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(84, 99, 8);
    glVertex2f(-0.945f, 0.33f);
    glVertex2f(-0.945f, 0.5f);
    glVertex2f(-0.90f, 0.5f);
    glVertex2f(-0.90f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(59, 5, 99);
    glVertex2f(-0.895f, 0.33f);
    glVertex2f(-0.895f, 0.5f);
    glVertex2f(-0.85f, 0.5f);
    glVertex2f(-0.85f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(79, 120, 12);
    glVertex2f(-0.845f, 0.33f);
    glVertex2f(-0.845f, 0.5f);
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(-0.8f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(217, 122, 7);
    glVertex2f(-0.795f, 0.33f);
    glVertex2f(-0.795f, 0.5f);
    glVertex2f(-0.75f, 0.5f);
    glVertex2f(-0.75f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(43, 38, 32);
    glVertex2f(-0.745f, 0.33f);
    glVertex2f(-0.745f, 0.5f);
    glVertex2f(-0.7f, 0.5f);
    glVertex2f(-0.7f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(36, 6, 4);
    glVertex2f(-0.695f, 0.33f);
    glVertex2f(-0.695f, 0.5f);
    glVertex2f(-0.65f, 0.5f);
    glVertex2f(-0.65f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(4, 75, 89);
    glVertex2f(-0.645f, 0.33f);
    glVertex2f(-0.645f, 0.5f);
    glVertex2f(-0.6f, 0.5f);
    glVertex2f(-0.6f, 0.33f);
    glEnd();

    //up
    glBegin(GL_QUADS);
    glColor3ub(7, 68, 110);
    glVertex2f(-0.9225f, 0.35f);
    glVertex2f(-0.9225f, 0.44f);
    glVertex2f(-0.8225f, 0.44f);
    glVertex2f(-0.8225f, 0.35f);
    glEnd();

}


void drawCar()
{
    // Car Body
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0); // Red color
    glVertex2f(-0.4f, -0.65f);
    glVertex2f(-0.1f, -0.65f);
    glVertex2f(-0.1f, -0.55f);
    glVertex2f(-0.4f, -0.55f);
    glEnd();

    // Car Roof
    glBegin(GL_QUADS);
    glColor3ub(200, 0, 0); // Darker red
    glVertex2f(-0.35f, -0.55f);
    glVertex2f(-0.15f, -0.55f);
    glVertex2f(-0.2f, -0.48f);
    glVertex2f(-0.3f, -0.48f);
    glEnd();

    // Front Wheel
    glColor3ub(0, 0, 0); // Black color
    drawCircle(-0.35f, -0.67f, 0.04f); // Left wheel
    drawCircle(-0.15f, -0.67f, 0.04f); // Right wheel

    // Window
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 235); // Light blue for the window
    glVertex2f(-0.32f, -0.55f);
    glVertex2f(-0.18f, -0.55f);
    glVertex2f(-0.22f, -0.49f);
    glVertex2f(-0.28f, -0.49f);
    glEnd();
}

void drawCar2()
{
    // Car Body
    glBegin(GL_QUADS);
    glColor3ub(171, 129, 14);
    glVertex2f(-1.0f, -0.78f); // Left side of the car, just below the road divider
    glVertex2f(-0.7f, -0.78f);
    glVertex2f(-0.7f, -0.88f);  // Bottom of the car, below the road divider
    glVertex2f(-1.0f, -0.88f);
    glEnd();

    glColor3ub(16, 11, 48);
    renderBitmapString(-0.935f, -0.84f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Customs Office");

    // Car Roof
    glBegin(GL_QUADS);
    glColor3ub(138, 103, 10); // Darker blue
    glVertex2f(-0.95f, -0.78f); // Left side of the roof, aligned with the car body
    glVertex2f(-0.75f, -0.78f);
    glVertex2f(-0.8f, -0.71f);  // Roof sloped downwards
    glVertex2f(-0.9f, -0.71f);
    glEnd();

    // Front Wheel
    glColor3ub(0, 0, 0); // Black color
    drawCircle(-0.95f, -0.91f, 0.04f); // Left wheel, just below the car body
    drawCircle(-0.75f, -0.91f, 0.04f); // Right wheel, just below the car body

    // Window
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 235); // Light blue for the window
    glVertex2f(-0.92f, -0.78f); // Left side of the window
    glVertex2f(-0.78f, -0.78f); // Right side of the window
    glVertex2f(-0.83f, -0.71f); // Bottom-right corner of the window
    glVertex2f(-0.87f, -0.71f); // Bottom-left corner of the window
    glEnd();

}


void Day_sky()
{
     /// Sky
    glBegin(GL_POLYGON);
    glColor3ub(58, 139, 232);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.8f, 0.57f);
    glVertex2f(-0.6f, 0.54f);
    glVertex2f(-0.4f, 0.46f);
    glVertex2f(-0.1f, 0.3f);
    glVertex2f(0.0f, 0.06f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.4f, -0.02f);
    glVertex2f(0.6f, -0.1f);
    glVertex2f(0.8f, -0.2f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
}

void Floor()
{
    /// Floor
    glBegin(GL_POLYGON);
    glColor3ub(158, 156, 149);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.8f, 0.57f);
    glVertex2f(-0.6f, 0.54f);
    glVertex2f(-0.4f, 0.46f);
    glVertex2f(-0.1f, 0.3f);
    glVertex2f(0.0f, 0.06f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.4f, -0.02f);
    glVertex2f(0.6f, -0.1f);
    glVertex2f(0.8f, -0.2f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
}

void sea()
{
    /// Sea
    glBegin(GL_POLYGON);
    glColor3ub(7, 106, 219);
    glVertex2f(-0.1f, 0.3f);
    glVertex2f(0.1f, 0.4f);
    glVertex2f(0.3f, 0.48f);
    glVertex2f(0.5f, 0.52f);
    glVertex2f(0.6f, 0.5f);
    glVertex2f(0.8f, 0.40f);
    glVertex2f(1.0f, 0.38f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(0.9f, -1.0f);
    glVertex2f(0.8f, -0.7f);
    glVertex2f(0.78f, -0.6f);
    glVertex2f(0.72f, -0.54f);
    glVertex2f(0.7f, -0.40f);
    glVertex2f(0.6f, -0.28f);
    glVertex2f(0.4f, -0.26f);
    glVertex2f(0.24f, -0.2f);
    glVertex2f(0.3f, -0.12f);
    glVertex2f(0.3f, -0.12f);
    glVertex2f(0.26f, 0.1f);
    glVertex2f(0.0f, 0.06f);
    glVertex2f(-0.1f, 0.3f);
    glEnd();

    ///Layer
    glBegin(GL_POLYGON);
    glColor3ub(219, 216, 149);
    glVertex2f(-0.1f, 0.3f);
    glVertex2f(0.0f, 0.06f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.26f, -0.1f);
    glVertex2f(0.30f, -0.12f);
    glVertex2f(0.24f, -0.2f);
    glVertex2f(0.4f, -0.26f);
    glVertex2f(0.6f, -0.28f);
    glVertex2f(0.7f, -0.4f);
    glVertex2f(0.72f, -0.54f);
    glVertex2f(0.78f, -0.6f);
    glVertex2f(0.8f, -0.7f);
    glVertex2f(0.9f, -1.0f);
    glVertex2f(0.89f, -1.0f);
    glVertex2f(0.79f, -0.7f);
    glVertex2f(0.77f, -0.6f);
    glVertex2f(0.71f, -0.54f);
    glVertex2f(0.69f, -0.4f);
    glVertex2f(0.59f, -0.28f);
    glVertex2f(0.39f, -0.26f);
    glVertex2f(0.23f, -0.20f);
    glVertex2f(0.29f, -0.12f);
    glVertex2f(0.25f, -0.1f);
    glVertex2f(0.19f, -0.01f);
    glVertex2f(-0.01f, 0.05f);
    glVertex2f(-0.09f, 0.3f);

    glEnd();
}

void crane()
{
    ///Crane
    glBegin(GL_QUADS);
    glColor3ub(176, 9, 20);
    glVertex2f(0.34f, 0.3f);
    glVertex2f(0.4f, 0.30f);
    glVertex2f(0.4f, -0.9f);
    glVertex2f(0.34f, -0.9f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.68f, 0.3f);
    glVertex2f(0.74f, 0.30f);
    glVertex2f(0.74f, -0.9f);
    glVertex2f(0.68f, -0.9f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.34f, 0.3f);
    glVertex2f(0.4f, 0.30f);
    glVertex2f(0.54f, 0.46f);
    glVertex2f(0.54f, 0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.68f, 0.3f);
    glVertex2f(0.74f, 0.30f);
    glVertex2f(0.54f, 0.5f);
    glVertex2f(0.54f, 0.46f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.15f, 0.1f);
    glVertex2f(-0.15f, 0.02f);
    glVertex2f(0.85f, 0.02f);
    glVertex2f(0.85f, 0.10f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.1f, 0.08f);
    glVertex2f(0.54f, 0.5f);
    glEnd();

    ///"Z"
    glBegin(GL_QUADS);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.4f, -0.14f);
    glVertex2f(0.68f, -0.14f);
    glVertex2f(0.68f, -0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.4f, -0.5f);
    glVertex2f(0.4f, -0.54f);
    glVertex2f(0.68f, -0.54f);
    glVertex2f(0.68f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.4f, -0.5f);
    glVertex2f(0.68f, -0.14f);
    glVertex2f(0.68f, -0.15f);
    glVertex2f(0.41f, -0.5f);
    glEnd();


    glPushMatrix();
    glTranslatef(crane_Position,0.0f, 0.0f);
    ///hunger
    glBegin(GL_QUADS);
    glVertex2f(-0.13f, 0.02f);
    glVertex2f(-0.13f, -0.06f);
    glVertex2f(-0.12f, -0.06f);
    glVertex2f(-0.12f, 0.02f);
    glEnd();
    glPopMatrix();

    glColor3ub(245, 233, 10);
    renderBitmapString(0.43f, 0.045f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Port of Chittagong");
}

void Road()
{
    ///Road
    glBegin(GL_QUADS);
    glColor3ub(43, 40, 29);
    glVertex2f(0.25f, -0.5f);
    glVertex2f(0.25f, -0.99f);
    glVertex2f(-1.0f, -0.99f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();

    ///Road sideUP
    glBegin(GL_QUADS);
    glColor3ub(225, 227, 227);
    glVertex2f(0.25f, -0.51f);
    glVertex2f(0.25f, -0.53f);
    glVertex2f(-1.0f, -0.53f);
    glVertex2f(-1.0f, -0.51f);
    glEnd();

    ///Road sideDown
    glBegin(GL_QUADS);
    glColor3ub(225, 227, 227);
    glVertex2f(0.25f, -0.98f);
    glVertex2f(0.25f, -0.96f);
    glVertex2f(-1.0f, -0.96f);
    glVertex2f(-1.0f, -0.98f);
    glEnd();

    // Road Divider
    glColor3ub(255, 255, 0);

    // First Dash
    glBegin(GL_QUADS);
    glVertex2f(-0.9f, -0.75f);
    glVertex2f(-0.8f, -0.75f);
    glVertex2f(-0.8f, -0.78f);
    glVertex2f(-0.9f, -0.78f);
    glEnd();

    // Second Dash
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, -0.75f);
    glVertex2f(-0.5f, -0.75f);
    glVertex2f(-0.5f, -0.78f);
    glVertex2f(-0.6f, -0.78f);
    glEnd();

    // Third Dash
    glBegin(GL_QUADS);
    glVertex2f(-0.3f, -0.75f);
    glVertex2f(-0.2f, -0.75f);
    glVertex2f(-0.2f, -0.78f);
    glVertex2f(-0.3f, -0.78f);
    glEnd();

    // Fourth Dash
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -0.75f);
    glVertex2f(0.1f, -0.75f);
    glVertex2f(0.1f, -0.78f);
    glVertex2f(0.0f, -0.78f);
    glEnd();


}

void Lamp()
{
    ///Lamp
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.20f, -0.5f);
    glVertex2f(0.20f, -0.3f);
    glVertex2f(0.21f, -0.3f);
    glVertex2f(0.21f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.20f, -0.3f);
    glVertex2f(0.16f, -0.3f);
    glVertex2f(0.16f, -0.32f);
    glVertex2f(0.20f, -0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.13f, -0.3f);
    glVertex2f(0.16f, -0.3f);
    glVertex2f(0.16f, -0.325f);
    glVertex2f(0.13f, -0.325f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.20f, -0.3f);
    glVertex2f(0.13f, -0.3f);
    glVertex2f(0.13f, -0.31f);
    glVertex2f(0.20f, -0.31f);
    glEnd();
}

void Container()
{
    ///Container
    //Left
    glBegin(GL_QUADS);
    glColor3ub(19, 26, 237);
    glVertex2f(-0.995f, -0.3f);
    glVertex2f(-0.7f, -0.3f);
    glVertex2f(-0.7f, -0.48f);
    glVertex2f(-0.995f, -0.48f);
    glEnd();

    glColor3ub(245, 233, 10);
    renderBitmapString(-0.92f, -0.41f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "FERRARI");

    glBegin(GL_QUADS);
    glColor3ub(227, 102, 30);
    glVertex2f(-0.995f, -0.3f);
    glVertex2f(-0.7f, -0.3f);
    glVertex2f(-0.7f, -0.12f);
    glVertex2f(-0.995f, -0.12f);
    glEnd();

    glColor3ub(13, 13, 20);
    renderBitmapString(-0.94f, -0.23f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "MARCEDES");

    glBegin(GL_QUADS);
    glColor3ub(209, 14, 10);
    glVertex2f(-0.995f, 0.06f);
    glVertex2f(-0.7f, 0.06f);
    glVertex2f(-0.7f, -0.12f);
    glVertex2f(-0.995f, -0.12f);
    glEnd();

    glColor3ub(235, 176, 16);
    renderBitmapString(-0.96f, -0.05f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "ROLLS-ROYCE ");

    //Right
    glBegin(GL_QUADS);
    glColor3ub(94, 48, 8);
    glVertex2f(-0.69f, -0.3f);
    glVertex2f(-0.69f, -0.48f);
    glVertex2f(-0.4f, -0.48f);
    glVertex2f(-0.4f, -0.3f);
    glEnd();

    glColor3ub(237, 237, 242);
    renderBitmapString(-0.62f, -0.41f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "BENTLEY");

    glBegin(GL_QUADS);
    glColor3ub(32, 140, 41);
    glVertex2f(-0.69f, -0.3f);
    glVertex2f(-0.69f, -0.12f);
    glVertex2f(-0.4f, -0.12f);
    glVertex2f(-0.4f, -0.3f);
    glEnd();

    glColor3ub(173, 7, 7);
    renderBitmapString(-0.66f, -0.23f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "LAMBORGHINI");

    glBegin(GL_QUADS);
    glColor3ub(138, 61, 156);
    glVertex2f(-0.69f, 0.06f);
    glVertex2f(-0.69f, -0.12f);
    glVertex2f(-0.4f, -0.12f);
    glVertex2f(-0.4f, 0.06f);
    glEnd();


    glColor3ub(10, 9, 41);
    renderBitmapString(-0.61f, -0.05f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "PORSCHE");


    glPushMatrix();
    glTranslatef(crane_Position,0.0f, 0.0f);
    ///hanging
    glBegin(GL_QUADS);
    glColor3ub(54, 5, 29);
    glVertex2f(-0.24f, -0.06f);
    glVertex2f(-0.02f, -0.06f);
    glVertex2f(-0.02f, -0.14f);
    glVertex2f(-0.24f, -0.14f);
    glEnd();


    glColor3ub(201, 245, 5);
    renderBitmapString(-0.16f, -0.11f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "BUGATTI");
    glPopMatrix();


    ///under_Crane
    glBegin(GL_QUADS);
    glColor3ub(79, 54, 9);
    glVertex2f(0.48f, -0.95f);
    glVertex2f(0.48f, -0.65f);
    glVertex2f(0.60f, -0.65f);
    glVertex2f(0.60f, -0.95f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(227, 58, 16);
    glVertex2f(0.50f, -0.93f);
    glVertex2f(0.50f, -0.63f);
    glVertex2f(0.60f, -0.63f);
    glVertex2f(0.60f, -0.93f);
    glEnd();

    glColor3ub(201, 245, 5);
    renderBitmapString(0.519f, -0.79f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "CONTROL");
    renderBitmapString(0.529f, -0.82f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "ROOM");
}

void Truck()
{
    //container
    glBegin(GL_QUADS);
    glColor3ub(98, 102, 45);
    glVertex2f(-0.1f, -0.2f);
    glVertex2f(-0.1f, -0.34f);
    glVertex2f(0.15f, -0.34f);
    glVertex2f(0.15f, -0.2f);
    glEnd();

    glColor3ub(245, 233, 10);
    renderBitmapString(-0.006f, -0.3f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "BMW");

    glBegin(GL_QUADS);
    glColor3ub(71, 74, 33);
    glVertex2f(-0.1f, -0.36f);
    glVertex2f(-0.1f, -0.34f);
    glVertex2f(0.15f, -0.34f);
    glVertex2f(0.15f, -0.36f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.22f, -0.36f);
    glVertex2f(-0.22f, -0.4f);
    glVertex2f(0.15f, -0.4f);
    glVertex2f(0.15f, -0.36f);
    glEnd();

    ///font
    glBegin(GL_POLYGON);
    glColor3ub(176, 45, 33);
    glVertex2f(-0.115f, -0.16f);
    glVertex2f(-0.24f, -0.16f);
    glVertex2f(-0.26f, -0.22f);
    glVertex2f(-0.32f, -0.26f);
    glVertex2f(-0.32f, -0.4f);
    glVertex2f(-0.34f, -0.41f);
    glVertex2f(-0.22f, -0.41f);
    glVertex2f(-0.22f, -0.36f);
    glVertex2f(-0.115f, -0.36f);
    glVertex2f(-0.115f, -0.34f);
    glVertex2f(-0.115f, -0.33f);
    glVertex2f(-0.115f, -0.32f);
    glVertex2f(-0.115f, -0.15f);
    glEnd();

    //window
    glBegin(GL_QUADS);
    glColor3ub(186, 38, 24);
    glVertex2f(-0.26f, -0.24f);
    glVertex2f(-0.26f, -0.3f);
    glVertex2f(-0.16f, -0.3f);
    glVertex2f(-0.16f, -0.24f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(-0.26f, -0.24f);
    glVertex2f(-0.23f, -0.18f);
    glVertex2f(-0.16f, -0.18f);
    glVertex2f(-0.16f, -0.24f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.23f, -0.18f);
    glVertex2f(-0.23f, -0.24f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.17f, -0.25f);
    glVertex2f(-0.17f, -0.26f);
    glVertex2f(-0.19f, -0.26f);
    glVertex2f(-0.19f, -0.25f);
    glEnd();

    //fuel
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.11f, -0.4f);
    glVertex2f(-0.11f, -0.43f);
    glVertex2f(-0.0f, -0.43f);
    glVertex2f(-0.0f, -0.4f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    renderBitmapString(-0.065f, -0.42f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "Fuel");



    glColor3ub(0, 0, 0); // Black color
    drawCircle(0.07f, -0.415f, 0.04f); // Back wheel
    drawCircle(-0.17f, -0.415f, 0.04f); // front wheel
}


void Truck_onRoad()
{
    glPushMatrix();
    glTranslatef(truck_Position,0.0f, 0.0f);

    ///Back
    glBegin(GL_QUADS);
    glColor3ub(40, 57, 84);
    glVertex2f(0.24f, -0.54f);
    glVertex2f(-0.06f, -0.54f);
    glVertex2f(-0.06f, -0.68f);
    glVertex2f(0.24f, -0.68f);
    glEnd();

    glColor3ub(184, 245, 234);
    renderBitmapString(-0.0f, -0.62f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "CONTAINER");

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.24f, -0.7f);
    glVertex2f(0.24f, -0.68f);
    glVertex2f(-0.09f, -0.68f);
    glVertex2f(-0.09f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30, 44, 66);
    glVertex2f(0.24f, -0.66f);
    glVertex2f(0.24f, -0.68f);
    glVertex2f(-0.06f, -0.68f);
    glVertex2f(-0.06f, -0.66f);
    glEnd();

    //font
    glBegin(GL_POLYGON);
    glColor3ub(166, 13, 16);
    glVertex2f(-0.07f, -0.6f);
    glVertex2f(-0.07f, -0.54f);
    glVertex2f(-0.14f, -0.54f);
    glVertex2f(-0.17f, -0.6f);
    glVertex2f(-0.21f, -0.61f);
    glVertex2f(-0.21f, -0.62f);
    glVertex2f(-0.21f, -0.68f);
    glVertex2f(-0.22f, -0.7f);
    glVertex2f(-0.145f, -0.7f);
    glVertex2f(-0.145f, -0.68f);
    glVertex2f(-0.07f, -0.68f);
    glEnd();


    //window
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex2f(-0.09f, -0.56f);
    glVertex2f(-0.09f, -0.61f);
    glVertex2f(-0.13f, -0.61f);
    glVertex2f(-0.13f, -0.56f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(135, 206, 235);
    glVertex2f(-0.13f, -0.61f);
    glVertex2f(-0.13f, -0.56f);
    glVertex2f(-0.16f, -0.61f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.13f, -0.56f);
    glVertex2f(-0.13f, -0.61f);
    glEnd();



    glColor3ub(0, 0, 0); // Black color
    drawCircle(0.15f, -0.705f, 0.03f); // Back wheel
    drawCircle(-0.11f, -0.705f, 0.03f); // front wheel

     glPopMatrix();
}

void writting()
{
    glColor3ub(14, 5, 97);
    renderBitmapString(-0.35f, 0.8f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "AMERICAN INTERNATIONAL UNIVERSITY-BANGLADESH");

    glColor3ub(14, 5, 97);
    renderBitmapString(-0.21f, 0.7f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "FACULTY OF SCIENCE & TECHNOLOGY");
    renderBitmapString(-0.065f, 0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "COMUTER GRAPHICS");
    renderBitmapString(-0.01f, 0.5f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "FALL 2024-2025");
    glColor3ub(0,0,0);
    renderBitmapString(0.045f, 0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Section: E");
    renderBitmapString(0.043f, 0.28f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Submitted To");
    renderBitmapString(-0.05f, 0.2f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "MAHFUJUR RAHMAN");
    renderBitmapString(0.043f, 0.08f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Submitted By");

    ///1st Line
    ///X-axis
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.35f, 0.04f);
    glVertex2f(0.5f, 0.04f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.35f, -0.04f);
    glVertex2f(0.5f, -0.04f);

    glVertex2f(-0.35f, -0.14f);
    glVertex2f(0.5f, -0.14f);

    glVertex2f(-0.35f, -0.24f);
    glVertex2f(0.5f, -0.24f);

    glVertex2f(-0.35f, -0.34f);
    glVertex2f(0.5f, -0.34f);

    glVertex2f(-0.35f, -0.44f);
    glVertex2f(0.5f, -0.44f);

    glVertex2f(-0.35f, -0.54f);
    glVertex2f(0.5f, -0.54f);

    ///Y-axis
    glVertex2f(-0.35f, 0.04f);
    glVertex2f(-0.35f, -0.54f);

    glVertex2f(-0.035f, 0.04f);
    glVertex2f(-0.035f, -0.54f);

    glVertex2f(0.135f, 0.04f);
    glVertex2f(0.135f, -0.54f);

    glVertex2f(0.19f, 0.04f);
    glVertex2f(0.19f, -0.54f);

    glVertex2f(0.5f, 0.04f);
    glVertex2f(0.5f, -0.54f);

    glEnd();


    renderBitmapString(-0.22f, -0.009f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Name");
    renderBitmapString(0.04f, -0.009f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ID");
    renderBitmapString(0.15f, -0.009f, 0.0f, GLUT_BITMAP_HELVETICA_18, "SL");
    renderBitmapString(0.27f, -0.009f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Contribution");

    renderBitmapString(-0.34f, -0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18, "MOHTASIM-UR-RAHMAN");
    renderBitmapString(-0.34f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_18, "SHIMU, SUMAIYA AKTER");
    renderBitmapString(-0.34f, -0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "SHAKIL, RAKIBUL HASAN");
    renderBitmapString(-0.34f, -0.4f, 0.0f, GLUT_BITMAP_HELVETICA_18, "MD.SIAM-UL ISLAM");
    renderBitmapString(-0.34f, -0.5f, 0.0f, GLUT_BITMAP_HELVETICA_18, "MD. SALMAN FARSHI");

    renderBitmapString(-0.01f, -0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18, "22-49461-3");
    renderBitmapString(-0.01f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_18, "22-48668-3");
    renderBitmapString(-0.01f, -0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "22-49462-3");
    renderBitmapString(-0.01f, -0.4f, 0.0f, GLUT_BITMAP_HELVETICA_18, "22-49466-3");
    renderBitmapString(-0.01f, -0.5f, 0.0f, GLUT_BITMAP_HELVETICA_18, "22-49306-3");

    renderBitmapString(0.15f, -0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18, "36");
    renderBitmapString(0.15f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_18, "27");
    renderBitmapString(0.15f, -0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "37");
    renderBitmapString(0.15f, -0.4f, 0.0f, GLUT_BITMAP_HELVETICA_18, "38");
    renderBitmapString(0.15f, -0.5f, 0.0f, GLUT_BITMAP_HELVETICA_18, "32");

    renderBitmapString(0.32f, -0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18, "25%");
    renderBitmapString(0.32f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_18, "20%");
    renderBitmapString(0.32f, -0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "20%");
    renderBitmapString(0.32f, -0.4f, 0.0f, GLUT_BITMAP_HELVETICA_18, "20%");
    renderBitmapString(0.32f, -0.5f, 0.0f, GLUT_BITMAP_HELVETICA_18, "15%");


    renderBitmapString(-0.09f, -0.65f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Date of Submission:  22 Jan, 2025");


}

///Cover Page
void cover_page()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f ); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glLoadIdentity();

    writting();

    glFlush(); // Render now
}


void nightCloudMove(int value5)
{
    GLfloat nightcloud_speed = 0.003f;

    if(night_cloudPosition >1.9)
        night_cloudPosition = -1.0f;
    night_cloudPosition += nightcloud_speed;

    glutPostRedisplay();
	glutTimerFunc(100, nightCloudMove, 0);
}


void nighttruckMove(int value6)
{
    GLfloat nighttruck_speed = 0.02f;

    if(night_truckPosition >1.6)
        night_truckPosition = -0.35f;
    night_truckPosition += nighttruck_speed;

    glutPostRedisplay();
	glutTimerFunc(100, nighttruckMove, 0);
}

void nighttruck2Move(int value7)
{
    GLfloat nighttruck2_speed = 0.01f;

    if(night_truck2Position <-1.5)
        night_truck2Position = 0.3f;
    night_truck2Position -= nighttruck2_speed;

    glutPostRedisplay();
	glutTimerFunc(100, nighttruck2Move, 0);
}

void draw_circle(float x, float y, float radius)
{
    int triangleAmount = 100; // The number of triangles to approximate the circle
    float twicePi = 2.0f * 3.14159265358979323846;

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}


void moon()
{
    int i;

	GLfloat x=0.88f; GLfloat y=0.85f; GLfloat radius =0.05f;
	int triangleAmount = 10000; //# of lines used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3ub(255, 255, 255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();

	glFlush();  // Render now
}

void night_sky()
{
        /// Night_Sky
    glBegin(GL_POLYGON);
    glColor3ub(6, 35, 140);
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(-0.4f, 0.44f);
    glVertex2f(0.1f, 0.38f);
    glVertex2f(0.6f, 0.5f);
    glVertex2f(0.6f, 1.0f);
    glVertex2f(1.0f, 0.5f);
    glVertex2f(1.0f, 1.0f);

    glVertex2f(-1.0f, 1.0f);




    glEnd();
}
void night_star()
{
     glPointSize(4.0f); // Set the size of the stars
glBegin(GL_POINTS);
glColor3ub(255, 255, 255); // White color for the stars

// Specify coordinates for stars
glVertex2f(-0.9f, 0.8f);
glVertex2f(-0.7f, 0.9f);
glVertex2f(-0.5f, 0.85f);
glVertex2f(-0.3f, 0.75f);
glVertex2f(-0.1f, 0.9f);
glVertex2f(0.2f, 0.85f);
glVertex2f(0.4f, 0.8f);
glVertex2f(0.6f, 0.9f);
glVertex2f(0.8f, 0.85f);
glVertex2f(0.9f, 0.75f);

// Additional stars
glVertex2f(-0.95f, 0.95f);
glVertex2f(-0.85f, 0.7f);
glVertex2f(-0.65f, 0.95f);
glVertex2f(-0.45f, 0.92f);
glVertex2f(-0.25f, 0.88f);
glVertex2f(0.0f, 0.92f);
glVertex2f(0.15f, 0.75f);
glVertex2f(0.35f, 0.92f);
glVertex2f(0.55f, 0.88f);
glVertex2f(0.75f, 0.92f);
glVertex2f(0.95f, 0.88f);

glEnd();


}

void night_cloud()
{
    glColor3ub(200, 200, 200); // Light gray
    draw_circle(-0.5f, 0.7f, 0.08f); // Main circle
    //draw_circle(-0.6f, 0.72f, 0.06f); // Left circle
    draw_circle(-0.4f, 0.72f, 0.06f); // Right circle
    draw_circle(-0.55f, 0.65f, 0.05f); // Bottom left circle
    draw_circle(-0.45f, 0.65f, 0.05f); // Bottom right circle
}

void night_floor()
{

     glBegin(GL_POLYGON);
    glColor3ub(75, 77, 76);
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(-0.4f, 0.44f);
    glVertex2f(0.1f, 0.38f);
    glVertex2f(0.6f, 0.5f);
    glVertex2f(0.6f, 1.0f);
    glVertex2f(1.0f, 0.5f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);

    glEnd();
}


void night_road()
{
    ///Road
    glBegin(GL_QUADS);
    glColor3ub(13, 2, 41);
    glVertex2f(-0.15f, 0.41f);
    glVertex2f(0.15f, 0.39f);
    glVertex2f(0.15f, -1.0f);
    glVertex2f(-0.15f, -1.0f);
    glEnd();

     /// Road Dashes
    glColor3ub(255, 255, 255); // White color for the dashes

    for (float y = -1.0f; y <= 0.4f; y += 0.18f) // Dash height + spacing = 0.18f
    {
        glBegin(GL_QUADS);
        glVertex2f(-0.01f, y);
        glVertex2f(0.01f, y);
        glVertex2f(0.01f, y + 0.06f); // Dash height = 0.06f
        glVertex2f(-0.01f, y + 0.06f);
        glEnd();
    }
    /// Left Side of the Road
    ///white
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.17f, 0.41f);
    glVertex2f(-0.15f, 0.41f);
    glVertex2f(-0.15f, -1.0f);
    glVertex2f(-0.17f, -1.0f);
    glEnd();

    /// Right Side of the Road
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.15f, 0.39f);
    glVertex2f(0.17f, 0.39f);
    glVertex2f(0.17f, -1.0f);
    glVertex2f(0.15f, -1.0f);
    glEnd();




    ///Road_RIGHT_sided

    glBegin(GL_QUADS);
    glColor3ub(13, 2, 41);
    glVertex2f(0.15f, -0.4f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(0.15f, -0.6f);

    glEnd();

    /// Road Left_sided
    glBegin(GL_QUADS);
    glColor3ub(13, 2, 41);
    glVertex2f(0.15f, -0.4f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(0.15f, -0.6f);
    glEnd();

// White border for the road (right side)
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.15f, -0.39f);
    glVertex2f(1.0f, -0.39f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(0.15f, -0.4f);
    glEnd();

//  white dashes on the road (right side)
    glColor3ub(255, 255, 255);
    glLineWidth(2.0f);
    for (float i = 0.2f; i < 1.0f; i += 0.2f) {
        glBegin(GL_LINES);
        glVertex2f(i, -0.5f);    // Start of dash
        glVertex2f(i + 0.1f, -0.5f); // End of dash
        glEnd();
    }

// Road border for the bottom edge
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.15f, -0.6f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(1.0f, -0.61f);
    glVertex2f(0.15f, -0.61f);
    glEnd();



    ///LEFT_side_Road
    glBegin(GL_QUADS);
    glColor3ub(13, 2, 41);
    glVertex2f(-0.15f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(-0.15f, -0.2f);
    glEnd();
    // Road left_side
    glBegin(GL_QUADS);
    glColor3ub(13, 2, 41); //
    glVertex2f(-0.15f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(-0.15f, -0.2f);
    glEnd();

// Top White Border for the Road
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.15f, 0.01f);
    glVertex2f(-1.0f, 0.01f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-0.15f, 0.0f);
    glEnd();

// Bottom White Border for the Road
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.15f, -0.2f);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(-1.0f, -0.21f);
    glVertex2f(-0.15f, -0.21f);
    glEnd();





    ///Dash 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.4f, -0.1f + 0.005f);
    glVertex2f(-0.35f, -0.1f + 0.005f);
    glVertex2f(-0.35f, -0.1f - 0.005f);
    glVertex2f(-0.4f, -0.1f - 0.005f);
    glEnd();

    /// Dash 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.6f, -0.1f + 0.005f);
    glVertex2f(-0.55f, -0.1f + 0.005f);
    glVertex2f(-0.55f, -0.1f - 0.005f);
    glVertex2f(-0.6f, -0.1f - 0.005f);
    glEnd();

    /// Dash 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.8f, -0.1f + 0.005f);
    glVertex2f(-0.75f, -0.1f + 0.005f);
    glVertex2f(-0.75f, -0.1f - 0.005f);
    glVertex2f(-0.8f, -0.1f - 0.005f);
    glEnd();
}


void night_crane()
{
    ///---Crane---

    ///left Quads
      glBegin(GL_QUADS);
    glColor3ub(13, 19, 105);
    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.6f, -0.36f);
    glVertex2f(0.62f, -0.36f);
    glVertex2f(0.62f, 0.3f);
    glEnd();

    ///right Quads
      glBegin(GL_QUADS);
    glColor3ub(13, 19, 105);
    glVertex2f(0.7f, 0.3f);
    glVertex2f(0.72f, 0.3f);
    glVertex2f(0.72f, -0.36f);
    glVertex2f(0.70f, -0.36f);
    glEnd();


    ///========

      glBegin(GL_QUADS);
    glColor3ub(13, 19, 105);
    glVertex2f(0.62f, -0.2f);
    glVertex2f(0.62f, -0.18f);
    glVertex2f(0.70f,  0.12f);
    glVertex2f(0.70f,  0.14f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3ub(13, 19, 105);
    glVertex2f(0.62f, 0.14f);
    glVertex2f(0.62f, 0.12f);
    glVertex2f(0.70f, -0.18f);
    glVertex2f(0.70f, -0.20f);
    glEnd();


    ///upper Quads
      glBegin(GL_QUADS);
    glColor3ub(13, 19, 105);
    glVertex2f(0.5f, 0.26f);
    glVertex2f(0.5f, 0.28f);
    glVertex2f(0.94f, 0.28f);
    glVertex2f(0.94f, 0.26f);
    glEnd();

    ///crane_rope
      glBegin(GL_LINES);
    glColor3ub(13, 19, 105);
    glVertex2f(0.88f, 0.26f);
    glVertex2f(0.88f, 0.18f);
    glEnd();

     ///rope_Container
      glBegin(GL_QUADS);
    glColor3ub(176, 9, 20);
    glVertex2f(0.82f, 0.14f);
    glVertex2f(0.82f, 0.18f);
    glVertex2f(0.94f, 0.18f);
    glVertex2f(0.94f, 0.14f);
    glEnd();

     ///Right_Containers
      glBegin(GL_QUADS);
    glColor3ub(176, 9, 20);
    glVertex2f(0.78f, -0.38f);
    glVertex2f(0.78f, -0.28f);
    glVertex2f(0.96f, -0.28f);
    glVertex2f(0.96f, -0.38f);
    glEnd();

    /// Title
    glColor3ub(245, 233, 10);
    renderBitmapString(0.825f, -0.34f, 0.0f, GLUT_BITMAP_HELVETICA_18, "FISH");

    ///----Right_Containers
     glBegin(GL_QUADS);
    glColor3ub(105, 31, 24);
    glVertex2f(0.78f, -0.28f);
    glVertex2f(0.78f, -0.18f);
    glVertex2f(0.96f, -0.18f);
    glVertex2f(0.96f, -0.28f);
    glEnd();

      /// Title
    glColor3ub(245, 233, 10);
    renderBitmapString(0.82f, -0.24f, 0.0f, GLUT_BITMAP_HELVETICA_18, "CLOTH");


    ///----Right_Containers
     glBegin(GL_QUADS);
    glColor3ub(69, 23, 84);
    glVertex2f(0.78f, -0.18f);
    glVertex2f(0.78f, -0.08f);
    glVertex2f(0.96f, -0.08f);
    glVertex2f(0.96f, -0.18f);
    glEnd();

      /// Title
    glColor3ub(245, 233, 10);
    renderBitmapString(0.82f, -0.14f, 0.0f, GLUT_BITMAP_HELVETICA_18, "SUGAR");


    ///--------Left_Containers--------
    glBegin(GL_QUADS);
    glColor3ub(28, 217, 194);
    glVertex2f(-0.94f, -0.82f);
    glVertex2f(-0.94f, -0.65f);
    glVertex2f(-0.61f, -0.65f);
    glVertex2f(-0.61f, -0.82f);
    glEnd();

           ///Title
    glColor3ub(0, 0, 0);
    renderBitmapString(-0.85f, -0.75f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "D R U G S");

    ///------second-----
      glBegin(GL_QUADS);
    glColor3ub(240, 203, 19);
    glVertex2f(-0.94f, -0.65f);
    glVertex2f(-0.94f, -0.48f);
    glVertex2f(-0.61f, -0.48f);
    glVertex2f(-0.61f, -0.65f);
    glEnd();

     ///Title
    glColor3ub(0, 0, 0);
    renderBitmapString(-0.85f, -0.58f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "K L I N E");

    /// Vertical_Container (right_side)
    glBegin(GL_QUADS);
    glColor3ub(242, 109, 7);
    glVertex2f(0.18, -0.3f);
    glVertex2f(0.18f, 0.2f);
    glVertex2f(0.25f, 0.2f);
    glVertex2f(0.25f, -0.3f);

     glBegin(GL_QUADS);
    glColor3ub(240, 203, 19);
    glVertex2f(0.25, -0.3f);
    glVertex2f(0.25f, 0.2f);
    glVertex2f(0.32f, 0.2f);
    glVertex2f(0.32f, -0.3f);


    ///--------Left_Containers (right_side)--------
     glBegin(GL_QUADS);
    glColor3ub(232, 61, 9);
    glVertex2f(-0.59f, -0.82f);
    glVertex2f(-0.59f, -0.65f);
    glVertex2f(-0.26f, -0.65f);
    glVertex2f(-0.26f, -0.82f);
    glEnd();

    ///Title
    glColor3ub(0, 0, 0);
    renderBitmapString(-0.50f, -0.75f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "C A R G O");

       ///--------second (right_side)--------
     glBegin(GL_QUADS);
    glColor3ub(82, 247, 22);
    glVertex2f(-0.59f, -0.65f);
    glVertex2f(-0.59f, -0.48f);
    glVertex2f(-0.26f, -0.48f);
    glVertex2f(-0.26f, -0.65f);
    glEnd();

       ///Title
    glColor3ub(0, 0, 0);
    renderBitmapString(-0.52f, -0.58f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "M  A E R S K");

}

void night_lamps()
{
    // First lamp pole
    glBegin(GL_QUADS);
    glColor3ub(27, 26, 31);
    glVertex2f(-0.30f, 0.0f);
    glVertex2f(-0.30f, 0.26f);
    glVertex2f(-0.28f, 0.26f);
    glVertex2f(-0.28f, 0.0f);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(27, 26, 31);
    glVertex2f(-0.28f, 0.26f);
    glVertex2f(-0.20f, 0.26f);
    glVertex2f(-0.20f, 0.24f);
    glVertex2f(-0.28f, 0.24f);
    glEnd();

        /// white colour
    glBegin(GL_QUADS);
    glColor3ub(253, 252, 255);
    glVertex2f(-0.24f, 0.26f);
    glVertex2f(-0.20f, 0.26f);
    glVertex2f(-0.20f, 0.23f);
    glVertex2f(-0.24f, 0.23f);
    glEnd();


    // Second lamp pole
     glBegin(GL_QUADS);
    glColor3ub(27, 26, 31);
    glVertex2f(-0.60f, 0.0f);
    glVertex2f(-0.60f, 0.26f);
    glVertex2f(-0.58f, 0.26f);
    glVertex2f(-0.58f, 0.0f);
    glEnd();

      glBegin(GL_QUADS);
    glColor3ub(27, 26, 31);
    glVertex2f(-0.58f, 0.26f);
    glVertex2f(-0.50f, 0.26f);
    glVertex2f(-0.50f, 0.24f);
    glVertex2f(-0.58f, 0.24f);
    glEnd();


        /// white colour
    glBegin(GL_QUADS);
    glColor3ub(253, 252, 255);
    glVertex2f(-0.54f, 0.26f);
    glVertex2f(-0.50f, 0.26f);
    glVertex2f(-0.50f, 0.23f);
    glVertex2f(-0.54f, 0.23f);
    glEnd();


    // Third lamp pole
       glBegin(GL_QUADS);
    glColor3ub(27, 26, 31);
    glVertex2f(-0.90f, 0.0f);
    glVertex2f(-0.90f, 0.26f);
    glVertex2f(-0.88f, 0.26f);
    glVertex2f(-0.88f, 0.0f);
    glEnd;

      glBegin(GL_QUADS);
    glColor3ub(27, 26, 31);
    glVertex2f(-0.88f, 0.26f);
    glVertex2f(-0.80f, 0.26f);
    glVertex2f(-0.80f, 0.24f);
    glVertex2f(-0.88f, 0.24f);
    glEnd();


        /// white colour
     glBegin(GL_QUADS);
    glColor3ub(253, 252, 255);
    glVertex2f(-0.84f, 0.26f);
    glVertex2f(-0.80f, 0.26f);
    glVertex2f(-0.80f, 0.23f);
    glVertex2f(-0.84f, 0.23f);
    glEnd();






}



///Right side
 void night_truck()
{

    //wheels
     glColor3ub(186, 183, 175);
     draw_circle(0.62, -0.54 , 0.025);
     draw_circle(0.785, -0.54 , 0.025);



   //back body
    glBegin(GL_QUADS);
    glColor3ub(171, 43, 51);
    glVertex2f(0.55f, -0.54f);
    glVertex2f(0.55f, -0.45f);
    glVertex2f(0.74f, -0.45f);
    glVertex2f(0.74f, -0.54f);
    glEnd();

    //font
    glBegin(GL_POLYGON);
    glColor3ub(171, 156, 43);
    glVertex2f(0.75f, -0.42f);
    glVertex2f(0.8f, -0.42f);
    glVertex2f(0.84f, -0.48f);
    glVertex2f(0.84f, -0.54f);
    glVertex2f(0.75f, -0.54f);

    glEnd();

    ///buttom
    glBegin(GL_QUADS);
    glColor3ub(171, 227, 50);
    glVertex2f(0.55f, -0.54f);
    glVertex2f(0.78f, -0.54f);
    glVertex2f(0.78f, -0.55f);
    glVertex2f(0.55f, -0.55f);
    glEnd();

    ///window
    glBegin(GL_QUADS);
    glColor3ub(174, 199, 242);
    glVertex2f(0.76f, -0.44f);
    glVertex2f(0.79f, -0.44f);
    glVertex2f(0.79f, -0.48f);
    glVertex2f(0.76f, -0.48f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.79f, -0.44f);
    glVertex2f(0.82f, -0.48f);
    glVertex2f(0.79f, -0.48f);

    glEnd();

}


void night_truck2()
{
    //wheels
     glColor3ub(186, 183, 175);
     draw_circle(-0.52, -0.15 , 0.025);
     draw_circle(-0.7, -0.15 , 0.025);


     //back body
    glBegin(GL_QUADS);
    glColor3ub(171, 43, 51);
    glVertex2f(-0.66f, -0.08f);
    glVertex2f(-0.46f, -0.08f);
    glVertex2f(-0.46f, -0.15f);
    glVertex2f(-0.66f, -0.15f);
    glEnd();

    ///buttom
    glBegin(GL_QUADS);
    glColor3ub(171, 227, 50);
    glVertex2f(-0.46f, -0.15f);
    glVertex2f(-0.46f, -0.16f);
    glVertex2f(-0.7f, -0.16f);
    glVertex2f(-0.7f, -0.15f);
    glEnd();


     //font
    glBegin(GL_POLYGON);
    glColor3ub(171, 156, 43);
    glVertex2f(-0.67f, -0.04f);
    glVertex2f(-0.74f, -0.04f);
    glVertex2f(-0.78f, -0.08f);
    glVertex2f(-0.78f, -0.15f);
    glVertex2f(-0.67f, -0.15f);

    glEnd();


     ///window
    glBegin(GL_QUADS);
    glColor3ub(174, 199, 242);
    glVertex2f(-0.685f, -0.06f);
    glVertex2f(-0.73f, -0.06f);
    glVertex2f(-0.73f, -0.1f);
    glVertex2f(-0.685f, -0.1f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(-0.73f, -0.06f);
    glVertex2f(-0.73f, -0.1f);
    glVertex2f(-0.75f, -0.1f);
    glEnd();
}

void daySound()
{
    PlaySound("Rain.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}



void raincloud1Move(int value8)
{
    GLfloat raincloud1_speed = 0.004f;

    if(rain_cloud1Position >1.9)
        rain_cloud1Position = -1.0f;
    rain_cloud1Position += raincloud1_speed;

    glutPostRedisplay();
	glutTimerFunc(100, raincloud1Move, 0);
}

void raincloud2Move(int value9)
{
    GLfloat raincloud2_speed = 0.02f;

    if(rain_cloud2Position <-1.5)
        rain_cloud2Position = 0.99f;
    rain_cloud2Position -= raincloud2_speed;

    glutPostRedisplay();
	glutTimerFunc(100, raincloud2Move, 0);
}

void rainfall(int value10)
{
    GLfloat rain_speed = 0.1f;

    if(rain_Position <-1.0)
        rain_Position = 1.5f;
    rain_Position -= rain_speed;

    glutPostRedisplay();
	glutTimerFunc(100, rainfall, 0);
}

void rainshipMove(int value11)
{
    GLfloat rainship_speed = 0.004f;

    if(rain_ShipPosition <-0.9)
        rain_ShipPosition = 0.1f;
    rain_ShipPosition -= rainship_speed;

    glutPostRedisplay();
	glutTimerFunc(100, rainshipMove, 0);
}

void rainwaveMove(int value12)
{
    GLfloat rainwave_speed = 0.003f;

    if(rain_wavePosition <-0.8)
        rain_wavePosition = 0.0f;
    rain_wavePosition -= rainwave_speed;

    glutPostRedisplay();
	glutTimerFunc(100, rainwaveMove, 0);
}

void rainfall2(int value13)
{
    GLfloat rain2_speed = 1.5f;

    if(rain2_Position <-1.0)
        rain2_Position = 1.0f;
    rain2_Position -= rain2_speed;

    glutPostRedisplay();
	glutTimerFunc(100, rainfall2, 0);
}

/*
void draw_circle(float x, float y, float radius)
{
    int triangleAmount = 1000; // The number of triangles to approximate the circle
    float twicePi = 2.0f * 3.14159265358979323846;

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
*/
void Rain_Sky()
{
    //sky
    glBegin(GL_POLYGON);
    glColor3ub(157, 157, 158);
    glVertex2f(-1.0f, 0.4f);
    glVertex2f(-0.7f, 0.6f);
    glVertex2f(-0.8f, 0.34f);
    glVertex2f(-0.6f, 0.3f);
    glVertex2f(-0.36f, 0.35f);
    glVertex2f(0.10f, 0.54f);
    glVertex2f(0.30f, 0.42f);
    glVertex2f(0.62f, 0.30f);
    glVertex2f(0.84f, 0.28f);
    glVertex2f(1.0f, 0.50f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
}
void Rain_Cloud()
{
    // Cloud 1
    glPushMatrix();
    glTranslatef(rain_cloud1Position,0.0f, 0.0f);
    glColor3ub(114, 114, 115); // Light gray
    draw_circle(-0.5f, 0.7f, 0.08f); // Main circle
    draw_circle(-0.6f, 0.72f, 0.06f); // Left circle
    draw_circle(-0.4f, 0.72f, 0.06f); // Right circle
    draw_circle(-0.55f, 0.65f, 0.05f); // Bottom left circle
    draw_circle(-0.45f, 0.65f, 0.05f); // Bottom right circle


    // Cloud 2
    draw_circle(0.3f, 0.75f, 0.08f); // Main circle
    //draw_circle(0.2f, 0.77f, 0.06f); // Left circle
    draw_circle(0.4f, 0.77f, 0.06f); // Right circle
    draw_circle(0.25f, 0.7f, 0.05f); // Bottom left circle
    draw_circle(0.35f, 0.7f, 0.05f); // Bottom right circle
    glPopMatrix();


    // Cloud 3
    glPushMatrix();
    glTranslatef(rain_cloud2Position,0.0f, 0.0f);
    draw_circle(-0.8f, 0.6f, 0.07f); // Main circle
    draw_circle(-0.9f, 0.62f, 0.05f); // Left circle
    //draw_circle(-0.7f, 0.62f, 0.05f); // Right circle
    draw_circle(-0.85f, 0.55f, 0.04f); // Bottom left circle
    draw_circle(-0.75f, 0.55f, 0.04f); // Bottom right circle

    // Cloud 4
    draw_circle(0.7f, 0.65f, 0.09f); // Main circle
    draw_circle(0.6f, 0.67f, 0.07f); // Left circle
    draw_circle(0.8f, 0.67f, 0.07f); // Right circle
    //draw_circle(0.65f, 0.6f, 0.06f); // Bottom left circle
    draw_circle(0.75f, 0.6f, 0.06f); // Bottom right circle
    glPopMatrix();
}
void Rain_Road()
{
    /// Road
    glBegin(GL_QUADS);
    glColor3ub(50, 50, 50); // Dark gray road color
    glVertex2f(0.3f, -1.0f);
    glVertex2f(1.0f, 0.2f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(0.6f, -1.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255); // Dark gray road color
    glVertex2f(0.45f, -1.0f);
    glVertex2f(1.0f, 0.05f);
    glEnd();
}

void Rain_Sea()
{
     glBegin(GL_POLYGON);
    glColor3ub(40, 152, 237); // Dark gray road color
    glVertex2f(-0.36f, 0.34f);
    glVertex2f(-0.4f, 0.28f);
    glVertex2f(-0.38f,-0.2f);
    glVertex2f(-0.3f,0.06f);
    glVertex2f(-0.28f,0.0f);
    glVertex2f(-0.3f,-0.04f);
    glVertex2f(-0.3f,0.1f);
    glVertex2f(-0.2f,-0.4f);
    glVertex2f(-0.18f,-0.46f);
    glVertex2f(-0.06f,-0.6f);
    glVertex2f(0.0f,-1.0f);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(-1.0f,0.4f);
    glEnd();

}

void Rain_Ship()
{
     glBegin(GL_POLYGON);
    glColor3ub(171, 132, 68); // Dark gray road color
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.4f,-0.5f);
    glVertex2f(-0.8f,-0.5f);
    glVertex2f(-0.9f,-0.3f);
    glVertex2f(-0.8f,-0.3f);
    glVertex2f(-0.76f,-0.42f);
    glVertex2f(-0.7f,-0.42f);
    glVertex2f(-0.56f,-0.42f);
    glVertex2f(-0.48f,-0.3f);
    glEnd();
}


void Rain_Crane()
{
    ///leg left
    glBegin(GL_QUADS);
    glColor3ub(217, 59, 85);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.4f, -0.45f);
    glVertex2f(0.42f, -0.45f);
    glVertex2f(0.42f, -0.0f);

    glEnd();

    ///leg Right
    glBegin(GL_QUADS);
    glColor3ub(217, 59, 85);
    glVertex2f(0.48f, -0.0f);
    glVertex2f(0.48f, -0.45f);
    glVertex2f(0.5f, -0.45f);
    glVertex2f(0.5f, -0.0f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(217, 59, 85);
    glVertex2f(0.2f, -0.05f);
    glVertex2f(0.2f, -0.07f);
    glVertex2f(0.55f, -0.07f);
    glVertex2f(0.55f, -0.05f);
    glEnd();

    ///Y
    glBegin(GL_QUADS);
    glColor3ub(217, 59, 85);
    glVertex2f(0.5f, -0.24f);
    glVertex2f(0.5f, -0.26f);
    glVertex2f(0.4f, -0.26f);
    glVertex2f(0.4f, -0.24f);
    glEnd();

    ///Y
    glBegin(GL_QUADS);
    glColor3ub(217, 59, 85);
    glVertex2f(0.5f, -0.3f);
    glVertex2f(0.5f, -0.32f);
    glVertex2f(0.4f, -0.32f);
    glVertex2f(0.4f, -0.3f);
    glEnd();

    ///Hang
    glBegin(GL_LINES);
    glColor3ub(217, 59, 85);
    glVertex2f(0.24f, -0.07f);
    glVertex2f(0.24f, -0.15f);
    glEnd();

}

void Rain_Container()
{
    //hanging
    glBegin(GL_QUADS);
    glColor3ub(46, 6, 84);
    glVertex2f(0.18f, -0.14f);
    glVertex2f(0.18f, -0.2f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.3f, -0.14f);
    glEnd();

     /// Title
    glColor3ub(255,255,255);
    renderBitmapString(0.22f, -0.18f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_10, "FISH");


    ///on the ship
    //left

    glPushMatrix();
    glTranslatef(rain_ShipPosition,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(6, 120, 8);
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.6f, -0.3f);
    glVertex2f(-0.6f, -0.2f);
    glVertex2f(-0.8f, -0.2f);
    glEnd();

        /// Title
    glColor3ub(0,0,0);
    renderBitmapString(-0.74f, -0.26f, 0.0f, GLUT_BITMAP_HELVETICA_18, "E V E R");

    glBegin(GL_QUADS);
    glColor3ub(96, 120, 8);
    glVertex2f(-0.8f, -0.1f);
    glVertex2f(-0.6f, -0.1f);
    glVertex2f(-0.6f, -0.2f);
    glVertex2f(-0.8f, -0.2f);
    glEnd();

     glColor3ub(0,0,0);
    renderBitmapString(-0.74f, -0.16f, 0.0f, GLUT_BITMAP_HELVETICA_18, "R E S K");

    glBegin(GL_QUADS);
    glColor3ub(6, 92, 35);
    glVertex2f(-0.8f, -0.1f);
    glVertex2f(-0.6f, -0.1f);
    glVertex2f(-0.6f, -0.0f);
    glVertex2f(-0.8f, -0.0f);
    glEnd();

     glColor3ub(0,0,0);
    renderBitmapString(-0.74f, -0.06f, 0.0f, GLUT_BITMAP_HELVETICA_18, "R D X X");


    //Right
    glBegin(GL_QUADS);
    glColor3ub(92, 6, 25);
    glVertex2f(-0.39f, -0.3f);
    glVertex2f(-0.59f, -0.3f);
    glVertex2f(-0.59f, -0.2f);
    glVertex2f(-0.39f, -0.2f);
    glEnd();

     glColor3ub(0,0,0);
    renderBitmapString(-0.53f, -0.26f, 0.0f, GLUT_BITMAP_HELVETICA_18, "F R A N");

    glBegin(GL_QUADS);
    glColor3ub(201, 12, 12);
    glVertex2f(-0.39f, -0.1f);
    glVertex2f(-0.59f, -0.1f);
    glVertex2f(-0.59f, -0.2f);
    glVertex2f(-0.39f, -0.2f);
    glEnd();

     glColor3ub(0,0,0);
    renderBitmapString(-0.53f, -0.16f, 0.0f, GLUT_BITMAP_HELVETICA_18, "S A I N T");

    glBegin(GL_QUADS);
    glColor3ub(55, 227, 20);
    glVertex2f(-0.39f, -0.1f);
    glVertex2f(-0.59f, -0.1f);
    glVertex2f(-0.59f, -0.0f);
    glVertex2f(-0.39f, -0.0f);
    glEnd();

    glColor3ub(0,0,0);
    renderBitmapString(-0.532f, -0.06f, 0.0f, GLUT_BITMAP_HELVETICA_18, "W H E E L");
    glPopMatrix();


    ///on floor
    glBegin(GL_QUADS);
    glColor3ub(235, 180, 52);
    glVertex2f(0.02f, -0.98f);
    glVertex2f(0.02f, -0.82f);
    glVertex2f(0.28f, -0.82f);
    glVertex2f(0.28f, -0.98f);
    glEnd();

        ///Title
    glColor3ub(0, 0, 0);
    renderBitmapString(0.08f, -0.92f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "K L I N E");

    glBegin(GL_QUADS);
    glColor3ub(122, 63, 29);
    glVertex2f(0.02f, -0.66f);
    glVertex2f(0.02f, -0.82f);
    glVertex2f(0.28f, -0.82f);
    glVertex2f(0.28f, -0.66f);
    glEnd();


        ///Title
    glColor3ub(0, 0, 0);
    renderBitmapString(0.08f, -0.75f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "I T A L Y");

    glBegin(GL_QUADS);
    glColor3ub(110, 107, 15);
    glVertex2f(0.02f, -0.66f);
    glVertex2f(0.02f, -0.5f);
    glVertex2f(0.28f, -0.5f);
    glVertex2f(0.28f, -0.66f);
    glEnd();

        ///Title
    glColor3ub(0, 0, 0);
    renderBitmapString(0.08f, -0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "T O K Y O");

    glBegin(GL_QUADS);
    glColor3ub(163, 196, 43);
    glVertex2f(-0.14f, -0.2f);
    glVertex2f(-0.14f, -0.3f);
    glVertex2f(0.02f, -0.3f);
    glVertex2f(0.02f, -0.2f);
    glEnd();

        /// Title
      glColor3ub(0,0,0);
    renderBitmapString(-0.12f, -0.26f, 0.0f, GLUT_BITMAP_HELVETICA_18, "S U P R A");

    glBegin(GL_QUADS);
    glColor3ub(255, 141, 10);
    glVertex2f(-0.14f, -0.2f);
    glVertex2f(-0.14f, -0.1f);
    glVertex2f(0.02f, -0.1f);
    glVertex2f(0.02f, -0.2f);
    glEnd();

        /// Title
      glColor3ub(0,0,0);
    renderBitmapString(-0.10f, -0.16f, 0.0f, GLUT_BITMAP_HELVETICA_18, "B M W");


    //right side of road
    glBegin(GL_QUADS);
    glColor3ub(110, 15, 125);
    glVertex2f(0.7f, -0.98f);
    glVertex2f(0.7f, -0.82f);
    glVertex2f(0.98f, -0.82f);
    glVertex2f(0.98f, -0.98f);
    glEnd();

     ///Title
    glColor3ub(0, 0, 0);
    renderBitmapString(0.77f, -0.92f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "B E R L I N");

    glBegin(GL_QUADS);
    glColor3ub(16, 71, 64);
    glVertex2f(0.77f, -0.66f);
    glVertex2f(0.77f, -0.82f);
    glVertex2f(0.98f, -0.82f);
    glVertex2f(0.98f, -0.66f);
    glEnd();

     ///Title
    glColor3ub(0, 0, 0);
    renderBitmapString(0.82f, -0.76f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "S A I N T");
}

void Rain_wave()
{
    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
    glVertex2f(-0.98f, -0.98f);
    glVertex2f(-0.9f, -0.94f);
    glVertex2f(-0.82f, -0.98f);
    glVertex2f(-0.74f, -0.94f);
    glVertex2f(-0.66f, -0.98f);
    glVertex2f(-0.58f, -0.94f);
    glVertex2f(-0.5f, -0.98f);
    glVertex2f(-0.42f, -0.94f);
    glVertex2f(-0.34f, -0.98f);
    glVertex2f(-0.26f, -0.94f);
    glVertex2f(-0.18f, -0.98f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
    glVertex2f(-0.98f, -0.90f);
    glVertex2f(-0.9f, -0.86f);
    glVertex2f(-0.82f, -0.90f);
    glVertex2f(-0.74f, -0.86f);
    glVertex2f(-0.66f, -0.90f);
    glVertex2f(-0.58f, -0.86f);
    glVertex2f(-0.5f, -0.90f);
    glVertex2f(-0.42f, -0.86f);
    glVertex2f(-0.34f, -0.9f);
    glVertex2f(-0.26f, -0.86f);
    glVertex2f(-0.18f, -0.9f);
    glEnd();

      glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
    glVertex2f(-0.98f, -0.82f);
    glVertex2f(-0.9f, -0.78f);
    glVertex2f(-0.82f, -0.82f);
    glVertex2f(-0.74f, -0.78f);
    glVertex2f(-0.66f, -0.82f);
    glVertex2f(-0.58f, -0.78f);
    glVertex2f(-0.5f, -0.82f);
    glVertex2f(-0.42f, -0.78f);
    glVertex2f(-0.34f, -0.82f);
    glVertex2f(-0.26f, -0.78f);
    glVertex2f(-0.18f, -0.82f);
    glEnd();

     glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
    glVertex2f(-0.98f, -0.74f);
    glVertex2f(-0.9f, -0.70f);
    glVertex2f(-0.82f, -0.74f);
    glVertex2f(-0.74f, -0.7f);
    glVertex2f(-0.66f, -0.74f);
    glVertex2f(-0.58f, -0.7f);
    glVertex2f(-0.5f, -0.74f);
    glVertex2f(-0.42f, -0.7f);
    glVertex2f(-0.34f, -0.74f);
    glVertex2f(-0.26f, -0.7f);
    glVertex2f(-0.18f, -0.74f);
    glEnd();

     glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
    glVertex2f(-0.98f, -0.66f);
    glVertex2f(-0.9f, -0.62f);
    glVertex2f(-0.82f, -0.66f);
    glVertex2f(-0.74f, -0.62f);
    glVertex2f(-0.66f, -0.66f);
    glVertex2f(-0.58f, -0.62f);
    glVertex2f(-0.5f, -0.66f);
    glVertex2f(-0.42f, -0.62f);
    glVertex2f(-0.34f, -0.66f);
    glVertex2f(-0.26f, -0.62f);
    glVertex2f(-0.18f, -0.66f);
    glEnd();

     glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
    glVertex2f(-0.98f, -0.58f);
    glVertex2f(-0.9f, -0.54f);
    glVertex2f(-0.82f, -0.58f);
    glVertex2f(-0.74f, -0.54f);
    glVertex2f(-0.66f, -0.58f);
    glVertex2f(-0.58f, -0.54f);
    glVertex2f(-0.5f, -0.58f);
    glVertex2f(-0.42f, -0.54f);
    glVertex2f(-0.34f, -0.58f);
    glVertex2f(-0.26f, -0.54f);
    glVertex2f(-0.18f, -0.58f);
    glEnd();

      glBegin(GL_LINE_STRIP);
    glColor3ub(255,255,255);
    glVertex2f(-0.98f, -0.5f);
    glVertex2f(-0.9f, -0.46f);
    glVertex2f(-0.82f, -0.5f);
    glVertex2f(-0.74f, -0.46f);
    glVertex2f(-0.66f, -0.5f);
    glVertex2f(-0.58f, -0.46f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.42f, -0.46f);
    glVertex2f(-0.34f, -0.5f);
    glVertex2f(-0.26f, -0.46f);
    glVertex2f(-0.18f, -0.5f);
    glEnd();


}


void Rain()
{

    glLineWidth(2.0f); // Set the width of the raindrops
    glBegin(GL_LINES);
    glColor3ub(173, 216, 230); // Light blue color for raindrops

    // Dynamically generate raindrops across the entire display
    float startX = -1.0f; // Starting x-coordinate in NDC
    float endX = 1.0f;    // Ending x-coordinate in NDC
    float startY = 1.0f;  // Starting y-coordinate in NDC
    float endY = -1.0f;   // Ending y-coordinate in NDC
    float stepX = 0.05f;  // Horizontal spacing between raindrops
    float stepY = 0.2f;   // Vertical spacing for raindrop repetition

    for (float x = startX; x <= endX; x += stepX)
        {
            for (float y = startY; y >= endY; y -= stepY)
            {
                glVertex2f(x, y);       // Start of the raindrop
                glVertex2f(x, y - 0.05f); // End of the raindrop (length of 0.05 in NDC)
            }
        }
    glEnd();

}

void Rain2()
{
    glPushMatrix();
    glTranslatef(0.0,rain_Position, 0.0f);
    glLineWidth(2.0f); // Set the width of the raindrops
    glBegin(GL_LINES);
    glColor3ub(173, 216, 230); // Light blue color for raindrops

    // Dynamically generate raindrops across the entire display
    float startX = 1.0f; // Starting x-coordinate in NDC
    float endX = 1.0f;    // Ending x-coordinate in NDC
    float startY = 1.0f;  // Starting y-coordinate in NDC
    float endY = -1.0f;   // Ending y-coordinate in NDC
    float stepX = 0.05f;  // Horizontal spacing between raindrops
    float stepY = 0.2f;   // Vertical spacing for raindrop repetition

    for (float x = startX; x <= endX; x += stepX)
        {
            for (float y = startY; y >= endY; y -= stepY)
            {
                glVertex2f(x, y);       // Start of the raindrop
                glVertex2f(x, y - 0.05f); // End of the raindrop (length of 0.05 in NDC)
            }
        }
    glEnd();
    glPopMatrix();
}

void Rain3()
{
    glLineWidth(2.0f); // Set the width of the raindrops
    glBegin(GL_LINES);
    glColor3ub(173, 216, 230); // Light blue color for raindrops

    // Dynamically generate raindrops across the entire display
    float startX = -1.0f; // Starting x-coordinate in NDC
    float endX = 1.0f;    // Ending x-coordinate in NDC
    float startY = 1.0f;  // Starting y-coordinate in NDC
    float endY = -1.0f;   // Ending y-coordinate in NDC
    float stepX = 0.05f;  // Horizontal spacing between raindrops
    float stepY = 0.2f;   // Vertical spacing for raindrop repetition

    for (float x = startX; x <= endX; x += stepX)
        {
            for (float y = startY; y >= endY; y -= stepY)
            {
                glVertex2f(x, y);       // Start of the raindrop
                glVertex2f(x, y - 0.05f); // End of the raindrop (length of 0.05 in NDC)
            }
        }
    glEnd();

}

///Day_View
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f ); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glLoadIdentity();

    Day_sky();
    Floor();

    sun();


    //cloud1();


    glPushMatrix();
    glTranslatef(cloud_Position,0.0f, 0.0f);
    cloud2();
    glPopMatrix();

    sea();


    glPushMatrix();
    glTranslatef(ship_Position,0.0f, 0.0f);
    ship();
    glPopMatrix();

    crane();

    Road();


   // drawCar();

    glPushMatrix();
    glTranslatef(car_Position,0.0f, 0.0f);
    drawCar2();
    glPopMatrix();

    Truck();

    glLoadIdentity();


    Truck_onRoad();


    Lamp();

    Container();

    smallContainer();

    //daySound();

    glFlush(); // Render now
}


///Night_View
void night_display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f ); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    night_floor();
    night_sky();
    night_road();
    night_star();

    glPushMatrix();
    glTranslatef(night_cloudPosition,0.0f, 0.0f);
    night_cloud();
    glPopMatrix();

    night_crane();
    night_lamps();

    glPushMatrix();
    glTranslatef(night_truckPosition,0.0f, 0.0f);
    night_truck();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(night_truck2Position,0.0f, 0.0f);
    night_truck2();
    glPopMatrix();


    moon();

     glFlush(); // Render now
}


///Rain_View
void rain_display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f ); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    Rain_Sky();
    Rain_Cloud();
    Rain_Road();
    Rain_Sea();

    Rain_Crane();
    Rain_Container();

    glPushMatrix();
    glTranslatef(rain_wavePosition,rain_wavePosition, 0.0f);
    Rain_wave();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(rain_ShipPosition,0.0f, 0.0f);
    Rain_Ship();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,rain_Position, 0.0f);
    Rain();
    glPopMatrix();

    Rain2();
    Rain3();

    glFlush(); // Render now
}
void handleKeyPass(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'c':
    case 'C':
        glutDisplayFunc(cover_page);
        glutPostRedisplay();
        break;


    case 'd':
    case 'D':
        glutDisplayFunc(display);
        glutPostRedisplay();
        sndPlaySound("Day.wav",SND_ASYNC);
        break;


    case 'N':
    case 'n':
        glutDisplayFunc(night_display);
        glutPostRedisplay();
        sndPlaySound("Night.wav",SND_ASYNC);
        break;


    case 'R':
    case 'r':
        glutDisplayFunc(rain_display);
        glutPostRedisplay();
        sndPlaySound("Rain.wav",SND_ASYNC);
        break;



    }
    glutPostRedisplay();
}



/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1910, 1020); // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("SEA PORT VIEW"); // Create a window with the given title
    glutDisplayFunc(cover_page); // Register display callback handler for window re-paint
    glutKeyboardFunc(handleKeyPass);

    ///day
    glutTimerFunc(2500, truckMove, 0);
     glutTimerFunc(100, carMove, 0);
     glutTimerFunc(1000, cloudMove, 0);
     glutTimerFunc(5000, craneMove, 0);
     glutTimerFunc(4000, shipMove, 0);

     ///night
    glutTimerFunc(100, nightCloudMove, 0);
    glutTimerFunc(100, nighttruckMove, 0);
    glutTimerFunc(1000, nighttruck2Move, 0);

    ///rain
    glutTimerFunc(100, raincloud1Move, 0);
    glutTimerFunc(100, raincloud2Move, 0);
    glutTimerFunc(100, rainfall, 0);
    glutTimerFunc(1000, rainshipMove, 0);
    glutTimerFunc(100, rainwaveMove, 0);
    glutTimerFunc(2000, rainfall2, 0);


    //daySound();
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
