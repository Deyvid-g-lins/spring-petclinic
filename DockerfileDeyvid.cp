FROM deyvidglins/petclinic
RUN docker container run --name petclinic_01 -d --restart=always -p 8080:8080 -p 50000:50000 -u 0 deyvidglins/petclinic
RUN docker run -e MYSQL_USER=petclinic -e MYSQL_PASSWORD=petclinic -e MYSQL_ROOT_PASSWORD=root -e MYSQL_DATABASE=petclinic -p 3306:3306 mysql:5.7.8
RUN dokcer exec -it petclinic_01 bash
RUN docker login && /  docker push docker push deyvidglins/petclinic
