;Prototype
;size_t ft_strlen(const char *s);

section .text
	global _ft_strlen

_ft_strlen:
	mov	rax, 0 ; 리턴할 rax 값 0으로 초기화
	jmp	count ; count로 이동

count:
	cmp	BYTE [rdi + rax], 0 ; 1바이트씩 읽고, 0(NULL) 과 비교
	je	done ; 만약 NULL 이라면? done 으로 이동
	inc	rax ; rax++
	jmp	count ; count로 이동

done:
	ret ; rax 값 리턴
