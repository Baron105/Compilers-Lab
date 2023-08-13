	.file	"code.c"						# source file name
	.text									# code starts here
	.globl	calculateFrequency				# calculateFrequency is a global name
	.type	calculateFrequency, @function	# calculateFrequency is a function
calculateFrequency:							# function calculateFrequency starts
.LFB0:										# function definition label LFB0, // line 3 of .c file having the function call with arguments
	.cfi_startproc							# cfi directive, call frame information used for debugging and exception handling
	endbr64									# end of branch 64 bit
	pushq	%rbp							# save old base pointer %rbp
	.cfi_def_cfa_offset 16					# cfi directive
	.cfi_offset 6, -16						# cfi directive
	movq	%rsp, %rbp						# set stack pointer %rsp to base pointer %rbp
	.cfi_def_cfa_register 6					# cfi directive
	movq	%rdi, -24(%rbp)					# store first argument (array arr1[]) in -24(%rbp)
	movl	%esi, -28(%rbp)					# store second argument (integer n) in -28(%rbp)
	movq	%rdx, -40(%rbp)					# store third argument (array fr1[]) in -40(%rbp)
	movl	$0, -12(%rbp)					# initialize i, j and ctr to 0 after allocating space for them at -12(%rbp), -8(%rbp), -4(%rbp) respectively // line 4 of .c file having the declaration of i, j, ctr
	jmp	.L2									# jump to label L2
.L7:										# label L7, // line 6 of .c file having the loop 1 start
	movl	$1, -4(%rbp)					# initialize ctr to 1 and store in -4(%rbp), // line 7 of .c file where ctr = 1
	movl	-12(%rbp), %eax					# load value of i from -12(%rbp) into %eax
	addl	$1, %eax						# increment i stored in %eax by 1
	movl	%eax, -8(%rbp)					# store incremented %eax ie i + 1 in -8(%rbp) ie j, ie j = i + 1 // line 8 of .c file where j = i + 1
	jmp	.L3									# jump to label .L3
.L5:										# label L5, // line 8 of .c file having the loop 2 start
	movl	-12(%rbp), %eax					# load i stored at -12(%rbp) into %eax
	cltq									# convert long to quad, sign extend %eax to %rax
	leaq	0(,%rax,4), %rdx				# %rdx = 4 * %rax + 0 ie offset for array element used for traversing array
	movq	-24(%rbp), %rax					# load arr1[] stored at -24(%rbp) into %rax
	addq	%rdx, %rax						# add %rdx to %rax, ie 4*i is added to address of arr1[] to get arr[i] as rax is i
	movl	(%rax), %edx					# set %edx to the value of (%rax), ie load the value of arr1[i] into %edx
	movl	-8(%rbp), %eax					# load j stored at -8(%rbp) into %eax
	cltq									# convert long to quad, sign extend %eax to %rax
	leaq	0(,%rax,4), %rcx				# %rcx = 4 * %rax + 0 ie offset for array element used for traversing array
	movq	-24(%rbp), %rax					# load arr1[] stored at -24(%rbp) into %rax
	addq	%rcx, %rax						# add %rcx to %rax, ie 4*j is added to address of arr1[] to get arr[j] as rax is j
	movl	(%rax), %eax					# set %eax to the value of (%rax), ie load the value of arr1[j] into %eax
	cmpl	%eax, %edx						# compare arr1[i] with arr1[j], // line 9 of .c file having the if condition
	jne	.L4									# if arr1[i] is not equal to arr1[j], jump to label L4
	addl	$1, -4(%rbp)					# increment ctr stored in -4(%rbp) by 1, ie ctr = ctr + 1, line 10 of .c file having ctr++
	movl	-8(%rbp), %eax					# load j stored at -8(%rbp) into %eax
	cltq									# convert long to quad, sign extend %eax to %rax
	leaq	0(,%rax,4), %rdx				# %rdx = 4 * %rax + 0 ie offset for array element used for traversing array
	movq	-40(%rbp), %rax					# load fr1[] stored at -40(%rbp) into %rax
	addq	%rdx, %rax						# add %rdx to %rax, ie 4*j is added to address of fr1[] to get fr1[j] as rax is j
	movl	$0, (%rax)						# store 0 in fr1[j], ie fr1[j] = 0, // line 11 of .c file having fr1[j] = 0
