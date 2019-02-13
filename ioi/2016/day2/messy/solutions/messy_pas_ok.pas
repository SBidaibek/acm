type
  nodep = ^node;
  node = Record
    zero, one: ^node;
  end;

// BEGIN CUT
type
    TIntArray = array of longint;
// END CUT
var
  n, w, r, i: longint;
  p, answer: array of longint;
  ok: boolean;
  nn: longint;
  address: string;
  initialized: boolean = false;
  compiled: boolean;
  nodeSet: nodep;


  function create(): nodep;
var
  res: nodep;
begin
  res := new(nodep);
  res^.zero := NIL;
  res^.one := NIL;
  create := res;
end;

procedure wa();
begin
  writeln('WA');
  halt;
end;

// BEGIN CUT
procedure init_grader(n_, w_, r_: longint; p_: array of longint);
var
  i: longint;
begin
  if initialized then
     wa;
  n := n_;
  w := w_;
  r := r_;
  setLength(p, n);
  for i := 0 to n - 1 do
      p[i] := p_[i];
  initialized := true;
  nodeSet := create();
  compiled := false;
end;

function check(x: string): Boolean;
var
  i: longint;
  res: boolean;
begin
  res := true;
  if length(x) <> n then
    res := false
  else begin
    for i := 0 to n - 1 do
        if (x[i + 1] <> '0') and (x[i + 1] <> '1') then
           res := false;
  end;
  check := res;
end;

procedure addImpl(nodeSet: nodep; x: string; at: longint);
begin
  if at <> n then begin
    if x[at + 1] = '0' then begin
      if nodeSet^.zero = nil then
         nodeSet^.zero := create();
      addImpl(nodeSet^.zero, x, at + 1);
    end else begin
      if nodeSet^.one = nil then
         nodeSet^.one := create();
      addImpl(nodeSet^.one, x, at + 1);
    end;
  end;
end;

procedure add_element(x: string);
begin
  dec(w);
  if (w < 0) or compiled or (not check(x)) then
     wa;
  addImpl(nodeSet, x, 0);
end;

function check_element(x: string):boolean;
var
  res: Boolean;
  i: LongInt;
  cur: nodep;
begin
  dec(r);
  if (w < 0) or (not compiled) or (not check(x)) then
     wa;
  res := true;
  cur := nodeSet;
  for i := 0 to n - 1 do begin
    if x[i + 1] = '0' then begin
      if cur^.zero = nil then begin
        res := false;
        break;
      end;
      cur := cur^.zero;
    end else begin
      if cur^.one = nil then begin
        res := false;
        break;
      end;
      cur := cur^.one;
    end;
  end;
  check_element := res;
end;

procedure compile(nodeSet: nodep; at: longint; compiledSet: nodep; elem, compElem: string);
var
  i: longint;
begin
  if at = n then begin
    for i := 0 to n - 1 do
      compElem[i + 1] := elem[p[i] + 1];
    addImpl(compiledSet, compElem, 0);
    exit;
  end;
  if nodeSet^.zero <> nil then begin
    elem[at + 1] := '0';
    compile(nodeSet^.zero, at + 1, compiledSet, elem, compElem);
  end;
  if nodeSet^.one <> nil then begin
    elem[at + 1] := '1';
    compile(nodeSet^.one, at + 1, compiledSet, elem, compElem);
  end;
end;

procedure compile_set();
var
  compSet: nodep;
  elem, compElem: string;
begin
  if compiled then
     wa;
  compiled := true;
  setLength(elem, n);
  setLength(compElem, n);
  compSet := create();
  compile(nodeSet, 0, compSet, elem, compElem);
  nodeSet := compSet;
end;

// END CUT

procedure fill(c: char);
var
  i: longint;
begin
  for i := 1 to nn do
    address[i] := c;
end;

procedure helper(length, w: longint);
var
  i, j, shift: longint;
begin
  fill('1');
  i := w;
  shift := 1 shl length;
  while i < nn do begin
    address[i + 1] := '0';
    inc(i, shift);
  end;
  j := w;
  for i := 0 to nn div shift - 1 do begin
    address[j + 1] := '1';
    if i mod 2 = 1 then
       add_element(address);
    address[j + 1] := '0';
    inc(j, shift);
  end;
end;

procedure doWrites(n_: longint);
var
  i, x, log, length, shift: longint;
begin
  nn := n_;
  setLength(address, nn);
  for i := 0 to nn - 1 do begin
    fill('0');
    address[i + 1] := '1';
    if i mod 2 = 1 then
       add_element(address);
  end;
  x := 1;
  log := 0;
  while x < nn do begin
    x := x * 2;
    inc(log);
  end;
  for length := 1 to log - 1 do begin
    shift := 1 shl length;
    for i := 0 to shift - 1 do
      helper(length, i);
  end;
end;

procedure readImpl(t: array of longint; tSize: longint; var answer: array of longint; step, w: longint);
var
  t0, t1: array of longint;
  at0, at1, i, j: longint;
begin
  if tSize = 1 then begin
    answer[t[0]] := w;
    exit;
  end;
  setLength(t0, tSize div 2);
  setLength(t1, tSize div 2);
  at0 := 0;
  at1 := 0;
  fill('1');
  for j := 0 to tSize - 1 do
    address[t[j] + 1] := '0';
  for i := 0 to tSize - 1 do begin
    j := t[i];
    address[j + 1] := '1';
    if not check_element(address) then begin
      t0[at0] := j;
      inc(at0);
    end else begin
      t1[at1] := j;
      inc(at1);
    end;
    address[j + 1] := '0';
  end;
  readImpl(t0, tSize div 2, answer, step + 1, w);
  readImpl(t1, tSize div 2, answer, step + 1, w + (1 shl step));
end;

procedure doReads(n: longint; var answer: array of longint);
var
  order: array of longint;
  i: longint;
begin
  setLength(order, n);
  for i := 0 to n - 1 do
    order[i] := i;
  readImpl(order, n, answer, 0, 0);
end;

function restore_permutation(n, w, r: longint) : TIntArray;
var
    answer : array of longint;
begin
  doWrites(n);
  compile_set;
  setlength(answer, n);
  doReads(n, answer);
  restore_permutation := answer;
end;

// BEGIN CUT
begin
  read(n, w, r);
  setLength(p, n);
  for i := 0 to n - 1 do
    read(p[i]);
  writeln('098d134608c94f7413faac591054ee35');
  init_grader(n, w, r, p);
  setLength(answer, n);
  answer := restore_permutation(n, w, r);
  ok := true;
  for i := 0 to n - 1 do
    if p[i] <> answer[i] then
      ok := false;
  if ok then
    writeln('OK')
  else
    writeln('WA');
  write(answer[0]);
  for i := 1 to n - 1 do begin
    write(' ');
    write(answer[i]);
  end;
  writeln;

// END CUT
end.

