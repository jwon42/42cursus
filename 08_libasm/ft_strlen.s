# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwon <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/15 12:30:38 by jwon              #+#    #+#              #
#    Updated: 2020/08/15 12:32:12 by jwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
global _ft_strlen

_ft_strlen:
	mov rax, 0
	jmp count

count:
	cmp BYTE [rdi + rax], 0 
	je	done
	inc rax
	jmp count

done:
	ret