.L4:										# label L4, used to do j++ as in line 8 of .c file
	addl	$1, -8(%rbp)					# add 1 to j stored at -8(%rbp), ie j = j + 1
.L3:										# label L3, used to check if j < n, // line 8 of .c file
	movl	-8(%rbp), %eax					# load j stored at -8(%rbp) into %eax
	cmpl	-28(%rbp), %eax					# compare j (%eax) with n stored at -28(%rbp), // line 8 of .c file
	jl	.L5									# if j is less than n, jump to label L5, else continue
	movl	-12(%rbp), %eax					# load i stored at -12(%rbp) into %eax
	cltq									# convert long to quad, sign extend %eax to %rax
	leaq	0(,%rax,4), %rdx				# %rdx = 4 * %rax + 0 ie offset for array element used for traversing array
	movq	-40(%rbp), %rax					# load fr1[] stored at -40(%rbp) into %rax
	addq	%rdx, %rax						# add %rdx to %rax, ie 4*i is added to address of fr1[] to get fr1[i] as rax is i
	movl	(%rax), %eax					# set %eax to the value of (%rax), ie load the value of fr1[i] into %eax
	testl	%eax, %eax						# test the value of %eax, ie fr1[i], // line 15 of .c file having if(fr1[i] == 0)
	je	.L6									# if fr1[i] is 0, jump to label L6, else continue
	movl	-12(%rbp), %eax					# load i stored at -12(%rbp) into %eax
	cltq									# convert long to quad, sign extend %eax to %rax
	leaq	0(,%rax,4), %rdx				# %rdx = 4 * %rax + 0 ie offset for array element used for traversing array
	movq	-40(%rbp), %rax					# load fr1[] stored at -40(%rbp) into %rax
	addq	%rax, %rdx						# add %rdx to %rax, ie 4*i is added to address of fr1[] to get fr1[i] as rax is i
	movl	-4(%rbp), %eax					# load ctr stored at -4(%rbp) into %eax
	movl	%eax, (%rdx)					# load ctr stored at (%eax) into fr1[i], ie fr1[i] = ctr, // line 16 of .c file having fr1[i] = ctr
.L6:										# label L6, used to do i++ as in line 6 of .c file
	addl	$1, -12(%rbp)					# add 1 to i stored at -12(%rbp), ie i = i + 1, // line 6 of .c file
.L2:										# label L2, used to check if i < n, // line 6 of .c file
	movl	-12(%rbp), %eax					# load i stored at -12(%rbp) into %eax
	cmpl	-28(%rbp), %eax					# compare i stored at (%eax) with n stored at -28(%rbp), // line 6 of .c file
	jl	.L7									# if i is less than n, jump to label L7, else continue
	nop										# no operation, placeholder
	nop										# no operation, placeholder
	popq	%rbp							# restore base pointer %rbp
	.cfi_def_cfa 7, 8						# cfi directive
	ret										# return from function
	.cfi_endproc							# cfi directive
.LFE0:										# label LFE0
	.size	calculateFrequency, .-calculateFrequency	# size of calculateFrequency function
	.section	.rodata						# read only data section of calculateFrequency
.LC0:										# label LC0, used to store string "Element\tFrequency" which is used for printf function in line 22 of .c code
	.string	"Element\tFrequency"			# store value of "Element\tFrequency" in LC0
.LC1:										# label LC1, used to store string "%d\t%d\n" which is used for printf function in line 25 of .c code
	.string	"%d\t%d\n"						# store value of "%d\t%d\n" in LC1
	.text									# code starts here
	.globl	printArrayWithFrequency			# printArrayWithFrequency is a global name
	.type	printArrayWithFrequency, @function			# printArrayWithFrequency is a function
