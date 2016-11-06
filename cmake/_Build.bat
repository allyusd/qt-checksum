SET CMAKE_PREFIX_PATH=C:/Qt/5.7/msvc2015
SET PATH=%PATH%;C:\Program Files (x86)\MSBuild\14.0\Bin
SET BuildPath=_build

sh run.sh

for %%i in (%BuildPath%/*.sln) do msbuild %BuildPath%/%%~i