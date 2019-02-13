Program grader;
uses rings;
const
   inbuf_len  = 1 shl 16;
   outbuf_len = 1 shl 16;
var
   N, L, i, a, b, critical : longint;
   inbuf	           : array [1..inbuf_len] of Byte;
   outbuf	           : array [1..outbuf_len] of Byte;

begin
   { Set input and output buffering }
   settextbuf(input, inbuf);
   settextbuf(output, outbuf);

   readln(N, L);
   Init(N);
   for i := 1 to L do begin
      read(a);
      if a = -1 then begin
	 critical := CountCritical();
	 writeln(critical);
      end else begin
	 readln(b);
	 Link(a, b);
      end;
   end;
end.
