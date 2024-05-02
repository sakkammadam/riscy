** RISCY - Reduced Instruction Set Assembler **
** Instruction set **

e.g.
LOADI R0, #10
--- Immediate Load value 10 into register0

ADDRR R1, R2, R3
--- Add values in Registers R2 and R3 and place it in R1

ADDRI R1, #10
--- Add value 10 to existing value in R1

EQUAL R4, R5, R6
--- Check if registers R5 and R6 have same value and store result (0 or 1) in R4

NQUAL R7, R5, R6
--- Check if registers R5 and R6 have different value and store result (0 or 1) in R7

CLOSE
--- Signal end of program