printArrayWithFrequency:					# function printArrayWithFrequency starts
.LFB1:										# function definition label LFB1, // line 21 of .c code
	.cfi_startproc							# cfi directive
	endbr64									# end of branch 64 bit
	pushq	%rbp							# save old base pointer %rbp
	.cfi_def_cfa_offset 16					# cfi directive
	.cfi_offset 6, -16						# cfi directive
	movq	%rsp, %rbp						# set stack pointer %rsp to base pointer %rbp
	.cfi_def_cfa_register 6					# cfi directive
	subq	$48, %rsp						# allocate 48 bytes of memory on stack for local variables
	movq	%rdi, -24(%rbp)					# store first argument (array arr1[]) at -24(%rbp)
	movq	%rsi, -32(%rbp)					# store second argument (array fr1[]) at -32(%rbp)
	movl	%edx, -36(%rbp)					# store third argument (int n) at -36(%rbp)
	leaq	.LC0(%rip), %rdi				# load address of string "Element\tFrequency" stored at LC0 into %rdi
	call	puts@PLT						# call puts function to print "Element\tFrequency" to stdout, // line 22 of .c code
	movl	$0, -4(%rbp)					# initialise i to 0 and store at -4(%rbp), ie i = 0, // line 23 of .c code
	jmp	.L9									# jumps function to label L9
.L11:										# label L11, used to print fr1[i] and arr1[i] using printf function, // line 25 of .c code
	movl	-4(%rbp), %eax					# load i stored at -4(%rbp) into %eax
	cltq									# convert long to quad, sign extend %eax to %rax
	leaq	0(,%rax,4), %rdx				# %rdx = 4 * %rax + 0 ie offset for array element used for traversing array
	movq	-32(%rbp), %rax					# load fr1[] stored at -32(%rbp) into %rax
	addq	%rdx, %rax						# add %rdx to %rax, ie 4*i is added to address of fr1[] to get fr1[i] as rax is i
	movl	(%rax), %eax					# load value of fr1[i] stored at (%rax) into %eax
	testl	%eax, %eax						# test if fr1[i] is 0 or not
	je	.L10								# jump to L10 if fr1[i] is 0 else continue
	movl	-4(%rbp), %eax					# load i stored at -4(%rbp) into %eax
	cltq									# convert long to quad, sign extend %eax to %rax
	leaq	0(,%rax,4), %rdx				# %rdx = 4 * %rax + 0 ie offset for array element used for traversing array
	movq	-32(%rbp), %rax					# load fr1[] stored at -32(%rbp) into %rax
	addq	%rdx, %rax						# add %rdx to %rax, ie 4*i is added to address of fr1[] to get fr1[i] as rax is i
	movl	(%rax), %edx					# load value of fr1[i] stored at (%rax) into %edx
	movl	-4(%rbp), %eax					# load i stored at -4(%rbp) into %eax
	cltq									# convert long to quad, sign extend %eax to %rax
	leaq	0(,%rax,4), %rcx				# %rcx = 4 * %rax + 0 ie offset for array element used for traversing array
	movq	-24(%rbp), %rax					# load arr1[] stored at -24(%rbp) into %rax
	addq	%rcx, %rax						# add %rcx to %rax, ie 4*i is added to address of arr1[] to get arr1[i] as rax is i
	movl	(%rax), %eax					# load value of arr1[i] stored at (%rax) into %eax
	movl	%eax, %esi						# move value of %eax to %esi
	leaq	.LC1(%rip), %rdi				# load address of string "%d\t%d\n" stored at LC1 into %rdi
	movl	$0, %eax						# store 0 in %eax
	call	printf@PLT						# call printf function to print "%d\t%d\n" to stdout, // line 25 of .c code
.L10:										# label L10, used to increment i by 1, // line 23 of .c code
	addl	$1, -4(%rbp)					# increment i stored at -4(%rbp) by 1, ie i++
.L9:										# label L9, used to check if i < n, // line 23 of .c code
	movl	-4(%rbp), %eax					# load i stored at -4(%rbp) into %eax
	cmpl	-36(%rbp), %eax					# compare i at (%eax) with n stored at -36(%rbp)
	jl	.L11								# jump to L11 if i < n else continue
	nop										# no operation, placeholder
	nop										# no operation, placeholder
	leave									# restore stack pointer to base pointer
	.cfi_def_cfa 7, 8						# cfi directive
	ret										# return from function
	.cfi_endproc							# cfi directive
.LFE1:										# label LFE1
	.size	printArrayWithFrequency, .-printArrayWithFrequency	# size of function printArrayWithFrequency
	.section	.rodata						# read only data section
	.align 8								# align with 8 bytes
