;Prototype
;ssize_t ft_write(int fd, void *buff, size_t nbyte);

section .text
	global _ft_write
	extern ___error

_ft_write:
	mov		rax, 0x2000004 ; OSX 이기 때문에 upper bits 를 2로 설정, 4는 write 시스템콜 넘버
	syscall ; 시스템콜
	jc		_err ; 에러가 있다면 carry flag on
	ret ; rax 값 리턴

_err:
	push	rax; 스택에 rax 값(에러 주소) 저장
	call	___error ; ___error 호출
	pop		rdx ; 스택에 있는 값을 rdx에 저장
	mov		[rax], rdx ; rax 주소는 변경하지 않고 값을 rdx의 값으로 복사
	mov		rax, -1 ; rax 에 -1 저장
	ret ; rax 값 리턴