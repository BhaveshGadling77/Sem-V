	.file	"a.c"
	.text
.globl a
	.type	a, @function
a:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$13, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.size	a, .-a
	.ident	"GCC: (Ubuntu 4.4.1-4ubuntu9) 4.4.1"
	.section	.note.GNU-stack,"",@progbits
