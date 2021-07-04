#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace Vega {
	class VEGA_API Log
	{
	public:
		static void Init();
	    inline static std::shared_ptr<spdlog::logger>& GetCoreLog() { return s_CoreLog; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLog() { return s_ClientLog; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLog;
		static std::shared_ptr<spdlog::logger> s_ClientLog;
	};
}


//Core Logs.
#define VEG_CORE_TRACE(...)    ::Vega::Log::GetCoreLog()->trace(__VA_ARGS__)
#define VEG_CORE_DEBUG(...)    ::Vega::Log::GetCoreLog()->debug(__VA_ARGS__)
#define VEG_CORE_INFO(...)     ::Vega::Log::GetCoreLog()->info(__VA_ARGS__)
#define VEG_CORE_WARN(...)     ::Vega::Log::GetCoreLog()->warn(__VA_ARGS__)
#define VEG_CORE_ERROR(...)    ::Vega::Log::GetCoreLog()->error(__VA_ARGS__)
#define VEG_CORE_CRITICAL(...) ::Vega::Log::GetCoreLog()->critical(__VA_ARGS__)

//Client Logs.
#define VEG_TRACE(...)         ::Vega::Log::GetClientLog()->trace(__VA_ARGS__)
#define VEG_DEBUG(...)         ::Vega::Log::GetClientLog()->debug(__VA_ARGS__)
#define VEG_INFO(...)          ::Vega::Log::GetClientLog()->info(__VA_ARGS__)
#define VEG_WARN(...)          ::Vega::Log::GetClientLog()->warn(__VA_ARGS__)
#define VEG_ERROR(...)         ::Vega::Log::GetClientLog()->error(__VA_ARGS__)
#define VEG_CRITICAL(...)      ::Vega::Log::GetClientLog()->critical(__VA_ARGS__) 