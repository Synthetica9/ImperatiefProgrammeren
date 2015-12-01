	.file	"main.cpp"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"main.cpp"
.LC1:
	.string	"n >= 0"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.type	_Z3sumi.part.4, @function
_Z3sumi.part.4:
.LFB8347:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$_ZZ3sumiE19__PRETTY_FUNCTION__, %ecx
	movl	$16, %edx
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	call	__assert_fail
	.cfi_endproc
.LFE8347:
	.size	_Z3sumi.part.4, .-_Z3sumi.part.4
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.text.unlikely
.LCOLDB3:
	.text
.LHOTB3:
	.p2align 4,,15
	.globl	_Z3sumi
	.type	_Z3sumi, @function
_Z3sumi:
.LFB7978:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	testl	%edi, %edi
	js	.L4
	movl	$0, %eax
	je	.L6
	.p2align 4,,10
	.p2align 3
.L11:
	leal	-1(%rdi), %edx
	addl	%edi, %eax
	cmpl	$-1, %edx
	je	.L4
	testl	%edx, %edx
	movl	%edx, %edi
	jne	.L11
.L6:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L4:
	.cfi_restore_state
	call	_Z3sumi.part.4
	.cfi_endproc
.LFE7978:
	.size	_Z3sumi, .-_Z3sumi
	.section	.text.unlikely
.LCOLDE3:
	.text
.LHOTE3:
	.section	.text.unlikely
.LCOLDB4:
	.text
.LHOTB4:
	.p2align 4,,15
	.globl	_Z5powerii
	.type	_Z5powerii, @function
_Z5powerii:
.LFB7979:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	testl	%esi, %esi
	js	.L25
	movl	$1, %eax
	jne	.L26
.L19:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L26:
	.cfi_restore_state
	movl	%esi, %ebx
	sarl	%esi
	movl	%edi, %ebp
	call	_Z5powerii
	imull	%eax, %eax
	andl	$1, %ebx
	je	.L19
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	imull	%ebp, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L25:
	.cfi_restore_state
	movl	$_ZZ5poweriiE19__PRETTY_FUNCTION__, %ecx
	movl	$25, %edx
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	call	__assert_fail
	.cfi_endproc
.LFE7979:
	.size	_Z5powerii, .-_Z5powerii
	.section	.text.unlikely
.LCOLDE4:
	.text
.LHOTE4:
	.section	.text.unlikely
.LCOLDB5:
	.text
.LHOTB5:
	.p2align 4,,15
	.globl	_Z3gcdii
	.type	_Z3gcdii, @function
_Z3gcdii:
.LFB7981:
	.cfi_startproc
	movl	%edi, %eax
	jmp	.L28
	.p2align 4,,10
	.p2align 3
.L32:
	testl	%esi, %esi
	je	.L30
	cltd
	idivl	%esi
.L29:
	movl	%esi, %eax
	movl	%edx, %esi
.L28:
	cmpl	%esi, %eax
	jge	.L32
	movl	%eax, %edx
	jmp	.L29
	.p2align 4,,10
	.p2align 3
.L30:
	rep ret
	.cfi_endproc
.LFE7981:
	.size	_Z3gcdii, .-_Z3gcdii
	.section	.text.unlikely
.LCOLDE5:
	.text
.LHOTE5:
	.section	.rodata.str1.1
.LC6:
	.string	", "
	.section	.text.unlikely._Z9display_vIiEvRSt6vectorIT_SaIS1_EE,"axG",@progbits,_Z9display_vIiEvRSt6vectorIT_SaIS1_EE,comdat
.LCOLDB7:
	.section	.text._Z9display_vIiEvRSt6vectorIT_SaIS1_EE,"axG",@progbits,_Z9display_vIiEvRSt6vectorIT_SaIS1_EE,comdat
.LHOTB7:
	.p2align 4,,15
	.weak	_Z9display_vIiEvRSt6vectorIT_SaIS1_EE
	.type	_Z9display_vIiEvRSt6vectorIT_SaIS1_EE, @function
