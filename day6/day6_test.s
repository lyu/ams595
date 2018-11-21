	.file	"day6_test.cpp"
	.intel_syntax noprefix
# GNU C++11 (GCC) version 8.2.0 (x86_64-pc-linux-gnu)
#	compiled by GNU C version 8.2.0, GMP version 6.1.0, MPFR version 3.1.4, MPC version 1.0.3, isl version isl-0.18-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -D_GNU_SOURCE day6_test.cpp -masm=intel -mtune=generic
# -march=x86-64 -Wall -Wextra -std=c++11 -fverbose-asm
# options enabled:  -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
# -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -fexceptions -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm
# -fgnu-runtime -fgnu-unique -fident -finline-atomics -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots -fivopts
# -fkeep-static-consts -fleading-underscore -flifetime-dse
# -flto-odr-type-merging -fmath-errno -fmerge-debug-strings -fpeephole
# -fplt -fprefetch-loop-arrays -freg-struct-return
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
# -fshow-column -fshrink-wrap-separate -fsigned-zeros
# -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math -ftree-cselim
# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.globl	_Z3fooPii
	.type	_Z3fooPii, @function
_Z3fooPii:
.LFB1456:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-24], rdi	# a, a
	mov	DWORD PTR [rbp-28], esi	# len, len
# day6_test.cpp:11:     for (int i = 0; i < len; i++)
	mov	DWORD PTR [rbp-4], 0	# i,
.L3:
# day6_test.cpp:11:     for (int i = 0; i < len; i++)
	mov	eax, DWORD PTR [rbp-4]	# tmp90, i
	cmp	eax, DWORD PTR [rbp-28]	# tmp90, len
	jge	.L4	#,
# day6_test.cpp:12:         a[i] = i;
	mov	eax, DWORD PTR [rbp-4]	# tmp91, i
	cdqe
	lea	rdx, [0+rax*4]	# _2,
	mov	rax, QWORD PTR [rbp-24]	# tmp92, a
	add	rdx, rax	# _3, tmp92
# day6_test.cpp:12:         a[i] = i;
	mov	eax, DWORD PTR [rbp-4]	# tmp93, i
	mov	DWORD PTR [rdx], eax	# *_3, tmp93
# day6_test.cpp:11:     for (int i = 0; i < len; i++)
	add	DWORD PTR [rbp-4], 1	# i,
	jmp	.L3	#
.L4:
# day6_test.cpp:13: }
	nop	
	pop	rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1456:
	.size	_Z3fooPii, .-_Z3fooPii
	.globl	_Z3barPii
	.type	_Z3barPii, @function
_Z3barPii:
.LFB1457:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	mov	QWORD PTR [rbp-24], rdi	# a, a
	mov	DWORD PTR [rbp-28], esi	# len, len
# day6_test.cpp:16:     int result = 0;
	mov	DWORD PTR [rbp-4], 0	# result,
# day6_test.cpp:18:     if (a[len - 1] < 5) {
	mov	eax, DWORD PTR [rbp-28]	# tmp99, len
	cdqe
	sal	rax, 2	# _2,
	lea	rdx, [rax-4]	# _3,
	mov	rax, QWORD PTR [rbp-24]	# tmp100, a
	add	rax, rdx	# _4, _3
	mov	eax, DWORD PTR [rax]	# _5, *_4
# day6_test.cpp:18:     if (a[len - 1] < 5) {
	cmp	eax, 4	# _5,
	jg	.L6	#,
# day6_test.cpp:19:         result = -1;
	mov	DWORD PTR [rbp-4], -1	# result,
	jmp	.L7	#
.L6:
# day6_test.cpp:20:     } else if (a[len - 1] > 7) {
	mov	eax, DWORD PTR [rbp-28]	# tmp101, len
	cdqe
	sal	rax, 2	# _7,
	lea	rdx, [rax-4]	# _8,
	mov	rax, QWORD PTR [rbp-24]	# tmp102, a
	add	rax, rdx	# _9, _8
	mov	eax, DWORD PTR [rax]	# _10, *_9
# day6_test.cpp:20:     } else if (a[len - 1] > 7) {
	cmp	eax, 7	# _10,
	jle	.L8	#,
# day6_test.cpp:21:         result = 0;
	mov	DWORD PTR [rbp-4], 0	# result,
	jmp	.L7	#
.L8:
# day6_test.cpp:23:         result = 1;
	mov	DWORD PTR [rbp-4], 1	# result,
.L7:
# day6_test.cpp:25:     return result;
	mov	eax, DWORD PTR [rbp-4]	# _19, result
