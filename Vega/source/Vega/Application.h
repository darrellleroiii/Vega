#pragma once
#include "core.h"

namespace Vega {
	class VEGA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	//To be defined client side.
	Application* MakeApplication();
}
