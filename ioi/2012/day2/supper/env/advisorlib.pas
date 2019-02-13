Unit advisorlib;

interface
var
   A : Array of Byte;
   C : Array of LongInt;
   M, R    : LongInt;

procedure AdvisorInit();
procedure AdvisorFini();
procedure WriteAdvice(c : Byte);

implementation
var
   fadvice : Text;

procedure AdvisorInit();
begin
   R := 0;
   setlength(A, M);
   Assign(fadvice, 'advice.txt');
   Rewrite(fadvice);
end;

procedure AdvisorFini();
begin
   writeln(fadvice);
   writeln(fadvice, '2');
   close(fadvice);
end;

procedure WriteAdvice(c : Byte);
begin
   if c <> 0 then
      c := 1;

   if R < M then begin
      write(fadvice, c, ' ');
      A[R] := c;
      R := R + 1;
   end else begin
      writeln(stderr, 'Advisor is providing too many bits of advice');
      halt(1);
   end;
end;

end.
