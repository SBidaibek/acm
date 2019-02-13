unit garden;

interface

uses graderhelplib;
procedure count_routes(N : longint; M : longint; P : longint; R : RArray; Q : longint; G : array of longint); cdecl;

implementation

procedure count_routes(N : longint; M : longint; P : longint; R : RArray; Q : longint; G : array of longint); cdecl;
var i : longint;
begin
    for i := 1 to Q do
    begin
       answer(i);
    end
end;

begin
end.

