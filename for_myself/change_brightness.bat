rem //The two commands for setting any power settings are powercfg -SetDcValueIndex and powercfg -SetAcValueIndex, depending if you want to change setting when on batteries or on AC power.
@echo off
for /f "tokens=*" %%i in ('powercfg -q ^| find "Power Scheme GUID"') do set pwrSchm=%%i
set pwrSchm=%pwrSchm:~19,36%

for /f "tokens=*" %%i in ('powercfg -q ^| find "(Display)"') do set dsply=%%i
set dsply=%dsply:~15,36%

for /f "tokens=*" %%i in ('powercfg -q ^| find "(Display brightness)"') do set brtnss=%%i
set brtnss=%brtnss:~20,36%

Echo.Power Scheme GUID : %pwrSchm%
Echo.Display GUID : %dsply%
Echo.Display brightness : %brtnss%

rem //输入亮度值

set /P brightness=Enter Number to change System Brightness : % brightness: %=%
powercfg -SetDcValueIndex %pwrSchm% %dsply% %brtnss% %brightness%

rem //POWERCFG -SETDCVALUEINDEX <SCHEME_GUID> <SUBGROUP_GUID> <SETTING_GUID>  <SETTING_INDEX> 

powercfg -S %pwrSchm%