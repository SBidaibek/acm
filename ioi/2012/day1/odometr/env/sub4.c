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

cyc1:
    right
    border break1
    move
    right
    cyc11:
        pebble get1
        outget1:
        border break11
        move
    jump cyc11
    break11:

    left
    border break1
    move
    left
    cyc12:
        pebble get2
        outget2:
        border break12
        move
    jump cyc12
    break12:
jump cyc1
break1:

halt

get1:
    border spec1
    ##get
    right
    ##put
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

    outspec1:
    get
    right
jump outget1

spec1:
    right
    spec1cyc0:
        border spec1break0
        move
    jump spec1cyc0
    spec1break0:
    put
    right
    right
    move
    spec1cyc1:
        pebble spec1break1
        move
    jump spec1cyc1
    spec1break1:
jump outspec1

get2:
    left
    left
    border spec2
    right
    right
    ##get
    left
    ##put
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

    outspec2:
    get
    left
jump outget2

spec2:
    right
    spec2cyc0:
        border spec2break0
        move
    jump spec2cyc0
    spec2break0:
    put
    right
    right
    move
    spec2cyc1:
        pebble spec2break1
        move
    jump spec2cyc1
    spec2break1:
jump outspec2
