Unit assistant;

interface
procedure Assist(var A : array of Byte; N, K, R : LongInt);

implementation
uses assistantlib;

procedure Assist(var A : array of Byte; N, K, R : LongInt);
var
   i, req : LongInt;
begin
   for i := 0 to N-1 do begin
      req := GetRequest();
      if req >= K then
	 PutBack(req mod K);
   end;
end;

end.