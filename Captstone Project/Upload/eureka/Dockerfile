FROM docker.repository.esi.adp.com/clientcentral/java:17.0.1-jdk

ARG JAR_FILE=target/eureka.jar
ADD ${JAR_FILE} eureka.jar
ENTRYPOINT ["java","-jar","/eureka.jar"]
#EXPOSE 8761