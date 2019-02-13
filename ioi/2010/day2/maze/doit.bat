for /L %%i in (2, 1, 9) do (
 Copy field%%i.txt in
 a.exe
 Copy out %%i.out
)
Copy fieldA.txt in
a.exe
Copy out 10.out