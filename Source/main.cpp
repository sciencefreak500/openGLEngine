#include "application.h"

int main( void )
{
    Application app;

	// run the games main loop which updates the camera,
	// renderer, inputs, etc
    app.tick();

	return 0;
}
 