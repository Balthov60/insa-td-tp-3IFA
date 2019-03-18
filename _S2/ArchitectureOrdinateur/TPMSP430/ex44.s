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
	mov   #0, r9  /* blinkn counter */

waitpressed:
	mov.b &32, r14
	cmp r14, r12
	jne waitpressed
	jmp waitreleased	

waitreleased: 
	call #pause
	/* inc r13 */
	mov.b &32, r14
	cmp r14, r12
	jeq waitreleased
	mov #5, r13
	call #blinkn	

toggle: 
	mov.b r15, &49  /* transferer r15 vers la diode */
	xor #2, r15     /* que fait cette ligne? */

pause:
	inc r10
	cmp r11, r10
        jne pause
	mov #0, r10
	ret

blinkn:
	call #pause
	call #toggle
	call #pause
	call #toggle
	inc r9
	cmp r9, r13
	jne blinkn
	mov #0, r9
	jmp waitpressed
	
