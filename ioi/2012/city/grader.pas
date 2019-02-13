Program grader;
uses city;
const
   inbuf_len  = 1 shl 16;
   outbuf_len = 1 shl 16;
var
   N, i	      : LongInt;
   sq_x, sq_y : array of LongInt;
   inbuf      : array [1..inbuf_len] of Byte;
   outbuf     : array [1..outbuf_len] of Byte;

begin
   { Set input and output buffering }
   settextbuf(input, inbuf);
   settextbuf(output, outbuf);

   readln(N);
   setlength(sq_x, N);
   setlength(sq_y, N);
   for i := 0 to N-1 do
      readln(sq_x[i], sq_y[i]);
   writeln(DistanceSum(N, sq_x, sq_y));
end.