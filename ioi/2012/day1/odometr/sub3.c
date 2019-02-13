right
cyc0:
    pebble break0
    move
jump cyc0
break0:

cyc1:
    cyc2:
        move
        pebble link1
        jump cyc2
        link1:
            left
            left
            move
            put
            move
            pebble turnaround
            jump break2
    jump cyc2
    break2:
    cyc3:
        pebble link2
        move
        jump cyc3
        link2:
            right
            right
            move
            put
            jump break3
    jump cyc3
    break3:
jump cyc1

turnaround:
left
left
move
