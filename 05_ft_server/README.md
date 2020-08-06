## :notebook_with_decorative_cover: ft_server

#### :page_facing_up:  Mandatory part

- You must set up a web server with **Nginx**, in **only one docker container**. The **container OS must be [debian buster](https://github.com/jwon42/42cursus/blob/master/05_ft_server/Dockerfile#L13)**.

- Your web server must be able to run several services at the same time. The services will be a **[WordPress](https://github.com/jwon42/42cursus/blob/master/05_ft_server/Dockerfile#L41) website**, **[phpMyAdmin](https://github.com/jwon42/42cursus/blob/master/05_ft_server/Dockerfile#L34)** and **MySQL**. You will need to make sure your SQL database works with the WordPress and phpMyAdmin.
- Your server **should be able to use the [SSL protocol](https://github.com/jwon42/42cursus/blob/master/05_ft_server/Dockerfile#L28)**.
- You will have to make sure that, depending on the url, your server redirects to the correct website.
- You will also need to make sure your **server is running with an autoindex that must be able to be disabled**.

------

#### :page_facing_up:  Commands

- Build image

  ```
  docker build -t IMAGE_NAME .
  ```

- Run container

  ```
  docker run --name CONTAINER_NAME -p 80:80 -p 443:443 -itd IMAGE_NAME
  ```

- Execute running container

  ```
  docker exec -it CONTAINER_NAME /bin/bash
  ```

