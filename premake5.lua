--premake5.lua VEGA ENGINE

workspace "Vega"
architecture "x64"
startproject "Sandbox"
configurations 
{
"Debug",
"Release",
"Dist" }

   outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 
   

project "Vega"

location "Vega"

   kind "SharedLib"

   language "C++"

   targetdir ("bin/"..outputdir.."/%{prj.name}")

   objdir ("bin-int/"..outputdir.."/%{prj.name}")

     files 
   {
   "%{prj.name}/source/**.h",
   "%{prj.name}/source/**.cpp"
   } 

   includedirs
   {
   "%{prj.name}/vendor/spdlog/include;"
   }

filter "system:windows"

   cppdialect "C++17"

   staticruntime "on"

   systemversion "latest"

    defines 
    {
    "VEG_PLATFORM_WINDOWS",
    "VEG_BUILD_DLL"
    }
   
    postbuildcommands
    {
    ("{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. outputdir .. "\\Sandbox") 
    }      

filter "configurations:Debug"
	  defines "VEG_DEBUG"
	  symbols "On"

filter "configurations:Release"
	  defines "VEG_RELEASE"
	  optimize "On"

filter "configurations:Dist"
	  defines "VEG_DIST"
	  optimize "On"
   
   -------------------------------------------SANDBOX-------------------------------------------
project "Sandbox"

location "Sandbox"
   
      kind "ConsoleApp"
   
      language "C++"
   
      targetdir ("bin/"..outputdir.."/%{prj.name}")
   
      objdir ("bin-int/"..outputdir.."/%{prj.name}")
   
      files 
      {
      "%{prj.name}/source/**.h",
      "%{prj.name}/source/**.cpp"
      } 
   
      includedirs
      {
       "Vega/vendor/spdlog/include;",
       "Vega/source;"
      }

      links
      {
            "Vega"
      }
   
   filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"
   
      defines 
      {
      "VEG_PLATFORM_WINDOWS"
      }
   
   filter "configurations:Debug"
   	  defines "VEG_DEBUG"
   	  symbols "On"
   
   filter "configurations:Release"
   	  defines "VEG_RELEASE"
   	  optimize "On"
   
   filter "configurations:Dist"
   	  defines "VEG_DIST"
   	  optimize "On"
         