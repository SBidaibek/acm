Unit advisor;

interface
procedure ComputeAdvice(var C : array of LongInt; N, K, M : LongInt);

implementation
uses advisorlib;

procedure ComputeAdvice(var C : array of LongInt; N, K, M : LongInt);
begin
   WriteAdvice(0);
   WriteAdvice(1);
   WriteAdvice(2);
end;

end.