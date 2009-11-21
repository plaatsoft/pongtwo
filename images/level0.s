.rodata
.balign 32
.globl pic0length
.globl pic0data

pic0length:	.long	picdataend - pic0data
pic0data:
.incbin "../images/level0.jpg"
picdataend:


