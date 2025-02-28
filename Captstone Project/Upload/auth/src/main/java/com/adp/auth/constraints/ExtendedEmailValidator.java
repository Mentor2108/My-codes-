package com.adp.auth.constraints;

import jakarta.validation.Constraint;
import jakarta.validation.Payload;
import jakarta.validation.constraints.Email;
import jakarta.validation.constraints.Pattern;

import java.lang.annotation.Documented;
import java.lang.annotation.Retention;
import java.lang.annotation.Target;

import static java.lang.annotation.ElementType.*;
import static java.lang.annotation.RetentionPolicy.RUNTIME;

@Email(message=ValidationFailedMessage.EMAIL)
@Pattern(regexp=".+@.+\\..+", message=ValidationFailedMessage.EMAIL)
@Target( { METHOD, FIELD, ANNOTATION_TYPE })
@Retention(RUNTIME)
@Constraint(validatedBy = {})
@Documented
public @interface ExtendedEmailValidator {
    String message() default ValidationFailedMessage.EMAIL;
    Class<?>[] groups() default {};
    Class<? extends Payload>[] payload() default {};
}