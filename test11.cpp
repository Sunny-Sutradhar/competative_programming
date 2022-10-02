lw $s0, 20($s1)
add $s2, $s0, $t1
or $s3, $s3, $t2
and $t2, $s1, $s3
addi $t0,$s1,$s3
       
lw  =  IF | ID | EX | MEM | WB
add =       IF |    |     | ID | EX  | MEM | WB
or  =            IF | ID  | EX | MEM | WB
and =                 IF  |    |     | ID | EX | MEM | WB
addi=                       IF |     |    | ID | EX  | MEM | WB

11*300 = 3300 ps


lw  =  IF | ID | EX^ | MEM | WB
add =       IF | ID  | ... | EX | MEM | WB
or  =            IF  | ID  |    | EX  | MEM | WB
and =                | IF  | ID |     | EX^ | MEM | WB
addi=                      | IF | ID  |     | EX^  | MEM| WB

10*300 = 3000 ps

