	.file	"main.c"
	.comm	k,4,4
.globl m
	.data
	.align 4
	.type	m, @object
	.size	m, 4
m:
	.long	111
	.text
.globl b
	.type	b, @function
b:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$10, k
	popl	%ebp
	ret
	.size	b, .-b
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	movl	$5, 12(%esp)
	movl	$10, 8(%esp)
.L4:
	call	a
	movl	%eax, 12(%esp)
	movl	12(%esp), %eax
	movl	8(%esp), %edx
	leal	(%edx,%eax), %eax
	movl	%eax, k
	call	b
	jmp	.L4
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.1-4ubuntu9) 4.4.1"
	.section	.note.GNU-stack,"",@progbits
