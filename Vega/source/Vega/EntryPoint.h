#pragma once

//Entry point for Vega engine and the Vega sandbox.

#ifdef VEG_PLATFORM_WINDOWS

extern Vega::Application* Vega::MakeApplication();

int main(int argc, char** argv)
{
	auto app = Vega::MakeApplication();
	app->Run();
	delete app;
}
#endif