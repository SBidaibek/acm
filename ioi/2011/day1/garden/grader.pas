program grader;

uses garden, graderhelplib;

type
count_routesFunction = procedure (N : longint; M : longint; P : longint; R : RArray; Q : longint; G : array of longint); cdecl;

{$L graderlib.o}
{$IFDEF MSWINDOWS}
{$linklib msvcrt}
{$ELSE}
{$linklib c}
{$ENDIF}

procedure _main(count_routes : count_routesFunction); cdecl; external;

begin
    _main(@count_routes);
end.
