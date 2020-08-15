# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwon <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/15 12:44:23 by jwon              #+#    #+#              #
#    Updated: 2020/08/15 12:47:26 by jwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
global _ft_strcpy

_ft_strcpy:
	mov	rcx, 0
	mov rbx, 0
	cmp rsi, 0
	je	exit

copy:
	mov bl, byte [rsi + rcx]
	mov byte [rdi + rcx], bl
	inc rcx
	cmp bl, 0
	je	exit
	jmp copy

exit:
	mov rax, rdi
	ret