# day6_test.cpp:26: }
	pop	rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1457:
	.size	_Z3barPii, .-_Z3barPii
	.globl	main
	.type	main, @function
main:
.LFB1458:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	push	rbx	#
	sub	rsp, 40	#,
	.cfi_offset 3, -24
# day6_test.cpp:33:     std::cout << bar(a, N) << '\n';
	mov	rax, rsp	# tmp110,
	mov	rbx, rax	# saved_stack.3_6, tmp110
# day6_test.cpp:29:     int N = 8;
	mov	DWORD PTR [rbp-20], 8	# N,
# day6_test.cpp:30:     int a[N];
	mov	eax, DWORD PTR [rbp-20]	# tmp111, N
	cdqe
	sub	rax, 1	# _21,
# day6_test.cpp:30:     int a[N];
	mov	QWORD PTR [rbp-32], rax	# D.37325, _21
	mov	rdx, rax	# _3, _21
	add	rdx, 1	# _4,
	mov	r8, rdx	# _5, _4
	mov	r9d, 0	# _5,
	mov	rdx, rax	# _10, _21
	add	rdx, 1	# _11,
	mov	rsi, rdx	# _12, _11
	mov	edi, 0	# _12,
	add	rax, 1	# _15,
	lea	rdx, [0+rax*4]	# _26,
	mov	eax, 16	# tmp125,
	sub	rax, 1	# tmp112,
	add	rax, rdx	# tmp113, _26
	mov	ecx, 16	# tmp126,
	mov	edx, 0	# tmp116,
	div	rcx	# tmp126
	imul	rax, rax, 16	# tmp117, tmp115,
	sub	rsp, rax	#, tmp117
	mov	rax, rsp	# tmp118,
	add	rax, 3	# tmp119,
	shr	rax, 2	# tmp120,
	sal	rax, 2	# tmp121,
	mov	QWORD PTR [rbp-40], rax	# a.0, tmp121
# day6_test.cpp:31:     foo(a, N);
	mov	rax, QWORD PTR [rbp-40]	# a.1_17, a.0
	mov	edx, DWORD PTR [rbp-20]	# tmp122, N
	mov	esi, edx	#, tmp122
	mov	rdi, rax	#, a.1_17
	call	_Z3fooPii	#
# day6_test.cpp:33:     std::cout << bar(a, N) << '\n';
	mov	rax, QWORD PTR [rbp-40]	# a.2_18, a.0
	mov	edx, DWORD PTR [rbp-20]	# tmp123, N
	mov	esi, edx	#, tmp123
	mov	rdi, rax	#, a.2_18
	call	_Z3barPii	#
	mov	esi, eax	#, _19
	mov	edi, OFFSET FLAT:_ZSt4cout	#,
	call	_ZNSolsEi	#
	mov	esi, 10	#,
	mov	rdi, rax	#, _20
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c	#
	mov	rsp, rbx	#, saved_stack.3_6
# day6_test.cpp:34: }
	mov	eax, 0	# _35,
	mov	rbx, QWORD PTR [rbp-8]	#,
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1458:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1776:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	sub	rsp, 16	#,
	mov	DWORD PTR [rbp-4], edi	# __initialize_p, __initialize_p
	mov	DWORD PTR [rbp-8], esi	# __priority, __priority
# day6_test.cpp:34: }
	cmp	DWORD PTR [rbp-4], 1	# __initialize_p,
	jne	.L14	#,
# day6_test.cpp:34: }
	cmp	DWORD PTR [rbp-8], 65535	# __priority,
	jne	.L14	#,
# /gpfs/home/wenblu/.local/include/c++/8.2.0/iostream:74:   static ios_base::Init __ioinit;
	mov	edi, OFFSET FLAT:_ZStL8__ioinit	#,
	call	_ZNSt8ios_base4InitC1Ev	#
	mov	edx, OFFSET FLAT:__dso_handle	#,
	mov	esi, OFFSET FLAT:_ZStL8__ioinit	#,
	mov	edi, OFFSET FLAT:_ZNSt8ios_base4InitD1Ev	#,
	call	__cxa_atexit	#
.L14:
# day6_test.cpp:34: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1776:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z3fooPii, @function
_GLOBAL__sub_I__Z3fooPii:
.LFB1777:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
# day6_test.cpp:34: }
	mov	esi, 65535	#,
	mov	edi, 1	#,
	call	_Z41__static_initialization_and_destruction_0ii	#
	pop	rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1777:
	.size	_GLOBAL__sub_I__Z3fooPii, .-_GLOBAL__sub_I__Z3fooPii
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z3fooPii
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
