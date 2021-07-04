#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Vega {
   std::shared_ptr<spdlog::logger> Log::s_CoreLog;
   std::shared_ptr<spdlog::logger> Log::s_ClientLog;

	void Vega::Log::Init()
	{
		spdlog::set_pattern("%^%r: %t: %n: %v: %$");

		s_CoreLog = spdlog::stdout_color_mt("CORE");
		s_CoreLog->set_level(spdlog::level::trace);

		s_ClientLog = spdlog::stdout_color_mt("CLIENT");
		s_ClientLog->set_level(spdlog::level::trace);
	}
}