program grader;

uses ricehub, graderhelplib;

type
besthubFunction = function (n : longint; L : longint; X : array of longint; B : int64) : longint; cdecl;

{$L graderlib.o}
{$IFDEF MSWINDOWS}
{$linklib msvcrt}
{$ELSE}
{$linklib c}
{$ENDIF}

procedure _main(besthub : besthubFunction); cdecl; external;

begin
    _main(@besthub);
end.
