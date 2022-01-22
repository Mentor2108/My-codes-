employee_data <- data.frame( 
  First_Name = c("Gauransh","Vinay","Nimisha","Ishita","Riddhi","Rani","Vivek","Sapna","Pranay","Anil"),
  Sex = factor(c("M","M","F","F","F","F","M","F","M","M")),
  Age = c(40,45,20,11,32,30,30,24,23,22),
  Number_of_Projects_Completed = c(4, 5, 1, 4, 2, 5, 10, 9, 5, 1),
  Salary = c(5L,9L,8L,4L,9L,8L,8L,4L,7L,6L),
  stringsAsFactors=FALSE
) #Makes dataframe
write.csv(employee_data,"Question_4.csv", row.names = FALSE) #Write in csv file
print(employee_data) 
mod_employee_data <- employee_data[which(employee_data$Sex=="F" & employee_data$Salary>8L),]
print(mod_employee_data)
