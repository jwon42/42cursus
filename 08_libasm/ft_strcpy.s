;Prototype
;char *ft_strcpy(const char *dst, const char *src);

section .text
	global _ft_strcpy

_ft_strcpy:
	mov	rcx, 0 ; rcx 값 0으로 초기화
	mov	rbx, 0 ; rbx 값 0으로 초기화
	cmp	rsi, 0 ; rsi와 0(NULL) 비교
	je	exit ; 같으면 exit으로 이동

copy:
	mov	bl, byte [rsi + rcx] ; bl을 문자열 *src의 rcx번째 문자로 초기화
	mov	byte [rdi + rcx], bl ; 문자열 *dst의 rcx번째 문자를 bl로 초기화
	inc	rcx ; rcx++
	cmp	bl, 0 ; bl과 0(NULL) 비교
	je	exit ; 같으면 exit으로 이동
	jmp	copy ; copy로 이동

exit:
	mov	rax, rdi ; rax에 rdi 값 복사
	ret ; rax 값 리턴