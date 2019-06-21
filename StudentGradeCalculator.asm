; Programmer Name: Marco Seman
; CIS 310 Assembly Language
; Professor David Yoon
; March, 5, 2018
; Description: The goal of this program is for the user to enter in a score
; Once the user enters in their score, they will be given a letter grade for the score given
; This is processed by using if statements to make sure the program displays the correct output

include irvine32.inc

.data

mesg byte "     ---------This Program Displays the grade of the Student--------", 0dh, 0ah, 0
newline BYTE ' ', 10, 0, 0
GradeNum BYTE "Enter Grade: ", 0
GradeScore BYTE "SCORE: ", 0
GradeChar BYTE "GRADE: ", 0
okToRegister BYTE ?

mesgA BYTE "A", 10,0
mesgB BYTE "B", 10,0
mesgC BYTE "C", 10,0
mesgD BYTE "D", 10,0
mesgE BYTE "E", 10,0

TRUE = 1
FALSE = 0

.code
main proc

; set defaults
;mov ebx, OFFSET mesg3
mov eax, 0

; display the message on top
mov edx, OFFSET mesg
call writestring

; user enters value here
mov edx, OFFSET GradeNum
call writestring
call readint

; displays the score the user got in integer
mov edx, OFFSET GradeScore
call writestring
call writeint

; Sets up a new line
mov edx, OFFSET newline
call writestring

mov okToRegister, FALSE
; GREATER THAN 90
.IF eax >= 90
	mov okToRegister, TRUE
	
	; Grade Character a
	mov edx, OFFSET GradeChar
	call writestring

	mov edx, OFFSET mesgA
	call writestring ; display A grade

; BETWEEN 80-89
.ELSEIF (eax >= 80) && (eax <= 89)
	mov okToRegister, TRUE	
	
	; Grade Character B
	mov edx, OFFSET GradeChar
	call writestring

	mov edx, OFFSET mesgB
	call writestring ; display B grade

; BETWEEN 70-79
.ELSEIF (eax >= 70) && (eax <= 79)
	mov okToRegister, TRUE

	; Grade Character C
	mov edx, OFFSET GradeChar
	call writestring

	mov edx, OFFSET mesgC 
	call writestring ; display C grade

; BETWEEN 60-69
.ELSEIF (eax >= 60) && (eax <= 69)
	mov okToRegister, TRUE
	
	; Grade Character D
	mov edx, OFFSET GradeChar
	call writestring

	mov edx, OFFSET mesgD ; display D grade
	call writestring
	
; LESS THAN 60
.ELSEIF (eax <= 60)
	mov okToRegister, TRUE
	
	; Grade Character E
	mov edx, OFFSET GradeChar ; display E grade
	call writestring

	mov edx, OFFSET mesgE
	call writestring

.ENDIF ; End of if statement

; Sets up a new line
mov edx, OFFSET newline
call writestring

exit ; end program
main endp
end main