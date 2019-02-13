unit quality;
interface
   type Qtype = array [0..3000,0..3000] of longint;
   function rectangle(R,C,H,W: longint; var Q:Qtype): longint;
implementation
   function rectangle(R,C,H,W: longint; var Q:Qtype): longint;
   begin
      rectangle := R*C div 2;
   end;
begin
end.
