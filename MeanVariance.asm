; Programmer Name: Marco Seman
; CIS 310 Assembly Language
; Professor: David Yoon
; February 26, 2018
; Find the Mean and variance of the given numbers
; Mean: 18
; Variance: 57

INCLUDE Irvine32.inc

.data
	; List of numbers, variance, and mean
    list DWORD 8, 19, 14, 27, 6, 20, 18, 12, 23, 27, 31, 22, 17, 26, 7
	variance DWORD ? 
	mean DWORD ?
	sqNum DWORD ?
	change DWORD ?
	ab DWORD LENGTHOF list

.code
main PROC
	
	;initiate values that are in my default list
	mov esi, OFFSET list
	mov ecx, ab
	mov eax, 0


	;Loop to find the mean
	meanloop: 
	   mov eax, change 
	   add eax, [esi] ; add from array and current
	   mov change, eax ; move it to the next value
	   add esi, TYPE list  
	loop meanloop ; end of loop for mean
	; ends with 277 

	mov eax, change ; 277
	mov edx, 0

	div ab ; divide by list of array which is 15
	mov mean, eax ; make the word "mean" into 18


	; for the output of MEAN
	mov edx, OFFSET OutputMean
	call WriteString
	mov edx, OFFSET Endline
	call writeint
	call writestring

	; reset values
	mov eax, 0
	mov esi, OFFSET list
	mov ecx, ab

	VarianceLoop:
		mov eax, [esi] 
		sub eax, mean ; subtract each number by the mean
		mul eax

		add sqNum, eax ;squaring the number, only the last value is relevant
		add esi, TYPE list
	loop VarianceLoop ; end the variance loop where there should end up being 57

	mov edx, 0
	mov eax, sqNum
	div ab
	mov variance, eax
	mov edx, OFFSET OutputVariance


	; for printing the characters:
	call writestring
	call writeint
	mov edx, OFFSET Endline ;for the output line
	call writestring

	exit ; end of program

	; output for solution, should be +18 for mean, + 57 for variance
	Endline BYTE '  ', 10, 8, 0
	OutputMean BYTE "MEAN: ", 0
	OutputVariance BYTE "VAR:  ", 0

main ENDP
END main