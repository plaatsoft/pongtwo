.rodata
.balign 32
.globl pic8length
.globl pic8data

pic8length:	.long	picdataend - pic8data
pic8data:
.incbin "../images/intro1.jpg"
picdataend:


