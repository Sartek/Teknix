local libSFML = "../dependencies/SFML/build/lib"
local includeSFML = "../dependencies/SFML/include"
local libBox2D = "../dependencies/box2d-2.4.2/build/bin"
local includeBox2D = "../dependencies/box2d-2.4.2/include"

workspace "Teknix"
	configurations { "Debug", "Release" }
	location "build"
	
project "Teknix"
	location "build"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin"
	
	files { "src/*.h", "src/*.cpp" }
	
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
		links { "box2d", "sfml-system-d", "sfml-window-d", "sfml-graphics-d" }
		libdirs { libSFML, libBox2D }
		includedirs { includeSFML, includeBox2D }
		targetsuffix "-d"
		
	filter "configurations:Release"
		defines { "NDEBUG" }
		flags { }
		linktimeoptimization "On"
		optimize "Full"
		links { "box2d", "sfml-system", "sfml-window", "sfml-graphics" }
		libdirs { libSFML, libBox2D}
		includedirs { includeSFML, includeBox2D }