#pragma once

//Entry point for Vega engine and the Vega sandbox.

#ifdef VEG_PLATFORM_WINDOWS

extern Vega::Application* Vega::MakeApplication();

int main(int argc, char* argv[])
{
	Vega::Log::Init();
	
	VEG_CORE_TRACE("Tracing in core!");
	VEG_CORE_DEBUG("Debugging in core!");
	VEG_CORE_INFO("Info in core!");
	VEG_CORE_WARN("Warning in core!");
	VEG_CORE_ERROR("Error in core!");
	VEG_CORE_CRITICAL("Critical in core!");
	VEG_TRACE("Tracing in client");
	VEG_DEBUG("Debugging in client");
	VEG_INFO("Info in client!");
	VEG_WARN("Warning in clent!");
	VEG_ERROR("Error in client");
	VEG_CRITICAL("Critical in client");

	auto app = Vega::MakeApplication();
	app->Run();
	delete app;
}
#endif