_Z9display_vIiEvRSt6vectorIT_SaIS1_EE:
.LFB8072:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movl	$1, %edx
	movq	%rdi, %rbx
	movl	$_ZSt4cout, %edi
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	leaq	14(%rsp), %rsi
	movb	$123, 14(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	8(%rbx), %rbp
	movq	(%rbx), %rbx
	cmpq	%rbp, %rbx
	je	.L36
	.p2align 4,,10
	.p2align 3
.L37:
	movl	(%rbx), %esi
	movl	$_ZSt4cout, %edi
	addq	$4, %rbx
	call	_ZNSolsEi
	movl	$2, %edx
	movl	$.LC6, %esi
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	cmpq	%rbx, %rbp
	jne	.L37
.L36:
	leaq	15(%rsp), %rsi
	movl	$1, %edx
	movl	$_ZSt4cout, %edi
	movb	$125, 15(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	addq	$24, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE8072:
	.size	_Z9display_vIiEvRSt6vectorIT_SaIS1_EE, .-_Z9display_vIiEvRSt6vectorIT_SaIS1_EE
	.section	.text.unlikely._Z9display_vIiEvRSt6vectorIT_SaIS1_EE,"axG",@progbits,_Z9display_vIiEvRSt6vectorIT_SaIS1_EE,comdat
.LCOLDE7:
	.section	.text._Z9display_vIiEvRSt6vectorIT_SaIS1_EE,"axG",@progbits,_Z9display_vIiEvRSt6vectorIT_SaIS1_EE,comdat
.LHOTE7:
	.section	.text.unlikely._Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE,"axG",@progbits,_Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE,comdat
.LCOLDB8:
	.section	.text._Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE,"axG",@progbits,_Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE,comdat
.LHOTB8:
	.p2align 4,,15
	.weak	_Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE
	.type	_Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE, @function
_Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE:
.LFB8073:
	.cfi_startproc
	movq	8(%rdi), %rdx
	subq	(%rdi), %rdx
	movq	%rdx, %rax
	sarq	$2, %rax
	testq	%rax, %rax
	je	.L57
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movabsq	$4611686018427387903, %rcx
	movq	%rdi, %rbp
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	cmpq	%rcx, %rax
	ja	.L58
	movq	%rdx, %rdi
	call	_Znwm
	movq	0(%rbp), %rbx
	movq	8(%rbp), %rdx
	movq	%rax, %r10
	subq	%rbx, %rdx
	movq	%rdx, %rbp
	sarq	$2, %rbp
	testq	%rbp, %rbp
	jne	.L59
.L45:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movq	%r10, %rdi
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	jmp	_ZdlPv
	.p2align 4,,10
	.p2align 3
.L59:
	.cfi_restore_state
	movq	%rax, %rdi
	movq	%rbx, %rsi
	call	memmove
	cmpl	$1, %ebp
	movq	%rax, %r10
	movl	%ebp, %edi
	jle	.L45
	movslq	%ebp, %rbp
	leaq	4(%rbx), %r11
	leaq	-4(%rbx,%rbp,4), %r9
	.p2align 4,,10
	.p2align 3
.L49:
	movl	(%rbx), %esi
	movq	%r11, %rdx
	xorl	%r8d, %r8d
	movl	$1, %eax
	jmp	.L48
	.p2align 4,,10
	.p2align 3
.L61:
	addl	$1, %eax
	movslq	%r8d, %rcx
	addq	$4, %rdx
	cmpl	%eax, %edi
	leaq	(%rbx,%rcx,4), %rcx
	jle	.L60
.L48:
	movl	(%rdx), %ecx
	cmpl	%esi, %ecx
	jle	.L61
	movl	%eax, %r8d
	addl	$1, %eax
	movl	%ecx, %esi
	movq	%rdx, %rcx
	addq	$4, %rdx
	cmpl	%eax, %edi
	jg	.L48
.L60:
	movl	(%r9), %eax
	subl	$1, %edi
	movl	%esi, (%r9)
	subq	$4, %r9
	cmpl	$1, %edi
	movl	%eax, (%rcx)
	jne	.L49
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	movq	%r10, %rdi
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	jmp	_ZdlPv
.L57:
	rep ret
.L58:
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	call	_ZSt17__throw_bad_allocv
	.cfi_endproc
.LFE8073:
	.size	_Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE, .-_Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE
	.section	.text.unlikely._Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE,"axG",@progbits,_Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE,comdat
.LCOLDE8:
	.section	.text._Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE,"axG",@progbits,_Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE,comdat
.LHOTE8:
	.section	.text.unlikely._ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_,"axG",@progbits,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_,comdat
	.align 2
.LCOLDB9:
	.section	.text._ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_,"axG",@progbits,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_,comdat
.LHOTB9:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_
	.type	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_, @function
_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_:
.LFB8150:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movq	%rsi, %r12
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movq	8(%rdi), %rax
	movq	%rdi, %rbx
	subq	(%rdi), %rax
	sarq	$2, %rax
	testq	%rax, %rax
	je	.L70
	leaq	(%rax,%rax), %rdx
	cmpq	%rdx, %rax
	jbe	.L82
.L71:
	movq	$-4, %r13
	jmp	.L63
	.p2align 4,,10
	.p2align 3
.L70:
	movl	$4, %r13d
.L63:
	movq	%r13, %rdi
	call	_Znwm
	movq	%rax, %rbp
.L69:
	movq	(%rbx), %r14
	movq	8(%rbx), %rdx
	movl	(%r12), %ecx
	movq	%rbp, %r12
	subq	%r14, %rdx
	movq	%rdx, %rax
	sarq	$2, %rax
	addq	%rdx, %r12
	je	.L65
	movl	%ecx, (%r12)
.L65:
	testq	%rax, %rax
	jne	.L83
	addq	$4, %r12
	testq	%r14, %r14
	je	.L68
.L67:
	movq	%r14, %rdi
	call	_ZdlPv
.L68:
	movq	%rbp, (%rbx)
	addq	%r13, %rbp
	movq	%r12, 8(%rbx)
	movq	%rbp, 16(%rbx)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L83:
	.cfi_restore_state
	movq	%r14, %rsi
	movq	%rbp, %rdi
	addq	$4, %r12
	call	memmove
	jmp	.L67
.L82:
	movabsq	$4611686018427387903, %rcx
	cmpq	%rcx, %rdx
	ja	.L71
	xorl	%r13d, %r13d
	xorl	%ebp, %ebp
	testq	%rdx, %rdx
	je	.L69
	leaq	0(,%rax,8), %r13
	jmp	.L63
	.cfi_endproc
.LFE8150:
	.size	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_, .-_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_
	.section	.text.unlikely._ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_,"axG",@progbits,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_,comdat
.LCOLDE9:
	.section	.text._ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_,"axG",@progbits,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_,comdat
.LHOTE9:
	.weak	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
	.set	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_
	.section	.rodata.str1.1
.LC10:
	.string	"n >= 0 && m >= 0"
	.section	.text.unlikely._Z5log_2IiET_S0_S0_,"axG",@progbits,_Z5log_2IiET_S0_S0_,comdat
.LCOLDB11:
	.section	.text._Z5log_2IiET_S0_S0_,"axG",@progbits,_Z5log_2IiET_S0_S0_,comdat
.LHOTB11:
	.p2align 4,,15
	.weak	_Z5log_2IiET_S0_S0_
	.type	_Z5log_2IiET_S0_S0_, @function
_Z5log_2IiET_S0_S0_:
.LFB8166:
	.cfi_startproc
	movl	%edi, %eax
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	shrl	$31, %eax
	testb	%al, %al
	jne	.L85
	movl	%esi, %eax
	movl	%esi, %ecx
	shrl	$31, %eax
	testb	%al, %al
	je	.L95
	jmp	.L85
	.p2align 4,,10
	.p2align 3
.L88:
	addl	$1, %ecx
.L95:
	movl	%edi, %eax
	sarl	%cl, %eax
	testl	%eax, %eax
	jne	.L88
	movl	%ecx, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L85:
	.cfi_restore_state
	movl	$_ZZ5log_2IiET_S0_S0_E19__PRETTY_FUNCTION__, %ecx
	movl	$148, %edx
	movl	$.LC0, %esi
	movl	$.LC10, %edi
	call	__assert_fail
	.cfi_endproc
.LFE8166:
	.size	_Z5log_2IiET_S0_S0_, .-_Z5log_2IiET_S0_S0_
	.section	.text.unlikely._Z5log_2IiET_S0_S0_,"axG",@progbits,_Z5log_2IiET_S0_S0_,comdat
.LCOLDE11:
	.section	.text._Z5log_2IiET_S0_S0_,"axG",@progbits,_Z5log_2IiET_S0_S0_,comdat
.LHOTE11:
	.section	.rodata.str1.1
.LC14:
	.string	"b >= a"
.LC15:
	.string	"m >= -1"
.LC16:
	.string	"a >= 0"
.LC17:
	.string	"b >= 1"
	.section	.text.unlikely._Z12fib_doublingIidET0_T_S1_S0_S0_,"axG",@progbits,_Z12fib_doublingIidET0_T_S1_S0_S0_,comdat
.LCOLDB18:
	.section	.text._Z12fib_doublingIidET0_T_S1_S0_S0_,"axG",@progbits,_Z12fib_doublingIidET0_T_S1_S0_S0_,comdat
.LHOTB18:
	.p2align 4,,15
	.weak	_Z12fib_doublingIidET0_T_S1_S0_S0_
	.type	_Z12fib_doublingIidET0_T_S1_S0_S0_, @function
_Z12fib_doublingIidET0_T_S1_S0_S0_:
.LFB8167:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	testl	%edi, %edi
	js	.L97
	ucomisd	%xmm0, %xmm1
	jb	.L98
	cmpl	$-1, %esi
	jl	.L100
	pxor	%xmm3, %xmm3
	ucomisd	%xmm3, %xmm0
	jb	.L101
	movsd	.LC13(%rip), %xmm4
	ucomisd	%xmm4, %xmm1
	jnb	.L109
	jmp	.L103
	.p2align 4,,10
	.p2align 3
.L123:
	movapd	%xmm2, %xmm1
	addsd	%xmm0, %xmm1
.L111:
	subl	$1, %esi
	ucomisd	%xmm0, %xmm1
	jb	.L98
	cmpl	$-2, %esi
	je	.L100
	ucomisd	%xmm3, %xmm0
	jb	.L101
	ucomisd	%xmm4, %xmm1
	jb	.L103
.L109:
	cmpl	$-1, %esi
	je	.L118
	movapd	%xmm1, %xmm2
	btl	%esi, %edi
	addsd	%xmm1, %xmm2
	mulsd	%xmm1, %xmm1
	subsd	%xmm0, %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm0, %xmm0
	addsd	%xmm1, %xmm0
	jc	.L123
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	jmp	.L111
	.p2align 4,,10
	.p2align 3
.L118:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L97:
	.cfi_restore_state
	movl	$_ZZ12fib_doublingIidET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, %ecx
	movl	$124, %edx
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	call	__assert_fail
.L103:
	movl	$_ZZ12fib_doublingIidET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, %ecx
	movl	$128, %edx
	movl	$.LC0, %esi
	movl	$.LC17, %edi
	call	__assert_fail
.L101:
	movl	$_ZZ12fib_doublingIidET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, %ecx
	movl	$127, %edx
	movl	$.LC0, %esi
	movl	$.LC16, %edi
	call	__assert_fail
.L100:
	movl	$_ZZ12fib_doublingIidET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, %ecx
	movl	$126, %edx
	movl	$.LC0, %esi
	movl	$.LC15, %edi
	call	__assert_fail
.L98:
	movl	$_ZZ12fib_doublingIidET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, %ecx
	movl	$125, %edx
	movl	$.LC0, %esi
	movl	$.LC14, %edi
	call	__assert_fail
	.cfi_endproc
.LFE8167:
	.size	_Z12fib_doublingIidET0_T_S1_S0_S0_, .-_Z12fib_doublingIidET0_T_S1_S0_S0_
	.section	.text.unlikely._Z12fib_doublingIidET0_T_S1_S0_S0_,"axG",@progbits,_Z12fib_doublingIidET0_T_S1_S0_S0_,comdat
.LCOLDE18:
	.section	.text._Z12fib_doublingIidET0_T_S1_S0_S0_,"axG",@progbits,_Z12fib_doublingIidET0_T_S1_S0_S0_,comdat
.LHOTE18:
	.section	.text.unlikely._Z12fib_doublingIiiET0_T_S1_S0_S0_,"axG",@progbits,_Z12fib_doublingIiiET0_T_S1_S0_S0_,comdat
.LCOLDB19:
	.section	.text._Z12fib_doublingIiiET0_T_S1_S0_S0_,"axG",@progbits,_Z12fib_doublingIiiET0_T_S1_S0_S0_,comdat
.LHOTB19:
	.p2align 4,,15
	.weak	_Z12fib_doublingIiiET0_T_S1_S0_S0_
	.type	_Z12fib_doublingIiiET0_T_S1_S0_S0_, @function
_Z12fib_doublingIiiET0_T_S1_S0_S0_:
.LFB8214:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	testl	%edi, %edi
	js	.L125
	cmpl	%ecx, %edx
	jg	.L126
	cmpl	$-1, %esi
	jge	.L132
	jmp	.L127
	.p2align 4,,10
	.p2align 3
.L150:
	leal	(%rcx,%rcx), %eax
	imull	%ecx, %ecx
	subl	%edx, %eax
	imull	%edx, %eax
	imull	%edx, %edx
	addl	%ecx, %edx
	btl	%esi, %edi
	leal	(%rax,%rdx), %ecx
	jc	.L136
	movl	%edx, %ecx
	movl	%eax, %edx
.L136:
	subl	$1, %esi
	cmpl	%ecx, %edx
	jg	.L126
	cmpl	$-2, %esi
	je	.L127
.L132:
	testl	%edx, %edx
	js	.L148
	testl	%ecx, %ecx
	jle	.L149
	cmpl	$-1, %esi
	jne	.L150
	movl	%edx, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L125:
	.cfi_restore_state
	movl	$_ZZ12fib_doublingIiiET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, %ecx
	movl	$124, %edx
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	call	__assert_fail
.L149:
	movl	$_ZZ12fib_doublingIiiET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, %ecx
	movl	$128, %edx
	movl	$.LC0, %esi
	movl	$.LC17, %edi
	call	__assert_fail
.L148:
	movl	$_ZZ12fib_doublingIiiET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, %ecx
	movl	$127, %edx
	movl	$.LC0, %esi
	movl	$.LC16, %edi
	call	__assert_fail
.L127:
	movl	$_ZZ12fib_doublingIiiET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, %ecx
	movl	$126, %edx
	movl	$.LC0, %esi
	movl	$.LC15, %edi
	call	__assert_fail
.L126:
	movl	$_ZZ12fib_doublingIiiET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, %ecx
	movl	$125, %edx
	movl	$.LC0, %esi
	movl	$.LC14, %edi
	call	__assert_fail
	.cfi_endproc
.LFE8214:
	.size	_Z12fib_doublingIiiET0_T_S1_S0_S0_, .-_Z12fib_doublingIiiET0_T_S1_S0_S0_
	.section	.text.unlikely._Z12fib_doublingIiiET0_T_S1_S0_S0_,"axG",@progbits,_Z12fib_doublingIiiET0_T_S1_S0_S0_,comdat
.LCOLDE19:
	.section	.text._Z12fib_doublingIiiET0_T_S1_S0_S0_,"axG",@progbits,_Z12fib_doublingIiiET0_T_S1_S0_S0_,comdat
.LHOTE19:
	.section	.text.unlikely._Z3fibIiiET0_T_,"axG",@progbits,_Z3fibIiiET0_T_,comdat
.LCOLDB20:
	.section	.text._Z3fibIiiET0_T_,"axG",@progbits,_Z3fibIiiET0_T_,comdat
.LHOTB20:
	.p2align 4,,15
	.weak	_Z3fibIiiET0_T_
	.type	_Z3fibIiiET0_T_, @function
_Z3fibIiiET0_T_:
.LFB8147:
	.cfi_startproc
	testl	%edi, %edi
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	js	.L154
	movl	%edi, %ebx
	xorl	%esi, %esi
	call	_Z5log_2IiET_S0_S0_
	movl	%ebx, %edi
	movl	$1, %ecx
	xorl	%edx, %edx
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movl	%eax, %esi
	jmp	_Z12fib_doublingIiiET0_T_S1_S0_S0_
.L154:
	.cfi_restore_state
	movl	$_ZZ3fibIiiET0_T_E19__PRETTY_FUNCTION__, %ecx
	movl	$157, %edx
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	call	__assert_fail
	.cfi_endproc
.LFE8147:
	.size	_Z3fibIiiET0_T_, .-_Z3fibIiiET0_T_
	.section	.text.unlikely._Z3fibIiiET0_T_,"axG",@progbits,_Z3fibIiiET0_T_,comdat
.LCOLDE20:
	.section	.text._Z3fibIiiET0_T_,"axG",@progbits,_Z3fibIiiET0_T_,comdat
.LHOTE20:
	.section	.rodata.str1.1
.LC21:
	.string	"Selection sort test: "
.LC22:
	.string	"fib(20): "
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC23:
	.string	"fib(100) (using int > double conversion to prevent overflow): "
	.section	.rodata.str1.1
.LC24:
	.string	"sum(20): "
.LC25:
	.string	"gcd(5250, 27720): "
	.section	.text.unlikely
.LCOLDB26:
	.section	.text.startup,"ax",@progbits
.LHOTB26:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB7990:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA7990
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	xorl	%r12d, %r12d
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	xorl	%ebp, %ebp
	xorl	%ebx, %ebx
	subq	$64, %rsp
	.cfi_def_cfa_offset 96
	movq	$0, 32(%rsp)
	movq	$0, 40(%rsp)
	movq	$0, 48(%rsp)
	jmp	.L160
	.p2align 4,,10
	.p2align 3
.L187:
	testq	%rbx, %rbx
	je	.L157
	movl	%eax, (%rbx)
.L157:
	addl	$1, %ebp
	addq	$4, %rbx
	cmpl	$30, %ebp
	movq	%rbx, 40(%rsp)
	je	.L159
.L188:
	movq	40(%rsp), %rbx
	movq	48(%rsp), %r12
.L160:
	movl	%ebp, %edi
	call	_Z3fibIiiET0_T_
	cmpq	%r12, %rbx
	movl	%eax, 28(%rsp)
	jne	.L187
	leaq	28(%rsp), %rsi
	leaq	32(%rsp), %rdi
.LEHB0:
	call	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_
	addl	$1, %ebp
	cmpl	$30, %ebp
	jne	.L188
	.p2align 4,,10
	.p2align 3
.L159:
	movl	$21, %edx
	movl	$.LC21, %esi
	movl	$_ZSt4cout, %edi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	$_ZSt4cout, %edi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movq	40(%rsp), %rbp
	movq	32(%rsp), %r12
	cmpq	%r12, %rbp
	je	.L163
	leaq	4(%r12), %rbx
	cmpq	%rbx, %rbp
	je	.L163
	.p2align 4,,10
	.p2align 3
.L165:
	call	rand
	movq	%rbx, %rcx
	cltq
	subq	%r12, %rcx
	cqto
	sarq	$2, %rcx
	addq	$1, %rcx
	idivq	%rcx
	leaq	(%r12,%rdx,4), %rax
	cmpq	%rbx, %rax
	je	.L164
	movl	(%rbx), %edx
	movl	(%rax), %ecx
	movl	%ecx, (%rbx)
	movl	%edx, (%rax)
.L164:
	addq	$4, %rbx
	cmpq	%rbx, %rbp
	jne	.L165
.L163:
	leaq	32(%rsp), %rdi
	call	_Z9display_vIiEvRSt6vectorIT_SaIS1_EE
	movl	$_ZSt4cout, %edi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	leaq	32(%rsp), %rdi
	call	_Z14selection_sortIiEvRSt6vectorIT_SaIS1_EE
	leaq	32(%rsp), %rdi
	call	_Z9display_vIiEvRSt6vectorIT_SaIS1_EE
	movl	$27720, %ebx
	movl	$5250, %ecx
	jmp	.L166
	.p2align 4,,10
	.p2align 3
.L189:
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	movl	%edx, %ebx
.L167:
	movl	%ecx, %eax
	movl	%ebx, %ecx
	movl	%eax, %ebx
.L166:
	cmpl	%ebx, %ecx
	jg	.L167
	testl	%ecx, %ecx
	jne	.L189
	xorl	%esi, %esi
	movl	$100, %edi
	call	_Z5log_2IiET_S0_S0_
	pxor	%xmm0, %xmm0
	movl	%eax, %esi
	movsd	.LC13(%rip), %xmm1
	movl	$100, %edi
	call	_Z12fib_doublingIidET0_T_S1_S0_S0_
	movl	$20, %edi
	movsd	%xmm0, 8(%rsp)
	call	_Z3fibIiiET0_T_
	movl	$_ZSt4cout, %edi
	movl	%eax, %r12d
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movl	$9, %edx
	movl	$.LC22, %esi
	movq	%rax, %rdi
	movq	%rax, %rbp
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	%r12d, %esi
	movq	%rbp, %rdi
	call	_ZNSolsEi
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movl	$62, %edx
	movl	$.LC23, %esi
	movq	%rax, %rdi
	movq	%rax, %rbp
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movsd	8(%rsp), %xmm0
	movq	%rbp, %rdi
	call	_ZNSo9_M_insertIdEERSoT_
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movl	$9, %edx
	movl	$.LC24, %esi
	movq	%rax, %rdi
	movq	%rax, %rbp
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	$210, %esi
	movq	%rbp, %rdi
	call	_ZNSolsEi
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movl	$18, %edx
	movl	$.LC25, %esi
	movq	%rax, %rdi
	movq	%rax, %rbp
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	%ebx, %esi
	movq	%rbp, %rdi
	call	_ZNSolsEi
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
.LEHE0:
	movq	32(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L176
	call	_ZdlPv
.L176:
	addq	$64, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L172:
	.cfi_restore_state
	movq	32(%rsp), %rdi
	movq	%rax, %rbx
	testq	%rdi, %rdi
	je	.L171
	call	_ZdlPv
.L171:
	movq	%rbx, %rdi
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
	.cfi_endproc
.LFE7990:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA7990:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7990-.LLSDACSB7990
.LLSDACSB7990:
	.uleb128 .LEHB0-.LFB7990
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L172-.LFB7990
	.uleb128 0
	.uleb128 .LEHB1-.LFB7990
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE7990:
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE26:
	.section	.text.startup
.LHOTE26:
	.section	.text.unlikely
.LCOLDB27:
	.section	.text.startup
.LHOTB27:
	.p2align 4,,15
	.type	_GLOBAL__sub_I__Z3sumi, @function
_GLOBAL__sub_I__Z3sumi:
.LFB8342:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit
	.cfi_endproc
.LFE8342:
	.size	_GLOBAL__sub_I__Z3sumi, .-_GLOBAL__sub_I__Z3sumi
	.section	.text.unlikely
.LCOLDE27:
	.section	.text.startup
.LHOTE27:
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z3sumi
	.section	.rodata
	.align 32
	.type	_ZZ12fib_doublingIiiET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, @object
	.size	_ZZ12fib_doublingIiiET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, 79
_ZZ12fib_doublingIiiET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__:
	.string	"ret_T fib_doubling(arg_T, arg_T, ret_T, ret_T) [with arg_T = int; ret_T = int]"
	.align 32
	.type	_ZZ3fibIiiET0_T_E19__PRETTY_FUNCTION__, @object
	.size	_ZZ3fibIiiET0_T_E19__PRETTY_FUNCTION__, 49
_ZZ3fibIiiET0_T_E19__PRETTY_FUNCTION__:
	.string	"ret_T fib(arg_T) [with arg_T = int; ret_T = int]"
	.align 32
	.type	_ZZ12fib_doublingIidET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, @object
	.size	_ZZ12fib_doublingIidET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__, 82
_ZZ12fib_doublingIidET0_T_S1_S0_S0_E19__PRETTY_FUNCTION__:
	.string	"ret_T fib_doubling(arg_T, arg_T, ret_T, ret_T) [with arg_T = int; ret_T = double]"
	.align 32
	.type	_ZZ5log_2IiET_S0_S0_E19__PRETTY_FUNCTION__, @object
	.size	_ZZ5log_2IiET_S0_S0_E19__PRETTY_FUNCTION__, 61
_ZZ5log_2IiET_S0_S0_E19__PRETTY_FUNCTION__:
	.string	"arg_ret_T log_2(arg_ret_T, arg_ret_T) [with arg_ret_T = int]"
	.align 16
	.type	_ZZ5poweriiE19__PRETTY_FUNCTION__, @object
	.size	_ZZ5poweriiE19__PRETTY_FUNCTION__, 20
_ZZ5poweriiE19__PRETTY_FUNCTION__:
	.string	"int power(int, int)"
	.align 8
	.type	_ZZ3sumiE19__PRETTY_FUNCTION__, @object
	.size	_ZZ3sumiE19__PRETTY_FUNCTION__, 13
_ZZ3sumiE19__PRETTY_FUNCTION__:
	.string	"int sum(int)"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC13:
	.long	0
	.long	1072693248
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 5.2.0"
	.section	.note.GNU-stack,"",@progbits
