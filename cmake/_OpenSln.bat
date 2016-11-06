SET PATH=%PATH%;C:/Qt/5.7/msvc2015/bin
SET BuildPath=_build

for %%i in (%BuildPath%/*.sln) do START %BuildPath%/%%~i
