;Prototype
;char *ft_strdup(const char *s1);

section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
	push	rdi ; 스택에 rdi 저장
	call	_ft_strlen ; ft_strlen 호출
	mov		rdi, rax ; rdi에 ft_strlen 반환 값 저장
	call	_malloc ; malloc 호출
	cmp		rax, 0 ; malloc으로 할당된 공간과 0(NULL) 비교
	je		exit ; 같다면 exit로 이동
	pop		rsi ; 스택에 저장했던 값을 뽑아와서 rsi에 저장
	mov		rdi, rax ; rdi에 malloc 반환 값 복사
	sub		rsp, 8 ; 8바이트 만큼 빼서 조정
	call	_ft_strcpy ; ft_strcpy 호출
	add		rsp, 8 ; 8바이트 만큼 더해서 조정
	jmp		exit ; exit로 이동

exit:
	ret ; rax 값 리턴