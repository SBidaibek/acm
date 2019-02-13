unit ricehub;

interface

function besthub(n : longint; L : longint; X : array of longint; B : int64) : longint; cdecl;

implementation

function besthub(n : longint; L : longint; X : array of longint; B : int64) : longint; cdecl;
begin
    besthub := n div 2;
end;

begin
end.
