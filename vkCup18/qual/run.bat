@echo off
for /L %%i in (1, 1, 100) do (
ping 128.0.0.1 -w 1000 -n 1 > nul
echo test %%i
gen
d
test
)