.name 		"dtonc v1.0pl4"
.comment	"ta mere elle fait du rodeo sur les kfar"
.extend

debut:
	st	r1, :li1+1
	st	r1, :li2+1
	ld	%100, r4
	ld	%45, r5
	ld	%0, r3

li1:
	live	%42
cp:
	sti	r2, %400, r3
	add	r3, r6, r3
	sub	r3, r4, r5
li2:
	live	%1
	zjmp	%:li1
	ld	%0, r5
	zjmp	%:cp