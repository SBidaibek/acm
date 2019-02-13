Unit rings;

interface
procedure Init(N_ : longint);
procedure Link(a, b : longint);
function CountCritical : longint;

implementation
var
   N : longint;

procedure Init(N_ : longint );
begin
   N := N_;
end;

procedure Link(a, b : longint);
begin
end;

function CountCritical : longint;
begin
   CountCritical := N;
end;

end.
