workspace "calendar"
    architecture "x64"
    startproject "calendar"

    configurations {
        "Debug", 
        "Release",
    }

output_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

for_include = {}
for_include["imgui"] = "%{wks.location}/calendar/vendor/imgui"
for_include["imgui-sfml"] = "%{wks.location}/calendar/vendor/imgui-sfml"
for_include["sfml"] = "%{wks.location}/calendar/vendor/sfml/include"

libs = {}
libs["sfml"] = "%{wks.location}/calendar/vendor/sfml/lib"

group "dependencies"
    include "calendar/vendor/imgui"
    include "calendar/vendor/imgui-sfml"
group ""

group "app"
    include "calendar"
group ""

