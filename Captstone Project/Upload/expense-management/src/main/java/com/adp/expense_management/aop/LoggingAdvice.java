package com.adp.expense_management.aop;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;
import org.springframework.util.StopWatch;

@Aspect
@Component
public class LoggingAdvice {
    Logger log = LoggerFactory.getLogger(LoggingAdvice.class);

    @Before("execution( public * com.adp.expense_management.controller.EmployeeController.get*(..))")
    public void beforeGetNoteController() {
        System.out.println(" Executed before get**() of  EmployeeController class");
        log.info("Before advice called.");
    }

    @After("execution( public * com.adp.expense_management.controller.EmployeeController.addEmployee(..))")
    public void afterAddNote() {
        System.out.println(" Executed after executing addEmployee() method of EmployeeController class");
        log.info("After advice called.");
    }

//    @After("execution( public * com.adp.expense_management.controller.LoginSignupController.*)")
//    public void LoginSignupController()  {
//        System.out.println(" Executed after executing addEmployee() method of EmployeeController class");
//        log.info("After advice called.");
//    }
//

    @Pointcut(value = "execution(public * com.adp.expense_management..*(..))")
    public void myPointcut() {

    }

    @Around("myPointcut()")
    public Object applicationLogger(ProceedingJoinPoint pjp) throws Throwable {
        String methodName = pjp.getSignature().getName();
        String className = pjp.getTarget().getClass().toString();
        final StopWatch stopWatch = new StopWatch();
        stopWatch.start();
        log.debug("METHOD INVOKED " + className + ":: " + methodName + "()");

        Object object = pjp.proceed();

        log.debug("AFTER SUCCESSFULL EXECUTION OF " + className + ":: " + methodName + "() "
                + stopWatch.getTotalTimeMillis() + " ms");

        return object;
    }
}
