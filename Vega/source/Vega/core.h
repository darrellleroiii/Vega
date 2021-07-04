#pragma once

#ifdef VEG_PLATFORM_WINDOWS  //If platform is windows.
		#ifdef VEG_BUILD_DLL    //If dll is being built.
				#define VEGA_API __declspec(dllexport)
#else
				#define VEGA_API __declspec(dllimport)
#endif
#else					//If not then... NOIDONTHINKSO
		#error Vega is currently supported by Windows only!
#endif