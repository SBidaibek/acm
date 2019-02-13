Unit scrivener;

interface
procedure Init;
procedure TypeLetter(L : Char);
procedure UndoCommands(U : LongInt);
function GetLetter(P : LongInt) : Char;

implementation
var
   last : Char;

   procedure Init();
   begin
   end;

   procedure TypeLetter(L : Char);
   begin
      last := L;
   end;

   procedure UndoCommands(U : LongInt);
   begin;
   end;

   function GetLetter(P	: LongInt) : Char;
   begin
      GetLetter := last;
   end;

end.			
