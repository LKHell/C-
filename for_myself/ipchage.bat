@echo off
rem //设置变量 
set NAME="Wi-Fi"
rem //以下属性值可以根据需要更改
set ADDR=10.0.1.114
set MASK=255.255.255.0
set GATEWAY=10.0.1.2
set DNS1=10.0.1.2
set DNS2=
rem //以上属性依次为IP地址、子网掩码、网关、首选DNS、备用DNS
REM show ip

ipconfig

echo now you can_set:
echo 1 mobile
echo 2 mobile  8.8.8.8
echo 3 telecom 
echo 4 DHCP
echo 5 exit
echo insert and enter:
set /p operate=
if %operate%==1 goto 1

if %operate%==2 (       
    set DNS1=8.8.8.8
    goto 1    
)

if %operate%==3 (       
    set GATEWAY=10.0.1.1
    set DNS1=10.0.1.1
    goto 1    
)

if %operate%==4 goto 2

if %operate%==5 goto 3

:1
echo waiting
rem //可以根据你的需要更改 
echo IP_ = %ADDR%
echo MASK_ = %MASK%
echo Gateway_ = %GATEWAY%
netsh interface ipv4 set address %NAME% static %ADDR% %MASK% %GATEWAY% 
echo DNS1 = %DNS1% 
netsh interface ipv4 set dns %NAME% static %DNS1% validate=no
echo DNS2 = %DNS2% 
if "%DNS2%"=="" (echo DNS2 null) else (netsh interface ipv4 add dns %NAME% %DNS2%) 
echo done!
pause
goto 3


:2
echo waiting
REM echo 正在从DHCP自动获取IP地址...
netsh interface ip set address %NAME% dhcp
REM echo 正在从DHCP自动获取DNS地址...
netsh interface ip set dns %NAME% dhcp 
echo done!
pause
goto 3

:3
exit