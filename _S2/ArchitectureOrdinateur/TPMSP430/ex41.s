.section .init9
main:
	mov   #0, &34
	mov.b #2, &50   /* initialisation de la diode */
	mov   #2, r15   /* valeur initiale de la valeur de la diode */
	mov   #0, r14   /*init r14 à 0*/
	mov   #2, r12
	mov   #0, r10   /* init sleep counter */
	mov   #40000, r11 /* sleep constant */
	mov   #0, r13  /* pause counter */	

waitpressed:
	mov.b &32, r14
	cmp r14, r12
	jne waitpressed
	jmp waitreleased	

waitreleased: 
	call #pause
	inc r13
	mov.b &32, r14
	cmp r14, r12
	jeq waitreleased
	jmp toggle	

toggle: 
	call #pause
	mov.b r15, &49  /* transferer r15 vers la diode */
	xor #2, r15     /* que fait cette ligne? */
	dec r13
	cmp r13, r10
	jne toggle
	jmp waitpressed

pause:
	inc r10
	cmp r11, r10
        jne pause
	mov #0, r10
	ret
