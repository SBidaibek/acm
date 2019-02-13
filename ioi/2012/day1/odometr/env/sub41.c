left
left
move
cycvert:
    pebble veggypebble
    border breakvert
    move
    jump cycvert
    outveggypebble:
jump cycvert
veggypebble:
    get
    left
    left
    cyckek:
        border brekek
        move
    jump cyckek
    brekek:
    left
    left
    put
    move
jump outveggypebble
breakvert:

right
right
while1:
    border breakbed
    put
    move
jump while1
breakbed:

right
move
cyc0:
    pebble fruttypebble
    border break0
    move
    jump cyc0
    outfruttypebble:
jump cyc0
fruttypebble:
    get
    left
    left
    cyc01:
        border break01
        move
    jump cyc01
    break01:
    left
    left
    put
    move
jump outfruttypebble
break0:

left
left
move
cycvert123:
    pebble veggypebble123
    border breakvert123
    move
    jump cycvert123
    outveggypebble123:
jump cycvert123
veggypebble123:
    get
    left
    left
    cyckek123:
        border brekek123
        move
    jump cyckek123
    brekek123:
    left
    cyckek456:
        border brekek456
        move
    jump cyckek456
    brekek456:
    left
    left
    put
    cyckek789:
        border brekek789
        move
    jump cyckek789
    brekek789:
    right
jump outveggypebble123
breakvert123:

right
right
while1123:
    put
    border breakbed123
    move
jump while1123
breakbed123:
right

cyc1:
    right
    border clear1
    move
    right
    move
    cyc11:
        pebble get1
        outget1:
        #border break11
        move
    jump cyc11
    break11:

    left
    border clear2
    move
    left
    move
    cyc12:
        pebble get2
        outget2:
        #border break12
        move
    jump cyc12
    break12:
jump cyc1
break1:

halt

get1:
    border break11
    right
    get1cyc0:
        border get1break0
        move
    jump get1cyc0
    get1break0:

    left
    put
    get1cyc1:
        border get1break1
        move
    jump get1cyc1
    get1break1:

    right
    right
    put
    move
    get1cyc2:
        pebble get1break2
        move
    jump get1cyc2
    get1break2:

    right
    get
    get1cyc3:
        pebble get1break3
        move
    jump get1cyc3
    get1break3:

    get
    right
jump outget1

get2:
    border break12
    left
    get2cyc0:
        border get2break0
        move
    jump get2cyc0
    get2break0:

    left
    put
    get2cyc1:
        border get2break1
        move
    jump get2cyc1
    get2break1:

    right
    right
    put
    move
    get2cyc2:
        pebble get2break2
        move
    jump get2cyc2
    get2break2:

    right
    get
    get2cyc3:
        pebble get2break3
        move
    jump get2cyc3
    get2break3:

    get
    left
jump outget2

clear1:
    right
    right
    lastwhile1:
        get
        border lastbreak1
        move
    jump lastwhile1
    lastbreak1:
    left
    lastwhile2:
        border lastbreak2
        move
    jump lastwhile2
    lastbreak2:
    left
    move
    lastwhile3:
        get
        border lastbreak3
        move
    jump lastwhile3
    lastbreak3:
jump break1

clear2:
    halt
    right
    right
    fastwhile1:
        border fastbreak1
        get
        move
    jump fastwhile1
    fastbreak1:
    right
    fastwhile2:
        border fastbreak2
        move
    jump fastwhile2
    fastbreak2:
    right
    fastwhile3:
        get
        border fastbreak3
        move
    jump fastwhile3
    fastbreak3:
jump break1
