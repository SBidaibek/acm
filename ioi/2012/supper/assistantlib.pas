Unit assistantlib;

interface
procedure AssistantInit(N, K : LongInt);
function GetRequest : LongInt;
procedure PutBack(T : LongInt);

implementation
uses advisorlib;

var
   in_scaffold     : Array of LongInt;
   current_request : LongInt;
   expect_put_back : Byte;

procedure AssistantInit(N, K : LongInt);
var
   i : LongInt;
begin
   setlength(in_scaffold, N);
   for i := 0 to K-1 do
      in_scaffold[i] := 1;
   for i := K to N-1 do
      in_scaffold[i] := 0;
   current_request := -1;
   expect_put_back := 0;
end;

function GetRequest: LongInt;
var
   req : LongInt;
begin
   if expect_put_back <> 0 then begin
      writeln(stderr, 'Not putting back color when it is not on the scaffold');
      halt(1);
   end;

   current_request := current_request + 1;
   req := C[current_request];

   if in_scaffold[req] = 0 then
      expect_put_back := 1
   else
      expect_put_back := 0;

   writeln('R ', req);
   GetRequest := req;
end;

procedure PutBack(T : LongInt);
var
   req : LongInt;
begin
   if expect_put_back = 0 then begin
      writeln(stderr, 'Putting back a color when it is already on the scaffold');
      halt(1);
   end;

   if in_scaffold[T] = 0 then begin
      writeln(stderr, 'Putting back a color that is not on the scaffold');
      halt(1);
   end;

   req := C[current_request];
   in_scaffold[req] := 1;
   in_scaffold[T] := 0;
   expect_put_back := 0;

   writeln('P ', T);
end;

end.
