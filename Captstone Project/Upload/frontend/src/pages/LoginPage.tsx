import { SdfCard, SdfButton, SdfInput, SdfIcon } from "@waypoint/react-components";
import { Row, Col } from "../layouts/RowColumnLayout.tsx";
import { Logo } from "../components/Logo.tsx";
import { Spacing } from "../components/Spacing.tsx";
import Illustration from "../components/Illustration.tsx";
import { useReducer, useState } from "react";
import InlineError from "../components/InlineError.tsx";
import axios, { AxiosError, AxiosResponse } from "axios";
import { useNavigate } from "react-router-dom";
import { useUser } from "../components/UserState.tsx";
import { User } from "../types.ts";
import { Register } from "../components/Register/Register.tsx";
import { LoginState, LoginAction, LoginErrorState } from "../types.ts";
import ErrorBanner from "../components/ErrorBanner.tsx";

const initialState: LoginState = {
    email: "",
    password: ""
}
const initialErrors: LoginErrorState = {
    email: null,
    password: null
}

const reducer: React.Reducer<{ inputs: LoginState, errors: LoginErrorState }, LoginAction> = (state, action) => {
    switch (action.type) {
        case 'SET_INPUT': {
            return { ...state, inputs: { ...state.inputs, [action.field]: action.value } }
        }
        case 'SET_ERROR': {
            return { ...state, errors: { ...state.errors, [action.field]: action.value } }
        }
        case 'RESET': return { inputs: initialState, errors: initialErrors }
    }
}

export default function LoginPage() {
    const navigate = useNavigate()

    console.log("my variable test: ", process.env.REACT_APP_TEST);
    console.log("my variable testing: ", process.env.REACT_APP_TESTING);
    console.log("my variable testing2: ", process.env.REACT_APP_TESTING2);
    console.log("my variable testing3: ", process.env.REACT_APP_TESTING3);
    const [state, dispatch] = useReducer<React.Reducer<{ inputs: LoginState, errors: LoginErrorState }, LoginAction>>(reducer, {
        inputs: initialState,
        errors: initialErrors
    })
    const { updateCurrentUser } = useUser();
    const [loginResponse, setLoginResponse] = useState<string | null>(null);

    const validateInput = (field: keyof LoginState, value: string): string => {
        switch (field) {
            case "email": {
                var regexp = /^[^\s@]+@[^\s@]+\.[^\s@]+$/
                if (!regexp.test(value)) {
                    return "Please enter valid mail"
                } else {
                    return (value.trim() === "") ? "Email Required." : null
                }
            }
            case "password": {
                return (value.trim() === "") ? "Password Required." : null
            }
        }
    }

    function handleChange(event) {
        const { name, value } = event.target;
        const field = name as keyof LoginState;
        dispatch({ type: 'SET_INPUT', field: field, value: value })
        const error = validateInput(field, value)
        dispatch({ type: 'SET_ERROR', field: field, value: error })
    }

    function pressEnterEvent(evt: KeyboardEvent) {
        if (evt.key === "Enter") {
            handleLogin();
        }
    }

    async function handleLogin() {
        let hasError = false;
        (Object.keys(state.inputs) as (keyof LoginState)[]).forEach((field) => {
            const error = validateInput(field, state.inputs[field]);
            if (error) {
                hasError = true;
                dispatch({ type: 'SET_ERROR', field: field, value: error })
            }
        })
        if (!hasError) {
            await axios.post('http://localhost:6769/auth/login', {
                email: state.inputs['email'],
                password: state.inputs['password']
            }, {
                withCredentials: true
            }).then((response: AxiosResponse) => {
                if (response.status && response.status === 200) {
                    axios.get('http://localhost:6769/api/employee/profile', {
                        withCredentials: true
                    }).then((profileResponse: AxiosResponse<User>) => {
                        if (profileResponse.status && profileResponse.status === 200) {
                            updateCurrentUser(profileResponse.data)
                        } else {
                            setLoginResponse("Something went wrong. Please try again.");
                        }
                    }).catch((error: AxiosError) => {
                        setLoginResponse("Something went wrong. Please try again.");
                    });
                    navigate('/home');
                } else {
                    setLoginResponse("Something went wrong. Please try again.");
                }
            }).catch((error: AxiosError) => {
                if (error.status && error.status === 403) {
                    setLoginResponse("Invalid Login Credentials. Please enter correct details.");
                } else {
                    setLoginResponse("Something went wrong. Please try again.");
                }
            });
        }
    }
    return (
        <Row position="center">
            <Row columns={2} position="center" height="screen">
                <div>
                    <Illustration transformation="transform -translate-x-1/2 -translate-y-full" name="checkmark" />
                    <Illustration transformation="transform -translate-x-1/2 translate-y-full" name="wallet" />
                </div>

                <div>
                    {
                        loginResponse && <ErrorBanner message={loginResponse} setMessage={setLoginResponse}/>
                    }
                    <SdfCard spacing="loose" className="p-4 mr-1">
                        <Row position="center" padding={3}>
                            <Col>
                                <Row position="center">
                                    <Logo size="md" />
                                </Row>
                                <Col>
                                    <h1>Welcome Back</h1>
                                </Col>
                                <Row>
                                    <SdfInput
                                        label="Email"
                                        name="email"
                                        id="demo-component"
                                        inputType="text"
                                        required-state="required"
                                        className="w-full"
                                        onSdfInput={handleChange}
                                    >
                                        <SdfIcon aria-hidden slot="before" icon="pto-personal"></SdfIcon>
                                    </SdfInput>
                                </Row>
                                {
                                    state.errors.email && <InlineError message={state.errors.email} />
                                }
                                <Spacing />
                                <Row>
                                    <SdfInput
                                        label="Password"
                                        name="password"
                                        id="demo-component"
                                        type="password"
                                        required-state="required"
                                        className="w-full"
                                        onSdfInput={handleChange}
                                        onKeyDown={(event: KeyboardEvent) => pressEnterEvent(event)}
                                    >
                                        <SdfIcon aria-hidden slot="before" icon="status-locked"></SdfIcon>
                                    </SdfInput>
                                </Row>
                                {
                                    state.errors.password && <InlineError message={state.errors.password} />
                                }
                                <Spacing />
                                <Row position="center">
                                    <SdfButton
                                        emphasis="primary"
                                        variant="contained"
                                        size="lg"
                                        layout="stack"
                                        className="w-full"
                                        onClick={handleLogin}>
                                        Login
                                    </SdfButton>
                                </Row>
                                <Spacing />
                                <Spacing />
                                <Row>
                                    <Register />
                                </Row>
                            </Col>
                        </Row>
                    </SdfCard>
                </div>

                <div>
                    <Illustration transformation="transform translate-x-1/2 -translate-y-full" name="credit-card" />
                    <Illustration transformation="transform translate-x-1/2 translate-y-full" name="calculator" />
                </div>
            </Row>
        </Row>
    );
} 