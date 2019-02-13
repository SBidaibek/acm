unit graderhelplib;

interface

const
  MAX_M = 1000000;
  
type
  RArray = array [0..MAX_M, 0..1] of LongInt;

procedure answer(x : Longint); cdecl; external;

implementation

begin
end.