.LC2:										# label LC2, used to store string "\n\nCount frequency of each integer element of an array:", // line 34 of .c code
	.string	"\n\nCount frequency of each integer element of an array:"	# string "\n\nCount frequency of each integer element of an array:"
	.align 8								# align with 8 bytes
.LC3:										# label LC3, used to store string "------------------------------------------------", // line 35 of .c code
	.string	"------------------------------------------------"			# string "------------------------------------------------"
	.align 8								# align with 8 bytes
.LC4:										# label LC4, used to store string "Input the number of elements to be stored in the array :", // line 36 of .c code
	.string	"Input the number of elements to be stored in the array :"	# string "Input the number of elements to be stored in the array :"
.LC5:										# label LC5, used for scanf for the number of elements to be stored in the array, // line 38 of .c code
	.string	"%d"							# string "%d" for scanf function
	.align 8								# align with 8 bytes
.LC6:										# label LC6, used to store string "Enter each elements separated by space: ", // line 39 of .c code
	.string	"Enter each elements separated by space: "					# string "Enter each elements separated by space: "
	.text									# code starts here
	.globl	main							# main is a global name
	.type	main, @function					# main is a function
main:										# function main starts
.LFB2:										# label LFB2
	.cfi_startproc							# cfi directive
	endbr64									# end of branch 64
	pushq	%rbp							# save old base pointer %rbp	
	.cfi_def_cfa_offset 16					# cfi directive
	.cfi_offset 6, -16						# cfi directive
	movq	%rsp, %rbp						# set new stack pointer %rsp to base pointer %rbp
	.cfi_def_cfa_register 6					# cfi directive
	subq	$832, %rsp						# allocate 832 bytes of memory on stack, to make space for local variables and arrays
	movq	%fs:40, %rax					# load address into %rax for stack overflow handling
	movq	%rax, -8(%rbp)					# load address stored in %rax into -8(%rbp)
	xorl	%eax, %eax						# xor %eax with itself, ie store 0 in %eax
	leaq	.LC2(%rip), %rdi				# load address of string "\n\nCount frequency of each integer element of an array:" stored at LC2 into %rdi
	call	puts@PLT						# call puts function to print "\n\nCount frequency of each integer element of an array:" to stdout, // line 34 of .c code
	leaq	.LC3(%rip), %rdi				# load address of string "------------------------------------------------" stored at LC3 into %rdi
	call	puts@PLT						# call puts function to print "------------------------------------------------" to stdout, // line 35 of .c code
	leaq	.LC4(%rip), %rdi				# load address of string "Input the number of elements to be stored in the array :" stored at LC4 into %rdi
	movl	$0, %eax						# set %eax to 0
	call	printf@PLT						# call printf function to print "Input the number of elements to be stored in the array :" to stdout, // line 36 of .c code
	leaq	-828(%rbp), %rax				# make space for the string "%d" for scanf function at -828(%rbp)
	movq	%rax, %rsi						# move address stored in %rax to %rsi
	leaq	.LC5(%rip), %rdi				# load address of string "%d" stored at LC5 into %rdi
	movl	$0, %eax						# set %eax to 0
	call	__isoc99_scanf@PLT				# call scanf function to read input from stdin, // line 38 of .c code
	leaq	.LC6(%rip), %rdi				# load address of string "Enter each elements separated by space: " stored at LC6 into %rdi
	movl	$0, %eax						# set %eax to 0
	call	printf@PLT						# call printf function to print "Enter each elements separated by space: " to stdout, // line 39 of .c code
	movl	$0, -824(%rbp)					# set -824(%rbp) to 0, ie set i to 0, // line 40 of .c code
	jmp	.L13								# jump to label L13
.L14:										# label L14, used for for loop
	leaq	-816(%rbp), %rax				# load address of array arr1 stored at -816(%rbp) into %rax
	movl	-824(%rbp), %edx				# load i stored at -824(%rbp) into %edx
	movslq	%edx, %rdx						# expanding i stored in 32 bits %edx to 64 bits %rdx
	salq	$2, %rdx						# left shift operation done for %rdx hence getting 4*%rdx ie getting 4*i
	addq	%rdx, %rax						# add %rdx to %rax, ie add 4*i to %rax, ie get address of arr1[i]
	movq	%rax, %rsi						# move address stored in %rax to %rsi
	leaq	.LC5(%rip), %rdi				# load address of string "%d" stored at LC5 into %rdi
	movl	$0, %eax						# set %eax to 0
	call	__isoc99_scanf@PLT				# call scanf function to read input from stdin, // line 42 of .c code
	addl	$1, -824(%rbp)					# increment i stored at -824(%rbp) by 1, ie i++, // line 40 of .c code
