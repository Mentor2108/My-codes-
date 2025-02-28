import { IAddress, IPerson } from "../types"

const validateProfileInput = (field: keyof IPerson, value: string): string => {
    const todaysDate = new Date().getDate().toString()

    switch (field) {
        case "email": {
            var regexp = /^[^\s@]+@[^\s@]+\.[^\s@]+$/
            if (!regexp.test(value)) {
                return "Please enter valid mail"
            } else {
                return (value.trim() === "") ? "Email Required." : null
            }
        }break;
        case "password": {
            var pregx = /^(?=.*[0-9])(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{6,16}$/
            if(value.length< 6 && value.length>0){
                return "Password must be atleast 6 characters"
            }
            if(!pregx.test(value)){
                return "Password must contain atleast a number and a special character."
            }
            return (value.trim() === "") ? "Password Required." : null
        }break;
        case "firstname": {
            return (value === null || value === "") ? "FirstName Required." : null
        }break;
        
        case "dateofbirth":{
            return (value === todaysDate || value === null)? "Date should not be today!": null
        }
    }
}


const validateEditProfileInput = (field: keyof IPerson, value: string): string => {
    const todaysDate = new Date().getDate().toString()

    switch (field) {
        case "email": {
            var regexp = /^[^\s@]+@[^\s@]+\.[^\s@]+$/
            if (!regexp.test(value)) {
                return "Please enter valid mail"
            } else {
                return (value.trim() === "") ? "Email Required." : null
            }
        }break;
        case "firstname": {
            return (value === null || value === "") ? "FirstName Required." : null
        }break;
        
        case "dateofbirth":{
            return (value === todaysDate)? "Date should not be today!": null
        }
    }
}



const validateAddressInput = (field: keyof IAddress, value: string): string => {
    const todaysDate = new Date().getDate().toString()

    switch (field) {
        case "country": {
                return (value === null || value === "") ? "Country Required." : null
        }break;

        case "line_one":{
            return (value === null || value === "")? "Address One is Required!": null
        }break;
        case "postal_code":{
            return (value === null || value === "")? "Postal Code  is Required!": null
        }
    }
}


const validateRegisterAddressInput = (field: keyof IAddress, value: string): string => {
    const todaysDate = new Date().getDate().toString()

    switch (field) {
        case "country": {
                return (value === null || value === "") ? "Country Required!." : null
        }break;
        case "state":{
            return (value === null || value === "")? "State is Required!": null
        }break;
        case "postal_code":{
            return (value === null || value === "")? "Postal-Code is Required!": null
        }break;
        case "city":{
            return (value === null || value === "")? "City is Required!": null
        }break;
        case "line_one":{
            return (value === null || value === "")? "Address One is Required!": null
        }
    }
}

export {validateProfileInput,validateAddressInput,validateEditProfileInput,validateRegisterAddressInput};