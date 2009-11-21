.rodata
.balign 32
.globl pic2length
.globl pic2data

pic2length:	.long	picdataend - pic2data
pic2data:
.incbin "../images/level2.jpg"
picdataend:


