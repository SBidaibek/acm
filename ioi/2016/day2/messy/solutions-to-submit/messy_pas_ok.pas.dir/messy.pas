// name = messy_pas_ok.pas, type = pas.fpc

unit messy;

interface

type TIntArray = array of longint;

function restore_permutation(n, w, r: longint) : TIntArray;


implementation

uses graderlib;

type
  nodep = ^node;
  node = Record
    zero, one: ^node;
  end;


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


end.

