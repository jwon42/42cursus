# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwon <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/21 14:50:40 by jwon              #+#    #+#              #
#    Updated: 2020/08/21 14:50:51 by jwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
global _ft_read
	extern ___error

_ft_read:
	mov rax, 0x2000003
	syscall
	jc _err
	ret

_err:
	push rax
	call ___error
	pop rdx
	mov [rax], rdx
	mov rax, -1
	ret