.L13:										# label L13, used for for loop condition
	movl	-828(%rbp), %eax				# load n stored at -828(%rbp) into %eax
	cmpl	%eax, -824(%rbp)				# compare n stored at %eax with i stored at -824(%rbp)
	jl	.L14								# if i is less than n, jump to label L14
	movl	$0, -820(%rbp)					# set i (inside for loop condition scope) to 0 and storing it at -820(%rbp), // line 45 of .c code
	jmp	.L15								# jump to label L15
.L16:										# label L16, used for second for loop
	movl	-820(%rbp), %eax				# load i stored at -820(%rbp) into %eax
	cltq									# convert 32 bits %eax to 64 bits %rax
	movl	$-1, -416(%rbp,%rax,4)			# store -1 at -416(%rbp,%rax,4), ie store -1 at fr1[i], // line 46 of .c code
	addl	$1, -820(%rbp)					# increment i stored at -820(%rbp) by 1, ie i++, // line 45 of .c code
.L15:										# label L15
	movl	-828(%rbp), %eax				# load n stored at -828(%rbp) into %eax
	cmpl	%eax, -820(%rbp)				# compare n stored at %eax with i stored at -820(%rbp)
	jl	.L16								# if i is less than n, jump to label L16
	movl	-828(%rbp), %ecx				# load n stored at -828(%rbp) into %ecx
	leaq	-416(%rbp), %rdx				# load address of array fr1 stored at -416(%rbp) into %rdx
	leaq	-816(%rbp), %rax				# load address of array arr1 stored at -816(%rbp) into %rax
	movl	%ecx, %esi						# load value of n at %ecx into %esi
	movq	%rax, %rdi						# move address of arr1 stored in %rax to %rdi
	call	calculateFrequency				# call calculateFrequency function, // line 50 of .c code
	movl	-828(%rbp), %edx				# load n stored at -828(%rbp) into %edx
	leaq	-416(%rbp), %rcx				# load address of array fr1 stored at -416(%rbp) into %rcx 
	leaq	-816(%rbp), %rax				# load address of array arr1 stored at -816(%rbp) into %rax
	movq	%rcx, %rsi						# load address of array fr1 stored at (%rcx) into %rsi
	movq	%rax, %rdi						# load address of array arr1 stored at (%rax) into %rdi
	call	printArrayWithFrequency			# call printArrayWithFrequency function, // line 52 of .c code
	movl	$0, %eax						# set %eax to 0
	movq	-8(%rbp), %rcx					# load value of -8(%rbp) into %rcx
	xorq	%fs:40, %rcx					# xor of %fs:40 and %rcx and storing it in %rcx
	je	.L18								# if %rcx is equal to 0, jump to label L18
	call	__stack_chk_fail@PLT			# call __stack_chk_fail function if %rcx is not equal to 0, denoting error
.L18:										# label L18
	leave									# restore stack pointer to base pointer
	.cfi_def_cfa 7, 8						# cfi directive
	ret										# return from main function
	.cfi_endproc							# cfi directive
.LFE2:										# label LFE2 for software information
	.size	main, .-main					# size of main function
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0" # compiler information
	.section	.note.GNU-stack,"",@progbits	# section for GNU stack
	.section	.note.gnu.property,"a"			# section for GNU property
	.align 8								# align with 8 bytes
	.long	 1f - 0f						# difference between 1f and 0f labels
	.long	 4f - 1f						# difference between 4f and 1f labels
	.long	 5								# constant 5
0:											# label 0
	.string	 "GNU"							# string GNU
1:											# label 1
	.align 8								# align with 8 bytes
	.long	 0xc0000002						# constant 0xc0000002
	.long	 3f - 2f						# difference between 3f and 2f labels
2:											# label 2
	.long	 0x3							# constant 0x3
3:											# label 3
	.align 8								# align with 8 bytes
4:											# label 4, empty
