Program grader;
uses scrivener;
const
   inbuf_len  = 1 shl 16;
   outbuf_len = 1 shl 16;
var
   cmdnum, i, index, number : LongInt;
   cmd, letter		    : Char;
   inbuf		    : array [1..inbuf_len] of Byte;
   outbuf		    : array [1..outbuf_len] of Byte;

begin
   { Set input and output buffering }
   settextbuf(input, inbuf);
   settextbuf(output, outbuf);

   Init();
   readln(cmdnum);
   for i := 1 to cmdnum do begin
      read(cmd);
      case cmd of
	'T' : begin
	   { First read the space, then the letter... }
	   read(letter);
	   read(letter);
	   TypeLetter(letter);
	end;
	'U' : begin
	   read(number);
	   UndoCommands(number);
	end;
	'P' : begin
	   read(index);
	   letter := GetLetter(index);
	   writeln(letter);
	end;
      end;
      readln();
   end;
end.