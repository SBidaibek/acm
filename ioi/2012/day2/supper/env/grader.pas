Program grader;
uses advisor, advisorlib, assistant, assistantlib;
const
   inbuf_len  = 1 shl 16;
   outbuf_len = 1 shl 16;
var
   N, K, i : LongInt;
   inbuf      : array [1..inbuf_len] of Byte;
   outbuf     : array [1..outbuf_len] of Byte;

begin
   { Set input and output buffering }
   settextbuf(input, inbuf);
   settextbuf(output, outbuf);

   readln(N, K, M);
   AdvisorInit();
   setlength(C, N);
   for i := 0 to N-1 do
      read(C[i]);
   ComputeAdvice(C, N, K, M);
   AdvisorFini();

   AssistantInit(N, K);
   Assist(A, N, K, R);
end.
