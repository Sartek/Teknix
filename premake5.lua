local libSFML = "../../libaries/c++/bin/SFML/lib"
local includeSFML = "../../libaries/c++/bin/SFML/include"
local libBox2D = "../../libaries/c++/bin/Box2D/lib"
local includeBox2D = "../../libaries/c++/bin/Box2D/include"

workspace "Teknix"
	configurations { "Debug", "Release" }
	location "build"
	
project "Teknix"
	location "build"
	kind "WindowedApp"
	language "C++"
	targetdir "bin"
	
	files { "src/*.h", "src/*.cpp" }
	
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
		links { "Debug/Box2D", "sfml-system-d", "sfml-window-d", "sfml-graphics-d" }
		libdirs { libSFML, libBox2D .. "/Debug" }
		includedirs { includeSFML, includeBox2D }
		targetsuffix "-d"
		
	filter "configurations:Release"
		defines { "NDEBUG" }
		flags { "LinkTimeOptimization" }
		optimize "Full"
		links { "Box2D", "sfml-system", "sfml-window", "sfml-graphics" }
		libdirs { libSFML, libBox2D .. "/Release"}
		includedirs { includeSFML, includeBox2D }