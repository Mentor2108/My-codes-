FROM docker.repository.esi.adp.com/clientcentral/java:17.0.1-jdk

ARG JAR_FILE=target/auth.jar
ADD ${JAR_FILE} auth.jar
ENTRYPOINT ["java","-jar","/auth.jar"]
#EXPOSE 6869