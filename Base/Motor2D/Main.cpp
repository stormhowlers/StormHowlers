#include <stdlib.h>

#include "Defs.h"
#include "Log.h"
#include "App.h"

// This is needed here because SDL redefines main function
// do not add any other libraries here, instead put them in their Module
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

#include "Brofiler/Brofiler.h"
#pragma comment( lib, "Brofiler/ProfilerCore32.lib")

enum MainState
{
	CREATE = 1,
	AWAKE,
	START,
	LOOP,
	CLEAN,
	FAIL,
	EXIT
};

MainApp* App = NULL;

int main(int argc, char* args[])
{
	LOG("Engine starting ... %d");

	MainState state = MainState::CREATE;
	int result = EXIT_FAILURE;

	while(state != EXIT)
	{
		switch(state)
		{

			// Allocate the engine --------------------------------------------
			case CREATE:
			LOG("CREATION PHASE ===============================");

			App = new MainApp(argc, args);

			if(App != NULL)
				state = AWAKE;
			else
				state = FAIL;

			break;

			// Awake all Module -----------------------------------------------
			case AWAKE:
			LOG("AWAKE PHASE ===============================");
			if(App->Awake() == true)
				state = START;
			else
			{
				LOG("ERROR: Awake failed");
				state = FAIL;
			}

			break;

			// Call all Module before first frame  ----------------------------
			case START:
			LOG("START PHASE ===============================");
			if(App->Start() == true)
			{
				state = LOOP;
				LOG("UPDATE PHASE ===============================");
			}
			else
			{
				state = FAIL;
				LOG("ERROR: Start failed");
			}
			break;

			// Loop all Module until we are asked to leave ---------------------
			case LOOP: 
			{
				BROFILER_FRAME("Grip or Slip Brofiler Test");

				if (App->Update() == false)
					state = CLEAN;
			}
			break;

			// Cleanup allocated memory -----------------------------------------
			case CLEAN:
			LOG("CLEANUP PHASE ===============================");
			if(App->CleanUp() == true)
			{
				RELEASE(App);
				result = EXIT_SUCCESS;
				state = EXIT;
			}
			else
				state = FAIL;

			break;

			// Exit with errors and shame ---------------------------------------
			case FAIL:
			LOG("Exiting with errors :(");
			result = EXIT_FAILURE;
			state = EXIT;
			break;
		}
	}

	LOG("... Bye! :)\n");

	// Dump memory leaks
	return result;
}