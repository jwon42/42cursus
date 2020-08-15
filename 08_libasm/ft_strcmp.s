# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwon <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/15 12:48:31 by jwon              #+#    #+#              #
#    Updated: 2020/08/15 12:48:54 by jwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
global _ft_strcmp

_ft_strcmp:
	mov rax, 0
	mov rbx, 0
	mov rcx, 0
	jmp compare

compare:
	mov al, byte [rdi + rcx]
	mov bl, byte [rsi + rcx]
	cmp al, bl
	jne different
	je	same

different:
	sub rax, rbx
	ret

same:
	cmp al, 0
	je 	exit
	inc rcx
	jmp compare

exit:
	mov rax, 0
	ret