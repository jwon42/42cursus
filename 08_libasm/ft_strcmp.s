;Prototype
;int ft_strcmp(const char *s1, const char *s2);

section .text
	global _ft_strcmp

_ft_strcmp:
	mov	rax, 0 ; rax 값 0으로 초기화
	mov	rbx, 0 ; rbx 값 0으로 초기화
	mov	rcx, 0 ; rcx 값 0으로 초기화
	jmp	compare ; compare로 이동

compare:
	mov	al, byte [rdi + rcx] ; al을 문자열 *s1의 rcx번째 문자로 초기화
	mov	bl, byte [rsi + rcx] ; bl을 문자열 *s2의 rcx번째 문자로 초기화
	cmp	al, bl ; al, bl 값 비교
	jne	different ; 다르면 different로 이동
	je	same ; 같으면 same으로 이동

different:
	sub	rax, rbx ; rax에서 rbx 빼기
	ret ; rax 값 리턴

same:
	cmp	al, 0 ; al과 0(NULL) 비교
	je	exit ; 같으면 exit로 이동
	inc	rcx ; rcx++
	jmp	compare ; compare로 이동

exit:
	mov	rax, 0 ; rax를 0으로 초기화
	ret ; rax 값 리턴