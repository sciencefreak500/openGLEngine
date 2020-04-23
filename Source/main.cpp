#include "application.h"

int main( void )
{
    // Triangle to be rendered
	static const GLfloat triangle[] = 
    { 
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
	};

    Application test;

    test.render(triangle);

	return 0;
}
 