workspace "prumath"
	configurations {
		"Debug32", "Release32", "Debug64", "Release64"
	}

	filter "configurations:Debug*"
		optimize "Off"

	filter "configurations:Release*"
		optimize "On"

	filter "configurations:*32"
		architecture "x86"

	filter "configurations:*64"
		architecture "x86_64"

	project "prumath"
		kind "StaticLib"
		language "C++"
		cppdialect "C++20"

		targetdir "%{prj.location}/lib/"
		objdir "%{prj.location}/obj/"

		files "src/**.cpp"
