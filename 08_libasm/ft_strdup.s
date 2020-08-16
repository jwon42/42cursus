# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwon <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/16 23:30:18 by jwon              #+#    #+#              #
#    Updated: 2020/08/16 23:31:13 by jwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
	push rdi
	call _ft_strlen
	mov rdi, rax
	call _malloc
	cmp rax, 0
	je exit
	pop rsi
	mov rdi, rax
	sub rsp, 8
	call _ft_strcpy
	add rsp, 8
	jmp exit

exit:
	ret