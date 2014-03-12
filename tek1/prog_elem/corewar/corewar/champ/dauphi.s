.name		"dauphi"
.comment	"j'aime les dauphi"

start:
	sti	r1,%:live,%1
	sti	r1,%:sun,%1
	ld	%4,r5
	ld	%:end,r6
	ld	%:end,r7
	fork	%:tir
live:
	live	%1
	zjmp	%:live
sun:
	live	%1
	ld	%0,r2
	fork	%:live
	zjmp	%:sun
	zjmp	%:sun
tir:
	st	r1,r6
	add	r5,r6,r6
	fork	%:tir
	zjmp	%:sun
	zjmp	%:sun
end:
