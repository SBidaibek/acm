Program grader;
uses tournament;
const
   inbuf_len  = 1 shl 16;
   outbuf_len = 1 shl 16;
var
   N, C, R, i, pos : longint;
   K, S, E	   : array of LongInt;
   inbuf	   : array [1..inbuf_len] of Byte;
   outbuf	   : array [1..outbuf_len] of Byte;

begin
   { Set input and output buffering }
   settextbuf(input, inbuf);
   settextbuf(output, outbuf);

   readln(N, C, R);
   setlength(K, N-1);
   setlength(S, C);
   setlength(E, C);
   for i := 0 to N-2 do
      readln(K[i]);
   for i := 0 to C-1 do
      readln(S[i], E[i]);
   pos := GetBestPosition(N, C, R, K, S, E);
   writeln(pos);
end.