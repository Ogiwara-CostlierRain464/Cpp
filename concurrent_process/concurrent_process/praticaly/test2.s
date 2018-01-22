	.file	"test2.c"
	.globl	_a
	.bss
	.align 8
_a:
	.space 8
	.section .rdata,"dr"
LC0:
	.ascii "LONG LONG VALUE HAS BROKEN!!!\0"
	.text
	.globl	_check
	.def	_check;	.scl	2;	.type	32;	.endef
_check:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	_a, %eax
	movl	_a+4, %edx
	movl	%eax, %ecx
	xorl	$1, %ecx
	orl	%edx, %ecx
	movl	%ecx, %eax
	testl	%eax, %eax
	je	L3
	movl	_a, %eax
	movl	_a+4, %edx
	movl	%edx, %ecx
	xorl	$-1, %ecx
	xorl	$-1, %eax
	orl	%ecx, %eax
	testl	%eax, %eax
	je	L3
	movl	$LC0, (%esp)
	call	_printf
L3:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.section .rdata,"dr"
LC1:
	.ascii "SUB FINISHED\0"
	.text
	.globl	_func
	.def	_func;	.scl	2;	.type	32;	.endef
_func:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L5
L6:
	movl	$1, _a
	movl	$0, _a+4
	call	_check
	addl	$1, -12(%ebp)
L5:
	cmpl	$49999, -12(%ebp)
	jle	L6
	movl	$LC1, (%esp)
	call	_printf
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC2:
	.ascii "MAIN FINISHED\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$0, 12(%esp)
	movl	$_func, 8(%esp)
	movl	$0, 4(%esp)
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	_pthread_create
	movl	$0, 28(%esp)
	jmp	L8
L9:
	movl	$-1, _a
	movl	$-1, _a+4
	call	_check
	addl	$1, 28(%esp)
L8:
	cmpl	$49999, 28(%esp)
	jle	L9
	movl	$0, 8(%esp)
	movl	20(%esp), %eax
	movl	24(%esp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_pthread_join
	movl	$LC2, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.ident	"GCC: (GNU) 5.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_pthread_create;	.scl	2;	.type	32;	.endef
	.def	_pthread_join;	.scl	2;	.type	32;	.endef
