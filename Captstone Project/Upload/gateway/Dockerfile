FROM docker.repository.esi.adp.com/clientcentral/java:17.0.1-jdk

ARG JAR_FILE=target/gateway.jar
ADD ${JAR_FILE} gateway.jar
ENTRYPOINT ["java","-jar","/gateway.jar"]
#EXPOSE 6769