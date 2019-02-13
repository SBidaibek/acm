left
cyc1:
    pebble skip1
        cyc2:
            left
            #
            move
            pebble skip3
                left
                left
                move
                halt
            skip3:
            get
            left
            left
            move
            put
            #
            right
            move
            right
            #
            move
            get
            left
            left
            move
            put
            #
            left
            move
        jump cyc2
    skip1:

    get
    left
    move
    put
    left
    left
    move
    right
    move

    pebble skip2
        left
        left
        move
        left
        move
        get
        left
        left
        move
        put
        right
        move
        cyc3:
            right
            #
            move
            pebble skip4
                left
                left
                move
                halt
            skip4:
            get
            left
            left
            move
                put
            #
            left
            move
            left
            #
            move
            get
            left
            left
            move
            put
            #
            right
            move
        jump cyc3
    skip2:

    get
    right
    move
    put
    right
    right
    move
    left
    move

jump cyc1

