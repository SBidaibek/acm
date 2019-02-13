for /L %%i in (1, 1, 10) do (
set /A j=%%i+1
ren 0%%i.out %j%.out
) 