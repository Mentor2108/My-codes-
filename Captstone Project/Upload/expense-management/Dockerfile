FROM docker.repository.esi.adp.com/clientcentral/java:17.0.1-jdk

ARG JAR_FILE=target/expense-management.jar
ADD ${JAR_FILE} expense-management.jar
ENTRYPOINT ["java","-jar","/expense-management.jar"]
#EXPOSE 6969