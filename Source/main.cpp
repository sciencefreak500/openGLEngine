#include "../Header/core.h"

int main( void )
{
    // Triangle to be rendered
	static const GLfloat triangle[] = 
    { 
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
	};

    Program* test;

    test->render(triangle);

	return 0;
}
 