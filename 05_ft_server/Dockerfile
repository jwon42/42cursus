# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwon <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/04 18:34:59 by jwon              #+#    #+#              #
#    Updated: 2020/05/04 18:34:59 by jwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

# UPDATE PACKAGE & INSTALL SERVICES
RUN apt-get update;\
	apt-get install -y wget nginx php-fpm php-mysql php-mysqlnd php-mbstring mariadb-server mariadb-client vim

# COPY INDEX FILE
COPY ./srcs/index.htm ./var/www/html/index.htm

# COPY INDEX LOGO
COPY ./srcs/42logo.png ./var/www/html/42logo.png

# COPY NGINX CONFIG
COPY ./srcs/default ./etc/nginx/sites-available/default

# ISSUE SSL Certificate
RUN openssl req -x509 -nodes -days 3650 -newkey rsa:2048 -subj "/C=KR/ST=Seoul/L=Gangnam/O=42/OU=Student/CN=Jwon" -keyout /etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.crt

# SET WORKING DIR
WORKDIR /var/www/html/

# INSTALL PHPMYADMIN & COPY CONFIG
RUN mkdir phpmyadmin;\
	wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.tar.gz;\
	tar -xvf phpMyAdmin-4.9.5-all-languages.tar.gz --strip-components=1 -C ./phpmyadmin;\
	rm -rf phpMyAdmin-4.9.5-all-languages.tar.gz
COPY ./srcs/config.inc.php ./phpmyadmin

# INSTALL WORDPRESS & COPY CONFIG
RUN wget https://wordpress.org/latest.tar.gz;\
	tar -xvf latest.tar.gz;\
	rm -rf latest.tar.gz
COPY ./srcs/wp-config.php ./wordpress

# SET PERMISSION
RUN chown -R www-data:www-data *;\
	chmod -R 755 *

# START SERVICES & CREATE USER & CREATE DB
CMD	service mysql start;\
	service php7.3-fpm start;\
	echo "CREATE USER 'admin'@'%' identified by '';" | mysql -u root --skip-password;\
	echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password;\
	echo "GRANT ALL PRIVILEGES ON *.* TO 'admin'@'%';" | mysql -u root --skip-password ;\
	echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password;\
	service nginx start;\
	sleep inf